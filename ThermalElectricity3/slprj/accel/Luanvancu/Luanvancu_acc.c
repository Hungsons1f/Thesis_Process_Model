#include "__cf_Luanvancu.h"
#include <math.h>
#include "Luanvancu_acc.h"
#include "Luanvancu_acc_private.h"
#include <stdio.h>
#include "slexec_vm_simstruct_bridge.h"
#include "slexec_vm_zc_functions.h"
#include "slexec_vm_lookup_functions.h"
#include "slsv_diagnostic_codegen_c_api.h"
#include "simstruc.h"
#include "fixedpoint.h"
#define CodeFormat S-Function
#define AccDefine1 Accelerator_S-Function
#include "simtarget/slAccSfcnBridge.h"
#ifndef __RTW_UTFREE__  
extern void * utMalloc ( size_t ) ; extern void utFree ( void * ) ;
#endif
boolean_T Luanvancu_acc_rt_TDelayUpdateTailOrGrowBuf ( int_T * bufSzPtr ,
int_T * tailPtr , int_T * headPtr , int_T * lastPtr , real_T tMinusDelay ,
real_T * * tBufPtr , real_T * * uBufPtr , real_T * * xBufPtr , boolean_T
isfixedbuf , boolean_T istransportdelay , int_T * maxNewBufSzPtr ) { int_T
testIdx ; int_T tail = * tailPtr ; int_T bufSz = * bufSzPtr ; real_T * tBuf =
* tBufPtr ; real_T * xBuf = ( NULL ) ; int_T numBuffer = 2 ; if (
istransportdelay ) { numBuffer = 3 ; xBuf = * xBufPtr ; } testIdx = ( tail <
( bufSz - 1 ) ) ? ( tail + 1 ) : 0 ; if ( ( tMinusDelay <= tBuf [ testIdx ] )
&& ! isfixedbuf ) { int_T j ; real_T * tempT ; real_T * tempU ; real_T *
tempX = ( NULL ) ; real_T * uBuf = * uBufPtr ; int_T newBufSz = bufSz + 1024
; if ( newBufSz > * maxNewBufSzPtr ) { * maxNewBufSzPtr = newBufSz ; } tempU
= ( real_T * ) utMalloc ( numBuffer * newBufSz * sizeof ( real_T ) ) ; if (
tempU == ( NULL ) ) { return ( false ) ; } tempT = tempU + newBufSz ; if (
istransportdelay ) tempX = tempT + newBufSz ; for ( j = tail ; j < bufSz ; j
++ ) { tempT [ j - tail ] = tBuf [ j ] ; tempU [ j - tail ] = uBuf [ j ] ; if
( istransportdelay ) tempX [ j - tail ] = xBuf [ j ] ; } for ( j = 0 ; j <
tail ; j ++ ) { tempT [ j + bufSz - tail ] = tBuf [ j ] ; tempU [ j + bufSz -
tail ] = uBuf [ j ] ; if ( istransportdelay ) tempX [ j + bufSz - tail ] =
xBuf [ j ] ; } if ( * lastPtr > tail ) { * lastPtr -= tail ; } else { *
lastPtr += ( bufSz - tail ) ; } * tailPtr = 0 ; * headPtr = bufSz ; utFree (
uBuf ) ; * bufSzPtr = newBufSz ; * tBufPtr = tempT ; * uBufPtr = tempU ; if (
istransportdelay ) * xBufPtr = tempX ; } else { * tailPtr = testIdx ; }
return ( true ) ; } real_T Luanvancu_acc_rt_TDelayInterpolate ( real_T
tMinusDelay , real_T tStart , real_T * tBuf , real_T * uBuf , int_T bufSz ,
int_T * lastIdx , int_T oldestIdx , int_T newIdx , real_T initOutput ,
boolean_T discrete , boolean_T minorStepAndTAtLastMajorOutput ) { int_T i ;
real_T yout , t1 , t2 , u1 , u2 ; if ( ( newIdx == 0 ) && ( oldestIdx == 0 )
&& ( tMinusDelay > tStart ) ) return initOutput ; if ( tMinusDelay <= tStart
) return initOutput ; if ( ( tMinusDelay <= tBuf [ oldestIdx ] ) ) { if (
discrete ) { return ( uBuf [ oldestIdx ] ) ; } else { int_T tempIdx =
oldestIdx + 1 ; if ( oldestIdx == bufSz - 1 ) tempIdx = 0 ; t1 = tBuf [
oldestIdx ] ; t2 = tBuf [ tempIdx ] ; u1 = uBuf [ oldestIdx ] ; u2 = uBuf [
tempIdx ] ; if ( t2 == t1 ) { if ( tMinusDelay >= t2 ) { yout = u2 ; } else {
yout = u1 ; } } else { real_T f1 = ( t2 - tMinusDelay ) / ( t2 - t1 ) ;
real_T f2 = 1.0 - f1 ; yout = f1 * u1 + f2 * u2 ; } return yout ; } } if (
minorStepAndTAtLastMajorOutput ) { if ( newIdx != 0 ) { if ( * lastIdx ==
newIdx ) { ( * lastIdx ) -- ; } newIdx -- ; } else { if ( * lastIdx == newIdx
) { * lastIdx = bufSz - 1 ; } newIdx = bufSz - 1 ; } } i = * lastIdx ; if (
tBuf [ i ] < tMinusDelay ) { while ( tBuf [ i ] < tMinusDelay ) { if ( i ==
newIdx ) break ; i = ( i < ( bufSz - 1 ) ) ? ( i + 1 ) : 0 ; } } else { while
( tBuf [ i ] >= tMinusDelay ) { i = ( i > 0 ) ? i - 1 : ( bufSz - 1 ) ; } i =
( i < ( bufSz - 1 ) ) ? ( i + 1 ) : 0 ; } * lastIdx = i ; if ( discrete ) {
double tempEps = ( DBL_EPSILON ) * 128.0 ; double localEps = tempEps *
muDoubleScalarAbs ( tBuf [ i ] ) ; if ( tempEps > localEps ) { localEps =
tempEps ; } localEps = localEps / 2.0 ; if ( tMinusDelay >= ( tBuf [ i ] -
localEps ) ) { yout = uBuf [ i ] ; } else { if ( i == 0 ) { yout = uBuf [
bufSz - 1 ] ; } else { yout = uBuf [ i - 1 ] ; } } } else { if ( i == 0 ) {
t1 = tBuf [ bufSz - 1 ] ; u1 = uBuf [ bufSz - 1 ] ; } else { t1 = tBuf [ i -
1 ] ; u1 = uBuf [ i - 1 ] ; } t2 = tBuf [ i ] ; u2 = uBuf [ i ] ; if ( t2 ==
t1 ) { if ( tMinusDelay >= t2 ) { yout = u2 ; } else { yout = u1 ; } } else {
real_T f1 = ( t2 - tMinusDelay ) / ( t2 - t1 ) ; real_T f2 = 1.0 - f1 ; yout
= f1 * u1 + f2 * u2 ; } } return ( yout ) ; } void rt_ssGetBlockPath (
SimStruct * S , int_T sysIdx , int_T blkIdx , char_T * * path ) {
_ssGetBlockPath ( S , sysIdx , blkIdx , path ) ; } void rt_ssSet_slErrMsg (
SimStruct * S , void * diag ) { if ( ! _ssIsErrorStatusAslErrMsg ( S ) ) {
_ssSet_slErrMsg ( S , diag ) ; } } void rt_ssReportDiagnosticAsWarning (
SimStruct * S , void * diag ) { _ssReportDiagnosticAsWarning ( S , diag ) ; }
static void mdlOutputs ( SimStruct * S , int_T tid ) { real_T B_7_19_0 ;
real_T rtb_B_7_7_0 ; real_T rtb_B_7_17_0 ; int32_T isHit ; B_Luanvancu_T *
_rtB ; P_Luanvancu_T * _rtP ; X_Luanvancu_T * _rtX ; DW_Luanvancu_T * _rtDW ;
_rtDW = ( ( DW_Luanvancu_T * ) ssGetRootDWork ( S ) ) ; _rtX = ( (
X_Luanvancu_T * ) ssGetContStates ( S ) ) ; _rtP = ( ( P_Luanvancu_T * )
ssGetModelRtp ( S ) ) ; _rtB = ( ( B_Luanvancu_T * ) _ssGetModelBlockIO ( S )
) ; _rtB -> B_7_0_0 = 0.0 ; _rtB -> B_7_0_0 += _rtP -> P_5 [ 0 ] * _rtX ->
Motor_1_CSTATE [ 0 ] ; _rtB -> B_7_0_0 += _rtP -> P_5 [ 1 ] * _rtX ->
Motor_1_CSTATE [ 1 ] ; isHit = ssIsSampleHit ( S , 1 , 0 ) ; if ( isHit != 0
) { ssCallAccelRunBlock ( S , 7 , 1 , SS_CALL_MDL_OUTPUTS ) ; } _rtB ->
B_7_3_0 = 0.0 ; _rtB -> B_7_3_0 += _rtP -> P_8 * _rtX -> Heat_Power_CSTATE ;
_rtB -> B_7_4_0 = 0.0 ; _rtB -> B_7_4_0 += _rtP -> P_10 * _rtX ->
Heat_Power_CSTATE_k ; _rtB -> B_7_5_0 = 0.0 ; _rtB -> B_7_5_0 += _rtP -> P_12
* _rtX -> Heat_Power_CSTATE_kq ; _rtB -> B_7_6_0 = 0.0 ; _rtB -> B_7_6_0 +=
_rtP -> P_14 * _rtX -> Vit_CSTATE ; _rtB -> B_7_9_0 = _rtP -> P_16 * _rtX ->
psutbmnn_CSTATE + _rtB -> B_7_8_0 ; _rtB -> B_7_10_0 = 0.0 ; _rtB -> B_7_10_0
+= _rtP -> P_19 * _rtX -> Lulngchtlng_CSTATE ; rtb_B_7_17_0 = _rtP -> P_22 *
_rtX -> Gianhithp_CSTATE ; rtb_B_7_7_0 = _rtP -> P_23 * _rtB -> B_7_10_0 ; if
( rtb_B_7_7_0 >= _rtP -> P_25 ) { rtb_B_7_17_0 /= rtb_B_7_7_0 ; } else if (
rtb_B_7_7_0 >= _rtP -> P_3 ) { rtb_B_7_17_0 *= _rtP -> P_24 ; } else {
rtb_B_7_17_0 = _rtP -> P_24 * rtb_B_7_17_0 * ( _rtP -> P_2 * rtb_B_7_7_0 ) ;
} _rtB -> B_7_18_0 = _rtB -> B_7_11_0 + rtb_B_7_17_0 ; { real_T * * uBuffer =
( real_T * * ) & _rtDW -> TransportDelay_PWORK . TUbufferPtrs [ 0 ] ; real_T
* * tBuffer = ( real_T * * ) & _rtDW -> TransportDelay_PWORK . TUbufferPtrs [
1 ] ; real_T simTime = ssGetT ( S ) ; real_T tMinusDelay = simTime - _rtP ->
P_26 ; B_7_19_0 = Luanvancu_acc_rt_TDelayInterpolate ( tMinusDelay , 0.0 , *
tBuffer , * uBuffer , _rtDW -> TransportDelay_IWORK . CircularBufSize , &
_rtDW -> TransportDelay_IWORK . Last , _rtDW -> TransportDelay_IWORK . Tail ,
_rtDW -> TransportDelay_IWORK . Head , _rtP -> P_27 , 0 , ( boolean_T ) (
ssIsMinorTimeStep ( S ) && ( ssGetTimeOfLastOutput ( S ) == ssGetT ( S ) ) )
) ; } _rtB -> B_7_20_0 = _rtB -> B_7_18_0 + B_7_19_0 ; _rtB -> B_7_23_0 =
_rtP -> P_29 * _rtX -> psutbmnn_CSTATE_j + _rtB -> B_7_22_0 ; _rtB ->
B_7_24_0 = 0.0 ; _rtB -> B_7_24_0 += _rtP -> P_32 * _rtX ->
Lulngchtlng_CSTATE_c ; rtb_B_7_17_0 = _rtP -> P_34 * _rtX ->
Gianhitcaop_CSTATE ; rtb_B_7_7_0 = _rtP -> P_35 * _rtB -> B_7_24_0 ; if (
rtb_B_7_7_0 >= _rtP -> P_37 ) { rtb_B_7_17_0 /= rtb_B_7_7_0 ; } else if (
rtb_B_7_7_0 >= _rtP -> P_1 ) { rtb_B_7_17_0 *= _rtP -> P_36 ; } else {
rtb_B_7_17_0 = _rtP -> P_36 * rtb_B_7_17_0 * ( _rtP -> P_0 * rtb_B_7_7_0 ) ;
} _rtB -> B_7_31_0 = _rtB -> B_7_20_0 + rtb_B_7_17_0 ; rtb_B_7_17_0 = _rtP ->
P_39 * _rtX -> Bhm_CSTATE + _rtB -> B_7_31_0 ; _rtB -> B_7_35_0 = _rtP ->
P_41 * _rtX -> Water_Heat_Absorbing_CSTATE + rtb_B_7_17_0 ; _rtB -> B_7_37_0
= _rtP -> P_43 * _rtX -> Overheated_Pressure_CSTATE * _rtP -> P_44 ; _rtB ->
B_7_42_0 = ( ( _rtP -> P_46 * _rtX -> Tlcaop_CSTATE + _rtP -> P_48 * _rtX ->
Tltrungp_CSTATE ) + _rtP -> P_50 * _rtX -> Tlhp_CSTATE ) * _rtP -> P_51 ;
_rtB -> B_7_43_0 = 0.0 ; _rtB -> B_7_43_0 += _rtP -> P_53 * _rtX ->
Tuabinhp_CSTATE ; _rtB -> B_7_44_0 = 0.0 ; _rtB -> B_7_44_0 += _rtP -> P_55 *
_rtX -> Tuabinhp_CSTATE_b ; _rtB -> B_7_46_0 = _rtB -> B_7_43_0 - _rtP ->
P_57 * _rtX -> Ngngt_CSTATE ; _rtB -> B_7_47_0 = 0.0 ; _rtB -> B_7_47_0 +=
_rtP -> P_59 * _rtX -> Condense_Flow_CSTATE ; ssCallAccelRunBlock ( S , 7 ,
48 , SS_CALL_MDL_OUTPUTS ) ; isHit = ssIsSampleHit ( S , 1 , 0 ) ; if ( isHit
!= 0 ) { if ( _rtP -> P_99 == 1 ) { _rtB -> B_7_50_0 = 0.0 ; } else { _rtB ->
B_7_50_0 = _rtB -> B_7_49_0 ; } ssCallAccelRunBlock ( S , 7 , 51 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 7 , 52 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 7 , 53 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 7 , 54 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 7 , 55 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 7 , 56 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 7 , 57 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 7 , 58 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 7 , 59 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 7 , 60 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 7 , 61 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 7 , 62 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 7 , 63 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 7 , 64 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 7 , 65 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 7 , 66 ,
SS_CALL_MDL_OUTPUTS ) ; } _rtB -> B_7_67_0 = 0.0 ; _rtB -> B_7_67_0 += _rtP
-> P_70 * _rtX -> Gianhitcaop_CSTATE_n ; _rtB -> B_7_68_0 = 0.0 ; _rtB ->
B_7_68_0 += _rtP -> P_72 [ 0 ] * _rtX -> Motor_CSTATE [ 0 ] ; _rtB ->
B_7_68_0 += _rtP -> P_72 [ 1 ] * _rtX -> Motor_CSTATE [ 1 ] ; _rtB ->
B_7_69_0 = 0.0 ; _rtB -> B_7_69_0 += _rtP -> P_74 [ 0 ] * _rtX ->
Motor_CSTATE_f [ 0 ] ; _rtB -> B_7_69_0 += _rtP -> P_74 [ 1 ] * _rtX ->
Motor_CSTATE_f [ 1 ] ; _rtB -> B_7_70_0 = 0.0 ; _rtB -> B_7_70_0 += _rtP ->
P_76 [ 0 ] * _rtX -> Motor_CSTATE_m [ 0 ] ; _rtB -> B_7_70_0 += _rtP -> P_76
[ 1 ] * _rtX -> Motor_CSTATE_m [ 1 ] ; _rtB -> B_7_71_0 = 0.0 ; _rtB ->
B_7_71_0 += _rtP -> P_78 [ 0 ] * _rtX -> Motor_CSTATE_j [ 0 ] ; _rtB ->
B_7_71_0 += _rtP -> P_78 [ 1 ] * _rtX -> Motor_CSTATE_j [ 1 ] ; _rtB ->
B_7_72_0 = 0.0 ; _rtB -> B_7_72_0 += _rtP -> P_80 [ 0 ] * _rtX ->
Motor_CSTATE_k [ 0 ] ; _rtB -> B_7_72_0 += _rtP -> P_80 [ 1 ] * _rtX ->
Motor_CSTATE_k [ 1 ] ; _rtB -> B_7_73_0 = 0.0 ; _rtB -> B_7_73_0 += _rtP ->
P_82 [ 0 ] * _rtX -> Motor_CSTATE_mu [ 0 ] ; _rtB -> B_7_73_0 += _rtP -> P_82
[ 1 ] * _rtX -> Motor_CSTATE_mu [ 1 ] ; if ( rtb_B_7_17_0 > _rtP -> P_83 ) {
_rtB -> B_7_74_0 = _rtP -> P_83 ; } else if ( rtb_B_7_17_0 < _rtP -> P_84 ) {
_rtB -> B_7_74_0 = _rtP -> P_84 ; } else { _rtB -> B_7_74_0 = rtb_B_7_17_0 ;
} ssCallAccelRunBlock ( S , 6 , 0 , SS_CALL_MDL_OUTPUTS ) ; isHit =
ssIsSampleHit ( S , 1 , 0 ) ; if ( isHit != 0 ) { _rtB -> B_7_76_0 = _rtP ->
P_85 * _rtB -> B_7_51_3 ; } _rtB -> B_7_78_0 = ( ( _rtB -> B_7_3_0 + _rtB ->
B_7_4_0 ) + _rtB -> B_7_5_0 ) * _rtP -> P_86 ; _rtB -> B_7_81_0 = _rtP ->
P_90 * _rtX -> Tuabincaop_CSTATE + _rtP -> P_88 * _rtX -> Btisy_CSTATE ; _rtB
-> B_7_82_0 = 0.0 ; _rtB -> B_7_82_0 += _rtP -> P_92 * _rtX ->
Tuabintrungp_CSTATE ; _rtB -> B_7_83_0 = 0.0 ; _rtB -> B_7_83_0 += _rtP ->
P_94 * _rtX -> Tuabincaop_CSTATE_b ; _rtB -> B_7_84_0 = 0.0 ; _rtB ->
B_7_84_0 += _rtP -> P_96 * _rtX -> Tuabintrungp_CSTATE_i ; UNUSED_PARAMETER (
tid ) ; } static void mdlOutputsTID2 ( SimStruct * S , int_T tid ) {
B_Luanvancu_T * _rtB ; P_Luanvancu_T * _rtP ; _rtP = ( ( P_Luanvancu_T * )
ssGetModelRtp ( S ) ) ; _rtB = ( ( B_Luanvancu_T * ) _ssGetModelBlockIO ( S )
) ; _rtB -> B_7_2_0 = _rtP -> P_6 ; _rtB -> B_7_8_0 = _rtP -> P_17 ; _rtB ->
B_7_11_0 = _rtP -> P_20 ; _rtB -> B_7_22_0 = _rtP -> P_30 ; _rtB -> B_7_49_0
= _rtP -> P_64 ; UNUSED_PARAMETER ( tid ) ; }
#define MDL_UPDATE
static void mdlUpdate ( SimStruct * S , int_T tid ) { B_Luanvancu_T * _rtB ;
P_Luanvancu_T * _rtP ; DW_Luanvancu_T * _rtDW ; _rtDW = ( ( DW_Luanvancu_T *
) ssGetRootDWork ( S ) ) ; _rtP = ( ( P_Luanvancu_T * ) ssGetModelRtp ( S ) )
; _rtB = ( ( B_Luanvancu_T * ) _ssGetModelBlockIO ( S ) ) ; { real_T * *
uBuffer = ( real_T * * ) & _rtDW -> TransportDelay_PWORK . TUbufferPtrs [ 0 ]
; real_T * * tBuffer = ( real_T * * ) & _rtDW -> TransportDelay_PWORK .
TUbufferPtrs [ 1 ] ; real_T simTime = ssGetT ( S ) ; _rtDW ->
TransportDelay_IWORK . Head = ( ( _rtDW -> TransportDelay_IWORK . Head < (
_rtDW -> TransportDelay_IWORK . CircularBufSize - 1 ) ) ? ( _rtDW ->
TransportDelay_IWORK . Head + 1 ) : 0 ) ; if ( _rtDW -> TransportDelay_IWORK
. Head == _rtDW -> TransportDelay_IWORK . Tail ) { if ( !
Luanvancu_acc_rt_TDelayUpdateTailOrGrowBuf ( & _rtDW -> TransportDelay_IWORK
. CircularBufSize , & _rtDW -> TransportDelay_IWORK . Tail , & _rtDW ->
TransportDelay_IWORK . Head , & _rtDW -> TransportDelay_IWORK . Last ,
simTime - _rtP -> P_26 , tBuffer , uBuffer , ( NULL ) , ( boolean_T ) 0 ,
false , & _rtDW -> TransportDelay_IWORK . MaxNewBufSize ) ) {
ssSetErrorStatus ( S , "tdelay memory allocation error" ) ; return ; } } ( *
tBuffer ) [ _rtDW -> TransportDelay_IWORK . Head ] = simTime ; ( * uBuffer )
[ _rtDW -> TransportDelay_IWORK . Head ] = _rtB -> B_7_67_0 ; }
UNUSED_PARAMETER ( tid ) ; }
#define MDL_UPDATE
static void mdlUpdateTID2 ( SimStruct * S , int_T tid ) { UNUSED_PARAMETER (
tid ) ; }
#define MDL_DERIVATIVES
static void mdlDerivatives ( SimStruct * S ) { B_Luanvancu_T * _rtB ;
P_Luanvancu_T * _rtP ; X_Luanvancu_T * _rtX ; XDot_Luanvancu_T * _rtXdot ;
_rtXdot = ( ( XDot_Luanvancu_T * ) ssGetdX ( S ) ) ; _rtX = ( ( X_Luanvancu_T
* ) ssGetContStates ( S ) ) ; _rtP = ( ( P_Luanvancu_T * ) ssGetModelRtp ( S
) ) ; _rtB = ( ( B_Luanvancu_T * ) _ssGetModelBlockIO ( S ) ) ; _rtXdot ->
Motor_1_CSTATE [ 0 ] = 0.0 ; _rtXdot -> Motor_1_CSTATE [ 0 ] += _rtP -> P_4 [
0 ] * _rtX -> Motor_1_CSTATE [ 0 ] ; _rtXdot -> Motor_1_CSTATE [ 1 ] = 0.0 ;
_rtXdot -> Motor_1_CSTATE [ 0 ] += _rtP -> P_4 [ 1 ] * _rtX -> Motor_1_CSTATE
[ 1 ] ; _rtXdot -> Motor_1_CSTATE [ 1 ] += _rtX -> Motor_1_CSTATE [ 0 ] ;
_rtXdot -> Motor_1_CSTATE [ 0 ] += _rtB -> B_7_2_0 ; _rtXdot ->
Heat_Power_CSTATE = 0.0 ; _rtXdot -> Heat_Power_CSTATE += _rtP -> P_7 * _rtX
-> Heat_Power_CSTATE ; _rtXdot -> Heat_Power_CSTATE += _rtB -> B_7_71_0 ;
_rtXdot -> Heat_Power_CSTATE_k = 0.0 ; _rtXdot -> Heat_Power_CSTATE_k += _rtP
-> P_9 * _rtX -> Heat_Power_CSTATE_k ; _rtXdot -> Heat_Power_CSTATE_k += _rtB
-> B_7_72_0 ; _rtXdot -> Heat_Power_CSTATE_kq = 0.0 ; _rtXdot ->
Heat_Power_CSTATE_kq += _rtP -> P_11 * _rtX -> Heat_Power_CSTATE_kq ; _rtXdot
-> Heat_Power_CSTATE_kq += _rtB -> B_7_73_0 ; _rtXdot -> Vit_CSTATE = 0.0 ;
_rtXdot -> Vit_CSTATE += _rtP -> P_13 * _rtX -> Vit_CSTATE ; _rtXdot ->
Vit_CSTATE += _rtB -> B_7_78_0 ; _rtXdot -> psutbmnn_CSTATE = 0.0 ; _rtXdot
-> psutbmnn_CSTATE += _rtP -> P_15 * _rtX -> psutbmnn_CSTATE ; _rtXdot ->
psutbmnn_CSTATE += _rtB -> B_7_69_0 ; _rtXdot -> Lulngchtlng_CSTATE = 0.0 ;
_rtXdot -> Lulngchtlng_CSTATE += _rtP -> P_18 * _rtX -> Lulngchtlng_CSTATE ;
_rtXdot -> Lulngchtlng_CSTATE += _rtB -> B_7_69_0 ; _rtXdot ->
Gianhithp_CSTATE = 0.0 ; _rtXdot -> Gianhithp_CSTATE += _rtP -> P_21 * _rtX
-> Gianhithp_CSTATE ; _rtXdot -> Gianhithp_CSTATE += _rtB -> B_7_6_0 ;
_rtXdot -> psutbmnn_CSTATE_j = 0.0 ; _rtXdot -> psutbmnn_CSTATE_j += _rtP ->
P_28 * _rtX -> psutbmnn_CSTATE_j ; _rtXdot -> psutbmnn_CSTATE_j += _rtB ->
B_7_68_0 ; _rtXdot -> Lulngchtlng_CSTATE_c = 0.0 ; _rtXdot ->
Lulngchtlng_CSTATE_c += _rtP -> P_31 * _rtX -> Lulngchtlng_CSTATE_c ; _rtXdot
-> Lulngchtlng_CSTATE_c += _rtB -> B_7_68_0 ; _rtXdot -> Gianhitcaop_CSTATE =
0.0 ; _rtXdot -> Gianhitcaop_CSTATE += _rtP -> P_33 * _rtX ->
Gianhitcaop_CSTATE ; _rtXdot -> Gianhitcaop_CSTATE += _rtB -> B_7_6_0 ;
_rtXdot -> Bhm_CSTATE = 0.0 ; _rtXdot -> Bhm_CSTATE += _rtP -> P_38 * _rtX ->
Bhm_CSTATE ; _rtXdot -> Bhm_CSTATE += _rtB -> B_7_6_0 ; _rtXdot ->
Water_Heat_Absorbing_CSTATE = 0.0 ; _rtXdot -> Water_Heat_Absorbing_CSTATE +=
_rtP -> P_40 * _rtX -> Water_Heat_Absorbing_CSTATE ; _rtXdot ->
Water_Heat_Absorbing_CSTATE += _rtB -> B_7_6_0 ; _rtXdot ->
Overheated_Pressure_CSTATE = 0.0 ; _rtXdot -> Overheated_Pressure_CSTATE +=
_rtP -> P_42 * _rtX -> Overheated_Pressure_CSTATE ; _rtXdot ->
Overheated_Pressure_CSTATE += _rtB -> B_6_0_1 ; _rtXdot -> Tlcaop_CSTATE =
0.0 ; _rtXdot -> Tlcaop_CSTATE += _rtP -> P_45 * _rtX -> Tlcaop_CSTATE ;
_rtXdot -> Tlcaop_CSTATE += _rtB -> B_7_37_0 ; _rtXdot -> Tltrungp_CSTATE =
0.0 ; _rtXdot -> Tltrungp_CSTATE += _rtP -> P_47 * _rtX -> Tltrungp_CSTATE ;
_rtXdot -> Tltrungp_CSTATE += _rtB -> B_7_83_0 ; _rtXdot -> Tlhp_CSTATE = 0.0
; _rtXdot -> Tlhp_CSTATE += _rtP -> P_49 * _rtX -> Tlhp_CSTATE ; _rtXdot ->
Tlhp_CSTATE += _rtB -> B_7_84_0 ; _rtXdot -> Tuabinhp_CSTATE = 0.0 ; _rtXdot
-> Tuabinhp_CSTATE += _rtP -> P_52 * _rtX -> Tuabinhp_CSTATE ; _rtXdot ->
Tuabinhp_CSTATE += _rtB -> B_7_82_0 ; _rtXdot -> Tuabinhp_CSTATE_b = 0.0 ;
_rtXdot -> Tuabinhp_CSTATE_b += _rtP -> P_54 * _rtX -> Tuabinhp_CSTATE_b ;
_rtXdot -> Tuabinhp_CSTATE_b += _rtB -> B_7_84_0 ; _rtXdot -> Ngngt_CSTATE =
0.0 ; _rtXdot -> Ngngt_CSTATE += _rtP -> P_56 * _rtX -> Ngngt_CSTATE ;
_rtXdot -> Ngngt_CSTATE += _rtB -> B_7_47_0 ; _rtXdot -> Condense_Flow_CSTATE
= 0.0 ; _rtXdot -> Condense_Flow_CSTATE += _rtP -> P_58 * _rtX ->
Condense_Flow_CSTATE ; _rtXdot -> Condense_Flow_CSTATE += _rtB -> B_7_70_0 ;
_rtXdot -> Gianhitcaop_CSTATE_n = 0.0 ; _rtXdot -> Gianhitcaop_CSTATE_n +=
_rtP -> P_69 * _rtX -> Gianhitcaop_CSTATE_n ; _rtXdot -> Gianhitcaop_CSTATE_n
+= _rtB -> B_7_6_0 ; _rtXdot -> Motor_CSTATE [ 0 ] = 0.0 ; _rtXdot ->
Motor_CSTATE [ 0 ] += _rtP -> P_71 [ 0 ] * _rtX -> Motor_CSTATE [ 0 ] ;
_rtXdot -> Motor_CSTATE [ 1 ] = 0.0 ; _rtXdot -> Motor_CSTATE [ 0 ] += _rtP
-> P_71 [ 1 ] * _rtX -> Motor_CSTATE [ 1 ] ; _rtXdot -> Motor_CSTATE [ 1 ] +=
_rtX -> Motor_CSTATE [ 0 ] ; _rtXdot -> Motor_CSTATE [ 0 ] += _rtB ->
B_7_51_4 ; _rtXdot -> Motor_CSTATE_f [ 0 ] = 0.0 ; _rtXdot -> Motor_CSTATE_f
[ 0 ] += _rtP -> P_73 [ 0 ] * _rtX -> Motor_CSTATE_f [ 0 ] ; _rtXdot ->
Motor_CSTATE_f [ 1 ] = 0.0 ; _rtXdot -> Motor_CSTATE_f [ 0 ] += _rtP -> P_73
[ 1 ] * _rtX -> Motor_CSTATE_f [ 1 ] ; _rtXdot -> Motor_CSTATE_f [ 1 ] +=
_rtX -> Motor_CSTATE_f [ 0 ] ; _rtXdot -> Motor_CSTATE_f [ 0 ] += _rtB ->
B_7_76_0 ; _rtXdot -> Motor_CSTATE_m [ 0 ] = 0.0 ; _rtXdot -> Motor_CSTATE_m
[ 0 ] += _rtP -> P_75 [ 0 ] * _rtX -> Motor_CSTATE_m [ 0 ] ; _rtXdot ->
Motor_CSTATE_m [ 1 ] = 0.0 ; _rtXdot -> Motor_CSTATE_m [ 0 ] += _rtP -> P_75
[ 1 ] * _rtX -> Motor_CSTATE_m [ 1 ] ; _rtXdot -> Motor_CSTATE_m [ 1 ] +=
_rtX -> Motor_CSTATE_m [ 0 ] ; _rtXdot -> Motor_CSTATE_m [ 0 ] += _rtB ->
B_7_51_5 ; _rtXdot -> Motor_CSTATE_j [ 0 ] = 0.0 ; _rtXdot -> Motor_CSTATE_j
[ 0 ] += _rtP -> P_77 [ 0 ] * _rtX -> Motor_CSTATE_j [ 0 ] ; _rtXdot ->
Motor_CSTATE_j [ 1 ] = 0.0 ; _rtXdot -> Motor_CSTATE_j [ 0 ] += _rtP -> P_77
[ 1 ] * _rtX -> Motor_CSTATE_j [ 1 ] ; _rtXdot -> Motor_CSTATE_j [ 1 ] +=
_rtX -> Motor_CSTATE_j [ 0 ] ; _rtXdot -> Motor_CSTATE_j [ 0 ] += _rtB ->
B_7_51_0 ; _rtXdot -> Motor_CSTATE_k [ 0 ] = 0.0 ; _rtXdot -> Motor_CSTATE_k
[ 0 ] += _rtP -> P_79 [ 0 ] * _rtX -> Motor_CSTATE_k [ 0 ] ; _rtXdot ->
Motor_CSTATE_k [ 1 ] = 0.0 ; _rtXdot -> Motor_CSTATE_k [ 0 ] += _rtP -> P_79
[ 1 ] * _rtX -> Motor_CSTATE_k [ 1 ] ; _rtXdot -> Motor_CSTATE_k [ 1 ] +=
_rtX -> Motor_CSTATE_k [ 0 ] ; _rtXdot -> Motor_CSTATE_k [ 0 ] += _rtB ->
B_7_51_1 ; _rtXdot -> Motor_CSTATE_mu [ 0 ] = 0.0 ; _rtXdot ->
Motor_CSTATE_mu [ 0 ] += _rtP -> P_81 [ 0 ] * _rtX -> Motor_CSTATE_mu [ 0 ] ;
_rtXdot -> Motor_CSTATE_mu [ 1 ] = 0.0 ; _rtXdot -> Motor_CSTATE_mu [ 0 ] +=
_rtP -> P_81 [ 1 ] * _rtX -> Motor_CSTATE_mu [ 1 ] ; _rtXdot ->
Motor_CSTATE_mu [ 1 ] += _rtX -> Motor_CSTATE_mu [ 0 ] ; _rtXdot ->
Motor_CSTATE_mu [ 0 ] += _rtB -> B_7_51_2 ; _rtXdot -> Btisy_CSTATE = 0.0 ;
_rtXdot -> Btisy_CSTATE += _rtP -> P_87 * _rtX -> Btisy_CSTATE ; _rtXdot ->
Btisy_CSTATE += _rtB -> B_7_6_0 ; _rtXdot -> Tuabincaop_CSTATE = 0.0 ;
_rtXdot -> Tuabincaop_CSTATE += _rtP -> P_89 * _rtX -> Tuabincaop_CSTATE ;
_rtXdot -> Tuabincaop_CSTATE += _rtB -> B_7_35_0 ; _rtXdot ->
Tuabintrungp_CSTATE = 0.0 ; _rtXdot -> Tuabintrungp_CSTATE += _rtP -> P_91 *
_rtX -> Tuabintrungp_CSTATE ; _rtXdot -> Tuabintrungp_CSTATE += _rtB ->
B_7_81_0 ; _rtXdot -> Tuabincaop_CSTATE_b = 0.0 ; _rtXdot ->
Tuabincaop_CSTATE_b += _rtP -> P_93 * _rtX -> Tuabincaop_CSTATE_b ; _rtXdot
-> Tuabincaop_CSTATE_b += _rtB -> B_7_37_0 ; _rtXdot -> Tuabintrungp_CSTATE_i
= 0.0 ; _rtXdot -> Tuabintrungp_CSTATE_i += _rtP -> P_95 * _rtX ->
Tuabintrungp_CSTATE_i ; _rtXdot -> Tuabintrungp_CSTATE_i += _rtB -> B_7_83_0
; _rtXdot -> ngcAC_CSTATE [ 0 ] = 0.0 ; _rtXdot -> ngcAC_CSTATE [ 0 ] += _rtP
-> P_97 [ 0 ] * _rtX -> ngcAC_CSTATE [ 0 ] ; _rtXdot -> ngcAC_CSTATE [ 1 ] =
0.0 ; _rtXdot -> ngcAC_CSTATE [ 0 ] += _rtP -> P_97 [ 1 ] * _rtX ->
ngcAC_CSTATE [ 1 ] ; _rtXdot -> ngcAC_CSTATE [ 1 ] += _rtX -> ngcAC_CSTATE [
0 ] ; } static void mdlInitializeSizes ( SimStruct * S ) { ssSetChecksumVal (
S , 0 , 735229072U ) ; ssSetChecksumVal ( S , 1 , 2530365095U ) ;
ssSetChecksumVal ( S , 2 , 2182301256U ) ; ssSetChecksumVal ( S , 3 ,
2807716565U ) ; { mxArray * slVerStructMat = NULL ; mxArray * slStrMat =
mxCreateString ( "simulink" ) ; char slVerChar [ 10 ] ; int status =
mexCallMATLAB ( 1 , & slVerStructMat , 1 , & slStrMat , "ver" ) ; if ( status
== 0 ) { mxArray * slVerMat = mxGetField ( slVerStructMat , 0 , "Version" ) ;
if ( slVerMat == NULL ) { status = 1 ; } else { status = mxGetString (
slVerMat , slVerChar , 10 ) ; } } mxDestroyArray ( slStrMat ) ;
mxDestroyArray ( slVerStructMat ) ; if ( ( status == 1 ) || ( strcmp (
slVerChar , "9.1" ) != 0 ) ) { return ; } } ssSetOptions ( S ,
SS_OPTION_EXCEPTION_FREE_CODE ) ; if ( ssGetSizeofDWork ( S ) != sizeof (
DW_Luanvancu_T ) ) { ssSetErrorStatus ( S ,
"Unexpected error: Internal DWork sizes do "
"not match for accelerator mex file." ) ; } if ( ssGetSizeofGlobalBlockIO ( S
) != sizeof ( B_Luanvancu_T ) ) { ssSetErrorStatus ( S ,
"Unexpected error: Internal BlockIO sizes do "
"not match for accelerator mex file." ) ; } { int ssSizeofParams ;
ssGetSizeofParams ( S , & ssSizeofParams ) ; if ( ssSizeofParams != sizeof (
P_Luanvancu_T ) ) { static char msg [ 256 ] ; sprintf ( msg ,
"Unexpected error: Internal Parameters sizes do "
"not match for accelerator mex file." ) ; } } _ssSetModelRtp ( S , ( real_T *
) & Luanvancu_rtDefaultP ) ; rt_InitInfAndNaN ( sizeof ( real_T ) ) ; }
static void mdlInitializeSampleTimes ( SimStruct * S ) { { SimStruct * childS
; SysOutputFcn * callSysFcns ; childS = ssGetSFunction ( S , 0 ) ;
callSysFcns = ssGetCallSystemOutputFcnList ( childS ) ; callSysFcns [ 3 + 0 ]
= ( SysOutputFcn ) ( NULL ) ; } slAccRegPrmChangeFcn ( S , mdlOutputsTID2 ) ;
} static void mdlTerminate ( SimStruct * S ) { }
#include "simulink.c"
