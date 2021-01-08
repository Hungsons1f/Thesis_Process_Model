#include "__cf_Luanvancu.h"
#include "rt_logging_mmi.h"
#include "Luanvancu_capi.h"
#include <math.h>
#include "Luanvancu.h"
#include "Luanvancu_private.h"
#include "Luanvancu_dt.h"
extern void * CreateDiagnosticAsVoidPtr_wrapper ( const char * id , int nargs
, ... ) ; RTWExtModeInfo * gblRTWExtModeInfo = NULL ; extern boolean_T
gblExtModeStartPktReceived ; void raccelForceExtModeShutdown ( ) { if ( !
gblExtModeStartPktReceived ) { boolean_T stopRequested = false ;
rtExtModeWaitForStartPkt ( gblRTWExtModeInfo , 2 , & stopRequested ) ; }
rtExtModeShutdown ( 2 ) ; }
#include "slsv_diagnostic_codegen_c_api.h"
const int_T gblNumToFiles = 0 ; const int_T gblNumFrFiles = 0 ; const int_T
gblNumFrWksBlocks = 0 ;
#ifdef RSIM_WITH_SOLVER_MULTITASKING
boolean_T gbl_raccel_isMultitasking = 1 ;
#else
boolean_T gbl_raccel_isMultitasking = 0 ;
#endif
boolean_T gbl_raccel_tid01eq = 1 ; int_T gbl_raccel_NumST = 3 ; const char_T
* gbl_raccel_Version = "8.14 (R2018a) 06-Feb-2018" ; void
raccel_setup_MMIStateLog ( SimStruct * S ) {
#ifdef UseMMIDataLogging
rt_FillStateSigInfoFromMMI ( ssGetRTWLogInfo ( S ) , & ssGetErrorStatus ( S )
) ;
#else
UNUSED_PARAMETER ( S ) ;
#endif
} static DataMapInfo rt_dataMapInfo ; DataMapInfo * rt_dataMapInfoPtr = &
rt_dataMapInfo ; rtwCAPI_ModelMappingInfo * rt_modelMapInfoPtr = & (
rt_dataMapInfo . mmi ) ; const char * gblSlvrJacPatternFileName =
"slprj\\raccel\\Luanvancu\\Luanvancu_Jpattern.mat" ; const int_T
gblNumRootInportBlks = 0 ; const int_T gblNumModelInputs = 0 ; extern
rtInportTUtable * gblInportTUtables ; extern const char * gblInportFileName ;
const int_T gblInportDataTypeIdx [ ] = { - 1 } ; const int_T gblInportDims [
] = { - 1 } ; const int_T gblInportComplex [ ] = { - 1 } ; const int_T
gblInportInterpoFlag [ ] = { - 1 } ; const int_T gblInportContinuous [ ] = {
- 1 } ;
#include "simstruc.h"
#include "fixedpoint.h"
B rtB ; X rtX ; DW rtDW ; static SimStruct model_S ; SimStruct * const rtS =
& model_S ; void MdlInitialize ( void ) { rtX . nhvvzifkqp = 0.0 ; rtX .
hhmpdifc3c = 0.0 ; rtX . ihx3414sey = 0.0 ; rtX . od40m5krxv = 0.0 ; rtX .
fx3csoaabd = 0.0 ; rtX . odw5wlvb34 = 0.0 ; rtX . giibywb0cl = 0.0 ; rtX .
owgw4zk0aw = 0.0 ; rtX . kw1qdc4cz4 = 0.0 ; rtX . nbf2k2ygc5 = 0.0 ; rtX .
jldrrte2lv = 0.0 ; rtX . db4yvsthvi = 0.0 ; rtX . m0lhrxcp1u = 0.0 ; rtX .
ercyf5cds5 = 0.0 ; rtX . ox12x4mejg = 0.0 ; rtX . dihfkl1cxl = 0.0 ; rtX .
p0rhkfpw4c = 0.0 ; rtX . jd4z5evhqm [ 0 ] = 0.0 ; rtX . b1ules1l2z [ 0 ] =
0.0 ; rtX . jd4z5evhqm [ 1 ] = 0.0 ; rtX . b1ules1l2z [ 1 ] = 0.0 ; rtX .
itoxce2i1h = 0.0 ; rtX . eript4fjyj [ 0 ] = 0.0 ; rtX . eript4fjyj [ 1 ] =
0.0 ; rtX . ilkxtfb4ug = 0.0 ; rtX . bnlilehha5 [ 0 ] = 0.0 ; rtX .
bnlilehha5 [ 1 ] = 0.0 ; rtX . lezqgh4iib = 0.0 ; rtX . eyyaxrnhkv [ 0 ] =
0.0 ; rtX . eyyaxrnhkv [ 1 ] = 0.0 ; rtX . j1vh5quwhc = 0.0 ; rtX .
aiz44fnxee [ 0 ] = 0.0 ; rtX . aiz44fnxee [ 1 ] = 0.0 ; rtX . lyb4dk020l =
0.0 ; rtX . jlgmxxrcez = 0.0 ; rtX . fyz3cfwrlk = 0.0 ; rtX . iykniuxd30 =
0.0 ; rtX . d50zixyk2y = 0.0 ; rtX . djver23ubx [ 0 ] = 0.0 ; rtX .
ekxhmwwutz [ 0 ] = 0.0 ; rtX . djver23ubx [ 1 ] = 0.0 ; rtX . ekxhmwwutz [ 1
] = 0.0 ; } void MdlStart ( void ) { { void * * slioCatalogueAddr =
rt_slioCatalogueAddr ( ) ; void * r2 = ( NULL ) ; void * *
pOSigstreamManagerAddr = ( NULL ) ; const int maxErrorBufferSize = 16384 ;
char errMsgCreatingOSigstreamManager [ 16384 ] ; bool
errorCreatingOSigstreamManager = false ; const char *
errorAddingR2SharedResource = ( NULL ) ; * slioCatalogueAddr =
rtwGetNewSlioCatalogue ( rt_GetMatSigLogSelectorFileName ( ) ) ;
errorAddingR2SharedResource = rtwAddR2SharedResource (
rtwGetPointerFromUniquePtr ( rt_slioCatalogue ( ) ) , 1 ) ; if (
errorAddingR2SharedResource != ( NULL ) ) { rtwTerminateSlioCatalogue (
slioCatalogueAddr ) ; * slioCatalogueAddr = ( NULL ) ; ssSetErrorStatus ( rtS
, errorAddingR2SharedResource ) ; return ; } r2 = rtwGetR2SharedResource (
rtwGetPointerFromUniquePtr ( rt_slioCatalogue ( ) ) ) ;
pOSigstreamManagerAddr = rt_GetOSigstreamManagerAddr ( ) ;
errorCreatingOSigstreamManager = rtwOSigstreamManagerCreateInstance (
rt_GetMatSigLogSelectorFileName ( ) , r2 , pOSigstreamManagerAddr ,
errMsgCreatingOSigstreamManager , maxErrorBufferSize ) ; if (
errorCreatingOSigstreamManager ) { * pOSigstreamManagerAddr = ( NULL ) ;
ssSetErrorStatus ( rtS , errMsgCreatingOSigstreamManager ) ; return ; } } {
bool externalInputIsInDatasetFormat = false ; void * pISigstreamManager =
rt_GetISigstreamManager ( ) ; rtwISigstreamManagerGetInputIsInDatasetFormat (
pISigstreamManager , & externalInputIsInDatasetFormat ) ; if (
externalInputIsInDatasetFormat ) { } } MdlInitialize ( ) ; } void MdlOutputs
( int_T tid ) { int32_T low_i ; int32_T low_ip1 ; int32_T high_i ; int32_T
mid_i ; static const real_T b [ 36 ] = { 17.0 , 22.0 , 27.0 , 29.95 , 32.89 ,
41.53 , 45.82 , 52.57 , 60.08 , 69.12 , 75.87 , 81.33 , 93.5 , 99.62 , 109.32
, 120.24 , 133.56 , 143.64 , 151.87 , 158.86 , 164.98 , 170.44 , 175.39 ,
179.92 , 195.08 , 212.42 , 233.89 , 250.39 , 263.98 , 285.86 , 311.03 ,
342.34 , 357.04 , 365.8 , 373.7 , 425.0 } ; static const real_T c [ 36 ] = {
0.00192 , 0.00262 , 0.00354 , 0.004 , 0.005 , 0.008 , 0.01 , 0.018 , 0.02 ,
0.03 , 0.04 , 0.05 , 0.08 , 0.1 , 0.14 , 0.2 , 0.3 , 0.4 , 0.5 , 0.6 , 0.7 ,
0.8 , 0.9 , 1.0 , 1.4 , 2.0 , 3.0 , 4.0 , 5.0 , 7.0 , 10.0 , 15.0 , 18.0 ,
20.0 , 22.0 , 35.0 } ; real_T cwcmv4opnr ; real_T e2jyhaer03 ; e2jyhaer03 =
rtP . Gianhithp_C * rtX . nhvvzifkqp ; rtB . aoca5q4ss2 = 0.0 ; rtB .
aoca5q4ss2 += rtP . Lulngchtlng_C * rtX . hhmpdifc3c ; cwcmv4opnr = rtP .
Gain2_Gain * rtB . aoca5q4ss2 ; if ( cwcmv4opnr >= rtP . Switch_Threshold ) {
cwcmv4opnr = e2jyhaer03 / cwcmv4opnr ; } else if ( cwcmv4opnr >= rtP .
Switch1_Threshold_gztv0arq0y ) { cwcmv4opnr = rtP . Gain1_Gain * e2jyhaer03 ;
} else { cwcmv4opnr = rtP . Gain1_Gain * e2jyhaer03 * ( rtP .
Gain3_Gain_mhi1gc12x1 * cwcmv4opnr ) ; } rtB . htwqr5zjg1 = rtP .
Constant7_Value + cwcmv4opnr ; rtB . dbs5szu3hu = rtP . Gianhitcaop_C * rtX .
ihx3414sey + rtB . htwqr5zjg1 ; e2jyhaer03 = rtP . Gianhitcaop_C_cuxjfl0bny *
rtX . od40m5krxv ; rtB . jnen5c5srs = 0.0 ; rtB . jnen5c5srs += rtP .
Lulngchtlng_C_byw0yw2g0l * rtX . fx3csoaabd ; cwcmv4opnr = rtP .
Gain2_Gain_dt33lrcogy * rtB . jnen5c5srs ; if ( cwcmv4opnr >= rtP .
Switch_Threshold_bfiwed5r3a ) { e2jyhaer03 /= cwcmv4opnr ; } else if (
cwcmv4opnr >= rtP . Switch1_Threshold ) { e2jyhaer03 *= rtP .
Gain1_Gain_ajrshsszpr ; } else { e2jyhaer03 = rtP . Gain1_Gain_ajrshsszpr *
e2jyhaer03 * ( rtP . Gain3_Gain * cwcmv4opnr ) ; } rtB . ft5o21avnp = rtB .
dbs5szu3hu + e2jyhaer03 ; if ( ssIsSampleHit ( rtS , 1 , 0 ) ) { } e2jyhaer03
= rtP . Bhm_C * rtX . odw5wlvb34 + rtB . ft5o21avnp ; rtB . b2pbu1n1pm = rtP
. Water_Heat_Absorbing_C * rtX . giibywb0cl + e2jyhaer03 ; if ( ssIsSampleHit
( rtS , 1 , 0 ) ) { } rtB . p2bs4tz44d = rtP . psutbmnn_C * rtX . owgw4zk0aw
+ rtP . Constant_Value ; if ( ssIsSampleHit ( rtS , 1 , 0 ) ) { } rtB .
ho5gmcpx2t = 0.0 ; rtB . ho5gmcpx2t += rtP . Tuabinhp_C * rtX . kw1qdc4cz4 ;
if ( ssIsSampleHit ( rtS , 1 , 0 ) ) { } rtB . nruvz0bur4 = 0.0 ; rtB .
nruvz0bur4 += rtP . Tuabinhp_C_iunwv5jncy * rtX . nbf2k2ygc5 ; if (
ssIsSampleHit ( rtS , 1 , 0 ) ) { } rtB . on3fvwdnfd = ( ( rtP . Tlcaop_C *
rtX . jldrrte2lv + rtP . Tltrungp_C * rtX . db4yvsthvi ) + rtP . Tlhp_C * rtX
. m0lhrxcp1u ) * rtP . linhittc_Gain ; if ( ssIsSampleHit ( rtS , 1 , 0 ) ) {
} rtB . iesin1c131 = rtB . ho5gmcpx2t - rtP . Ngngt_C * rtX . ercyf5cds5 ; if
( ssIsSampleHit ( rtS , 1 , 0 ) ) { } rtB . bszztyqh40 = rtP .
psutbmnn_C_fpy55gg1x5 * rtX . ox12x4mejg + rtP . Constant_Value_gi4rxypddg ;
if ( ssIsSampleHit ( rtS , 1 , 0 ) ) { } rtB . jpo2be3j0l = 0.0 ; rtB .
jpo2be3j0l += rtP . Vit_C * rtX . dihfkl1cxl ; if ( ssIsSampleHit ( rtS , 1 ,
0 ) ) { } rtB . icvzkup4wn = rtP . Overheated_Pressure_C * rtX . p0rhkfpw4c *
rtP . Gain3_Gain_nyi3yuqbkz ; if ( ssIsSampleHit ( rtS , 1 , 0 ) ) { } rtB .
ihxxraqvfh = 0.0 ; rtB . ihxxraqvfh += rtP . Motor_C [ 0 ] * rtX . jd4z5evhqm
[ 0 ] ; rtB . ihxxraqvfh += rtP . Motor_C [ 1 ] * rtX . jd4z5evhqm [ 1 ] ;
rtB . ekiqmr4xcv = 0.0 ; rtB . ekiqmr4xcv += rtP . Motor_C_bulm522rai [ 0 ] *
rtX . b1ules1l2z [ 0 ] ; rtB . ekiqmr4xcv += rtP . Motor_C_bulm522rai [ 1 ] *
rtX . b1ules1l2z [ 1 ] ; rtB . fio2xdkn1t = 0.0 ; rtB . fio2xdkn1t += rtP .
Condense_Flow_C * rtX . itoxce2i1h ; rtB . exaaxqgjgy = 0.0 ; rtB .
exaaxqgjgy += rtP . Motor_C_nowl0zxxl1 [ 0 ] * rtX . eript4fjyj [ 0 ] ; rtB .
exaaxqgjgy += rtP . Motor_C_nowl0zxxl1 [ 1 ] * rtX . eript4fjyj [ 1 ] ; rtB .
kcbltgbeur = 0.0 ; rtB . kcbltgbeur += rtP . Motor_C_khazapi3pb [ 0 ] * rtX .
bnlilehha5 [ 0 ] ; rtB . kcbltgbeur += rtP . Motor_C_khazapi3pb [ 1 ] * rtX .
bnlilehha5 [ 1 ] ; rtB . omytbhyzix = 0.0 ; rtB . omytbhyzix += rtP .
Motor_C_eszjmj2kpa [ 0 ] * rtX . eyyaxrnhkv [ 0 ] ; rtB . omytbhyzix += rtP .
Motor_C_eszjmj2kpa [ 1 ] * rtX . eyyaxrnhkv [ 1 ] ; rtB . eoa4dk2j0w = 0.0 ;
rtB . eoa4dk2j0w += rtP . Motor_C_b3zi30mm3g [ 0 ] * rtX . aiz44fnxee [ 0 ] ;
rtB . eoa4dk2j0w += rtP . Motor_C_b3zi30mm3g [ 1 ] * rtX . aiz44fnxee [ 1 ] ;
low_ip1 = 2 ; if ( e2jyhaer03 > rtP . Saturation_UpperSat ) { e2jyhaer03 =
rtP . Saturation_UpperSat ; } else { if ( e2jyhaer03 < rtP .
Saturation_LowerSat ) { e2jyhaer03 = rtP . Saturation_LowerSat ; } } rtB .
j0mkgu2zq5 = ( rtNaN ) ; if ( muDoubleScalarIsNaN ( e2jyhaer03 ) ) { rtB .
j0mkgu2zq5 = ( rtNaN ) ; } else { if ( ! ( ( e2jyhaer03 > 425.0 ) || (
e2jyhaer03 < 17.0 ) ) ) { low_i = 0 ; high_i = 36 ; while ( high_i > low_ip1
) { mid_i = ( ( low_i + high_i ) + 1 ) >> 1 ; if ( e2jyhaer03 >= b [ mid_i -
1 ] ) { low_i = mid_i - 1 ; low_ip1 = mid_i + 1 ; } else { high_i = mid_i ; }
} e2jyhaer03 = ( e2jyhaer03 - b [ low_i ] ) / ( b [ low_i + 1 ] - b [ low_i ]
) ; if ( e2jyhaer03 == 0.0 ) { rtB . j0mkgu2zq5 = c [ low_i ] ; } else if (
e2jyhaer03 == 1.0 ) { rtB . j0mkgu2zq5 = c [ low_i + 1 ] ; } else if ( c [
low_i + 1 ] == c [ low_i ] ) { rtB . j0mkgu2zq5 = c [ low_i ] ; } else { rtB
. j0mkgu2zq5 = ( 1.0 - e2jyhaer03 ) * c [ low_i ] + c [ low_i + 1 ] *
e2jyhaer03 ; } } } rtB . fq23gpnbhd = ( ( rtP . Heat_Power_C * rtX .
ilkxtfb4ug + rtP . Heat_Power_C_n44yvipdtx * rtX . lezqgh4iib ) + rtP .
Heat_Power_C_jpuwdm244t * rtX . j1vh5quwhc ) * rtP . SliderGain1_gain ; rtB .
nnhqtkzwq5 = rtP . Tuabincaop_C * rtX . jlgmxxrcez + rtP . Btisy_C * rtX .
lyb4dk020l ; rtB . o2l0ex0xfl = 0.0 ; rtB . o2l0ex0xfl += rtP .
Tuabintrungp_C * rtX . fyz3cfwrlk ; rtB . nqcqxfnc1r = 0.0 ; rtB . nqcqxfnc1r
+= rtP . Tuabincaop_C_pab1ysi2qy * rtX . iykniuxd30 ; rtB . isyon0iaye = 0.0
; rtB . isyon0iaye += rtP . Tuabintrungp_C_ijxomeac24 * rtX . d50zixyk2y ;
rtB . phn44qhkql = 0.0 ; rtB . phn44qhkql += rtP . Motor_1_C [ 0 ] * rtX .
djver23ubx [ 0 ] ; rtB . phn44qhkql += rtP . Motor_1_C [ 1 ] * rtX .
djver23ubx [ 1 ] ; { SimStruct * rts = ssGetSFunction ( rtS , 0 ) ;
sfcnOutputs ( rts , 0 ) ; } if ( ssIsSampleHit ( rtS , 1 , 0 ) ) { if ( rtP .
ManualSwitch_CurrentSetting == 1 ) { rtB . h0kzcipt5k = 0.0 ; } else { rtB .
h0kzcipt5k = rtP . Constant9_Value ; } { SimStruct * rts = ssGetSFunction (
rtS , 1 ) ; sfcnOutputs ( rts , 0 ) ; } } UNUSED_PARAMETER ( tid ) ; } void
MdlOutputsTID2 ( int_T tid ) { rtB . cchttyvd1o = rtP . SliderGain_gain * rtP
. Constant2_Value ; UNUSED_PARAMETER ( tid ) ; } void MdlUpdate ( int_T tid )
{ UNUSED_PARAMETER ( tid ) ; } void MdlUpdateTID2 ( int_T tid ) {
UNUSED_PARAMETER ( tid ) ; } void MdlDerivatives ( void ) { XDot * _rtXdot ;
_rtXdot = ( ( XDot * ) ssGetdX ( rtS ) ) ; _rtXdot -> nhvvzifkqp = 0.0 ;
_rtXdot -> nhvvzifkqp += rtP . Gianhithp_A * rtX . nhvvzifkqp ; _rtXdot ->
nhvvzifkqp += rtB . jpo2be3j0l ; _rtXdot -> hhmpdifc3c = 0.0 ; _rtXdot ->
hhmpdifc3c += rtP . Lulngchtlng_A * rtX . hhmpdifc3c ; _rtXdot -> hhmpdifc3c
+= rtB . ekiqmr4xcv ; _rtXdot -> ihx3414sey = 0.0 ; _rtXdot -> ihx3414sey +=
rtP . Gianhitcaop_A * rtX . ihx3414sey ; _rtXdot -> ihx3414sey += rtB .
jpo2be3j0l ; _rtXdot -> od40m5krxv = 0.0 ; _rtXdot -> od40m5krxv += rtP .
Gianhitcaop_A_gp1isrh1zt * rtX . od40m5krxv ; _rtXdot -> od40m5krxv += rtB .
jpo2be3j0l ; _rtXdot -> fx3csoaabd = 0.0 ; _rtXdot -> fx3csoaabd += rtP .
Lulngchtlng_A_lttlvilq1r * rtX . fx3csoaabd ; _rtXdot -> fx3csoaabd += rtB .
ihxxraqvfh ; _rtXdot -> odw5wlvb34 = 0.0 ; _rtXdot -> odw5wlvb34 += rtP .
Bhm_A * rtX . odw5wlvb34 ; _rtXdot -> odw5wlvb34 += rtB . jpo2be3j0l ;
_rtXdot -> giibywb0cl = 0.0 ; _rtXdot -> giibywb0cl += rtP .
Water_Heat_Absorbing_A * rtX . giibywb0cl ; _rtXdot -> giibywb0cl += rtB .
jpo2be3j0l ; _rtXdot -> owgw4zk0aw = 0.0 ; _rtXdot -> owgw4zk0aw += rtP .
psutbmnn_A * rtX . owgw4zk0aw ; _rtXdot -> owgw4zk0aw += rtB . ekiqmr4xcv ;
_rtXdot -> kw1qdc4cz4 = 0.0 ; _rtXdot -> kw1qdc4cz4 += rtP . Tuabinhp_A * rtX
. kw1qdc4cz4 ; _rtXdot -> kw1qdc4cz4 += rtB . o2l0ex0xfl ; _rtXdot ->
nbf2k2ygc5 = 0.0 ; _rtXdot -> nbf2k2ygc5 += rtP . Tuabinhp_A_p4fqdq0nyf * rtX
. nbf2k2ygc5 ; _rtXdot -> nbf2k2ygc5 += rtB . isyon0iaye ; _rtXdot ->
jldrrte2lv = 0.0 ; _rtXdot -> jldrrte2lv += rtP . Tlcaop_A * rtX . jldrrte2lv
; _rtXdot -> jldrrte2lv += rtB . icvzkup4wn ; _rtXdot -> db4yvsthvi = 0.0 ;
_rtXdot -> db4yvsthvi += rtP . Tltrungp_A * rtX . db4yvsthvi ; _rtXdot ->
db4yvsthvi += rtB . nqcqxfnc1r ; _rtXdot -> m0lhrxcp1u = 0.0 ; _rtXdot ->
m0lhrxcp1u += rtP . Tlhp_A * rtX . m0lhrxcp1u ; _rtXdot -> m0lhrxcp1u += rtB
. isyon0iaye ; _rtXdot -> ercyf5cds5 = 0.0 ; _rtXdot -> ercyf5cds5 += rtP .
Ngngt_A * rtX . ercyf5cds5 ; _rtXdot -> ercyf5cds5 += rtB . fio2xdkn1t ;
_rtXdot -> ox12x4mejg = 0.0 ; _rtXdot -> ox12x4mejg += rtP .
psutbmnn_A_krrl5senh5 * rtX . ox12x4mejg ; _rtXdot -> ox12x4mejg += rtB .
ihxxraqvfh ; _rtXdot -> dihfkl1cxl = 0.0 ; _rtXdot -> dihfkl1cxl += rtP .
Vit_A * rtX . dihfkl1cxl ; _rtXdot -> dihfkl1cxl += rtB . fq23gpnbhd ;
_rtXdot -> p0rhkfpw4c = 0.0 ; _rtXdot -> p0rhkfpw4c += rtP .
Overheated_Pressure_A * rtX . p0rhkfpw4c ; _rtXdot -> p0rhkfpw4c += rtB .
j0mkgu2zq5 ; _rtXdot -> jd4z5evhqm [ 0 ] = 0.0 ; _rtXdot -> jd4z5evhqm [ 0 ]
+= rtP . Motor_A [ 0 ] * rtX . jd4z5evhqm [ 0 ] ; _rtXdot -> jd4z5evhqm [ 1 ]
= 0.0 ; _rtXdot -> jd4z5evhqm [ 0 ] += rtP . Motor_A [ 1 ] * rtX . jd4z5evhqm
[ 1 ] ; _rtXdot -> jd4z5evhqm [ 1 ] += rtX . jd4z5evhqm [ 0 ] ; _rtXdot ->
jd4z5evhqm [ 0 ] += rtP . Constant6_Value ; _rtXdot -> b1ules1l2z [ 0 ] = 0.0
; _rtXdot -> b1ules1l2z [ 0 ] += rtP . Motor_A_mm1y0efbc2 [ 0 ] * rtX .
b1ules1l2z [ 0 ] ; _rtXdot -> b1ules1l2z [ 1 ] = 0.0 ; _rtXdot -> b1ules1l2z
[ 0 ] += rtP . Motor_A_mm1y0efbc2 [ 1 ] * rtX . b1ules1l2z [ 1 ] ; _rtXdot ->
b1ules1l2z [ 1 ] += rtX . b1ules1l2z [ 0 ] ; _rtXdot -> b1ules1l2z [ 0 ] +=
rtB . cchttyvd1o ; _rtXdot -> itoxce2i1h = 0.0 ; _rtXdot -> itoxce2i1h += rtP
. Condense_Flow_A * rtX . itoxce2i1h ; _rtXdot -> itoxce2i1h += rtB .
exaaxqgjgy ; _rtXdot -> eript4fjyj [ 0 ] = 0.0 ; _rtXdot -> eript4fjyj [ 0 ]
+= rtP . Motor_A_d5m4c15oua [ 0 ] * rtX . eript4fjyj [ 0 ] ; _rtXdot ->
eript4fjyj [ 1 ] = 0.0 ; _rtXdot -> eript4fjyj [ 0 ] += rtP .
Motor_A_d5m4c15oua [ 1 ] * rtX . eript4fjyj [ 1 ] ; _rtXdot -> eript4fjyj [ 1
] += rtX . eript4fjyj [ 0 ] ; _rtXdot -> eript4fjyj [ 0 ] += rtP .
Constant8_Value ; _rtXdot -> ilkxtfb4ug = 0.0 ; _rtXdot -> ilkxtfb4ug += rtP
. Heat_Power_A * rtX . ilkxtfb4ug ; _rtXdot -> ilkxtfb4ug += rtB . kcbltgbeur
; _rtXdot -> bnlilehha5 [ 0 ] = 0.0 ; _rtXdot -> bnlilehha5 [ 0 ] += rtP .
Motor_A_bv5eyzqlpk [ 0 ] * rtX . bnlilehha5 [ 0 ] ; _rtXdot -> bnlilehha5 [ 1
] = 0.0 ; _rtXdot -> bnlilehha5 [ 0 ] += rtP . Motor_A_bv5eyzqlpk [ 1 ] * rtX
. bnlilehha5 [ 1 ] ; _rtXdot -> bnlilehha5 [ 1 ] += rtX . bnlilehha5 [ 0 ] ;
_rtXdot -> bnlilehha5 [ 0 ] += rtP . Constant3_Value ; _rtXdot -> lezqgh4iib
= 0.0 ; _rtXdot -> lezqgh4iib += rtP . Heat_Power_A_egs5tnb4gq * rtX .
lezqgh4iib ; _rtXdot -> lezqgh4iib += rtB . omytbhyzix ; _rtXdot ->
eyyaxrnhkv [ 0 ] = 0.0 ; _rtXdot -> eyyaxrnhkv [ 0 ] += rtP .
Motor_A_adem45aw5v [ 0 ] * rtX . eyyaxrnhkv [ 0 ] ; _rtXdot -> eyyaxrnhkv [ 1
] = 0.0 ; _rtXdot -> eyyaxrnhkv [ 0 ] += rtP . Motor_A_adem45aw5v [ 1 ] * rtX
. eyyaxrnhkv [ 1 ] ; _rtXdot -> eyyaxrnhkv [ 1 ] += rtX . eyyaxrnhkv [ 0 ] ;
_rtXdot -> eyyaxrnhkv [ 0 ] += rtP . Constant4_Value ; _rtXdot -> j1vh5quwhc
= 0.0 ; _rtXdot -> j1vh5quwhc += rtP . Heat_Power_A_mwhpd1vf2d * rtX .
j1vh5quwhc ; _rtXdot -> j1vh5quwhc += rtB . eoa4dk2j0w ; _rtXdot ->
aiz44fnxee [ 0 ] = 0.0 ; _rtXdot -> aiz44fnxee [ 0 ] += rtP .
Motor_A_eeuscavczf [ 0 ] * rtX . aiz44fnxee [ 0 ] ; _rtXdot -> aiz44fnxee [ 1
] = 0.0 ; _rtXdot -> aiz44fnxee [ 0 ] += rtP . Motor_A_eeuscavczf [ 1 ] * rtX
. aiz44fnxee [ 1 ] ; _rtXdot -> aiz44fnxee [ 1 ] += rtX . aiz44fnxee [ 0 ] ;
_rtXdot -> aiz44fnxee [ 0 ] += rtP . Constant5_Value ; _rtXdot -> lyb4dk020l
= 0.0 ; _rtXdot -> lyb4dk020l += rtP . Btisy_A * rtX . lyb4dk020l ; _rtXdot
-> lyb4dk020l += rtB . jpo2be3j0l ; _rtXdot -> jlgmxxrcez = 0.0 ; _rtXdot ->
jlgmxxrcez += rtP . Tuabincaop_A * rtX . jlgmxxrcez ; _rtXdot -> jlgmxxrcez
+= rtB . b2pbu1n1pm ; _rtXdot -> fyz3cfwrlk = 0.0 ; _rtXdot -> fyz3cfwrlk +=
rtP . Tuabintrungp_A * rtX . fyz3cfwrlk ; _rtXdot -> fyz3cfwrlk += rtB .
nnhqtkzwq5 ; _rtXdot -> iykniuxd30 = 0.0 ; _rtXdot -> iykniuxd30 += rtP .
Tuabincaop_A_nvs4biyz0y * rtX . iykniuxd30 ; _rtXdot -> iykniuxd30 += rtB .
icvzkup4wn ; _rtXdot -> d50zixyk2y = 0.0 ; _rtXdot -> d50zixyk2y += rtP .
Tuabintrungp_A_ir4nhbzr3q * rtX . d50zixyk2y ; _rtXdot -> d50zixyk2y += rtB .
nqcqxfnc1r ; _rtXdot -> djver23ubx [ 0 ] = 0.0 ; _rtXdot -> djver23ubx [ 0 ]
+= rtP . Motor_1_A [ 0 ] * rtX . djver23ubx [ 0 ] ; _rtXdot -> djver23ubx [ 1
] = 0.0 ; _rtXdot -> djver23ubx [ 0 ] += rtP . Motor_1_A [ 1 ] * rtX .
djver23ubx [ 1 ] ; _rtXdot -> djver23ubx [ 1 ] += rtX . djver23ubx [ 0 ] ;
_rtXdot -> djver23ubx [ 0 ] += rtP . Constant1_Value ; _rtXdot -> ekxhmwwutz
[ 0 ] = 0.0 ; _rtXdot -> ekxhmwwutz [ 0 ] += rtP . ngcAC_A [ 0 ] * rtX .
ekxhmwwutz [ 0 ] ; _rtXdot -> ekxhmwwutz [ 1 ] = 0.0 ; _rtXdot -> ekxhmwwutz
[ 0 ] += rtP . ngcAC_A [ 1 ] * rtX . ekxhmwwutz [ 1 ] ; _rtXdot -> ekxhmwwutz
[ 1 ] += rtX . ekxhmwwutz [ 0 ] ; } void MdlProjection ( void ) { } void
MdlTerminate ( void ) { { SimStruct * rts = ssGetSFunction ( rtS , 0 ) ;
sfcnTerminate ( rts ) ; } { SimStruct * rts = ssGetSFunction ( rtS , 1 ) ;
sfcnTerminate ( rts ) ; } if ( rt_slioCatalogue ( ) != ( NULL ) ) { void * *
slioCatalogueAddr = rt_slioCatalogueAddr ( ) ; rtwSaveDatasetsToMatFile (
rtwGetPointerFromUniquePtr ( rt_slioCatalogue ( ) ) ,
rt_GetMatSigstreamLoggingFileName ( ) ) ; rtwTerminateSlioCatalogue (
slioCatalogueAddr ) ; * slioCatalogueAddr = NULL ; } } void
MdlInitializeSizes ( void ) { ssSetNumContStates ( rtS , 42 ) ;
ssSetNumPeriodicContStates ( rtS , 0 ) ; ssSetNumY ( rtS , 0 ) ; ssSetNumU (
rtS , 0 ) ; ssSetDirectFeedThrough ( rtS , 0 ) ; ssSetNumSampleTimes ( rtS ,
2 ) ; ssSetNumBlocks ( rtS , 108 ) ; ssSetNumBlockIO ( rtS , 36 ) ;
ssSetNumBlockParams ( rtS , 123 ) ; } void MdlInitializeSampleTimes ( void )
{ ssSetSampleTime ( rtS , 0 , 0.0 ) ; ssSetSampleTime ( rtS , 1 , 0.09 ) ;
ssSetOffsetTime ( rtS , 0 , 0.0 ) ; ssSetOffsetTime ( rtS , 1 , 0.0 ) ; }
void raccel_set_checksum ( ) { ssSetChecksumVal ( rtS , 0 , 499643481U ) ;
ssSetChecksumVal ( rtS , 1 , 3733294652U ) ; ssSetChecksumVal ( rtS , 2 ,
3467698729U ) ; ssSetChecksumVal ( rtS , 3 , 550543215U ) ; }
#if defined(_MSC_VER)
#pragma optimize( "", off )
#endif
SimStruct * raccel_register_model ( void ) { static struct _ssMdlInfo mdlInfo
; ( void ) memset ( ( char * ) rtS , 0 , sizeof ( SimStruct ) ) ; ( void )
memset ( ( char * ) & mdlInfo , 0 , sizeof ( struct _ssMdlInfo ) ) ;
ssSetMdlInfoPtr ( rtS , & mdlInfo ) ; { static time_T mdlPeriod [
NSAMPLE_TIMES ] ; static time_T mdlOffset [ NSAMPLE_TIMES ] ; static time_T
mdlTaskTimes [ NSAMPLE_TIMES ] ; static int_T mdlTsMap [ NSAMPLE_TIMES ] ;
static int_T mdlSampleHits [ NSAMPLE_TIMES ] ; static boolean_T
mdlTNextWasAdjustedPtr [ NSAMPLE_TIMES ] ; static int_T mdlPerTaskSampleHits
[ NSAMPLE_TIMES * NSAMPLE_TIMES ] ; static time_T mdlTimeOfNextSampleHit [
NSAMPLE_TIMES ] ; { int_T i ; for ( i = 0 ; i < NSAMPLE_TIMES ; i ++ ) {
mdlPeriod [ i ] = 0.0 ; mdlOffset [ i ] = 0.0 ; mdlTaskTimes [ i ] = 0.0 ;
mdlTsMap [ i ] = i ; mdlSampleHits [ i ] = 1 ; } } ssSetSampleTimePtr ( rtS ,
& mdlPeriod [ 0 ] ) ; ssSetOffsetTimePtr ( rtS , & mdlOffset [ 0 ] ) ;
ssSetSampleTimeTaskIDPtr ( rtS , & mdlTsMap [ 0 ] ) ; ssSetTPtr ( rtS , &
mdlTaskTimes [ 0 ] ) ; ssSetSampleHitPtr ( rtS , & mdlSampleHits [ 0 ] ) ;
ssSetTNextWasAdjustedPtr ( rtS , & mdlTNextWasAdjustedPtr [ 0 ] ) ;
ssSetPerTaskSampleHitsPtr ( rtS , & mdlPerTaskSampleHits [ 0 ] ) ;
ssSetTimeOfNextSampleHitPtr ( rtS , & mdlTimeOfNextSampleHit [ 0 ] ) ; }
ssSetSolverMode ( rtS , SOLVER_MODE_SINGLETASKING ) ; { ssSetBlockIO ( rtS ,
( ( void * ) & rtB ) ) ; ( void ) memset ( ( ( void * ) & rtB ) , 0 , sizeof
( B ) ) ; } ssSetDefaultParam ( rtS , ( real_T * ) & rtP ) ; { real_T * x = (
real_T * ) & rtX ; ssSetContStates ( rtS , x ) ; ( void ) memset ( ( void * )
x , 0 , sizeof ( X ) ) ; } { void * dwork = ( void * ) & rtDW ;
ssSetRootDWork ( rtS , dwork ) ; ( void ) memset ( dwork , 0 , sizeof ( DW )
) ; } { static DataTypeTransInfo dtInfo ; ( void ) memset ( ( char_T * ) &
dtInfo , 0 , sizeof ( dtInfo ) ) ; ssSetModelMappingInfo ( rtS , & dtInfo ) ;
dtInfo . numDataTypes = 14 ; dtInfo . dataTypeSizes = & rtDataTypeSizes [ 0 ]
; dtInfo . dataTypeNames = & rtDataTypeNames [ 0 ] ; dtInfo . BTransTable = &
rtBTransTable ; dtInfo . PTransTable = & rtPTransTable ; }
Luanvancu_InitializeDataMapInfo ( ) ; ssSetIsRapidAcceleratorActive ( rtS ,
true ) ; ssSetRootSS ( rtS , rtS ) ; ssSetVersion ( rtS ,
SIMSTRUCT_VERSION_LEVEL2 ) ; ssSetModelName ( rtS , "Luanvancu" ) ; ssSetPath
( rtS , "Luanvancu" ) ; ssSetTStart ( rtS , 0.0 ) ; ssSetTFinal ( rtS , 99.99
) ; ssSetStepSize ( rtS , 0.09 ) ; ssSetFixedStepSize ( rtS , 0.09 ) ; {
static RTWLogInfo rt_DataLoggingInfo ; rt_DataLoggingInfo . loggingInterval =
NULL ; ssSetRTWLogInfo ( rtS , & rt_DataLoggingInfo ) ; } {
rtliSetLogXSignalInfo ( ssGetRTWLogInfo ( rtS ) , ( NULL ) ) ;
rtliSetLogXSignalPtrs ( ssGetRTWLogInfo ( rtS ) , ( NULL ) ) ; rtliSetLogT (
ssGetRTWLogInfo ( rtS ) , "tout" ) ; rtliSetLogX ( ssGetRTWLogInfo ( rtS ) ,
"" ) ; rtliSetLogXFinal ( ssGetRTWLogInfo ( rtS ) , "" ) ;
rtliSetLogVarNameModifier ( ssGetRTWLogInfo ( rtS ) , "none" ) ;
rtliSetLogFormat ( ssGetRTWLogInfo ( rtS ) , 4 ) ; rtliSetLogMaxRows (
ssGetRTWLogInfo ( rtS ) , 0 ) ; rtliSetLogDecimation ( ssGetRTWLogInfo ( rtS
) , 1 ) ; rtliSetLogY ( ssGetRTWLogInfo ( rtS ) , "" ) ;
rtliSetLogYSignalInfo ( ssGetRTWLogInfo ( rtS ) , ( NULL ) ) ;
rtliSetLogYSignalPtrs ( ssGetRTWLogInfo ( rtS ) , ( NULL ) ) ; } { static
struct _ssStatesInfo2 statesInfo2 ; ssSetStatesInfo2 ( rtS , & statesInfo2 )
; } { static ssPeriodicStatesInfo periodicStatesInfo ;
ssSetPeriodicStatesInfo ( rtS , & periodicStatesInfo ) ; } { static
ssSolverInfo slvrInfo ; static boolean_T contStatesDisabled [ 42 ] ;
ssSetSolverInfo ( rtS , & slvrInfo ) ; ssSetSolverName ( rtS , "ode4" ) ;
ssSetVariableStepSolver ( rtS , 0 ) ; ssSetSolverConsistencyChecking ( rtS ,
0 ) ; ssSetSolverAdaptiveZcDetection ( rtS , 0 ) ;
ssSetSolverRobustResetMethod ( rtS , 0 ) ; ssSetSolverStateProjection ( rtS ,
0 ) ; ssSetSolverMassMatrixType ( rtS , ( ssMatrixType ) 0 ) ;
ssSetSolverMassMatrixNzMax ( rtS , 0 ) ; ssSetModelOutputs ( rtS , MdlOutputs
) ; ssSetModelLogData ( rtS , rt_UpdateTXYLogVars ) ;
ssSetModelLogDataIfInInterval ( rtS , rt_UpdateTXXFYLogVars ) ;
ssSetModelUpdate ( rtS , MdlUpdate ) ; ssSetModelDerivatives ( rtS ,
MdlDerivatives ) ; ssSetTNextTid ( rtS , INT_MIN ) ; ssSetTNext ( rtS ,
rtMinusInf ) ; ssSetSolverNeedsReset ( rtS ) ; ssSetNumNonsampledZCs ( rtS ,
0 ) ; ssSetContStateDisabled ( rtS , contStatesDisabled ) ; }
ssSetChecksumVal ( rtS , 0 , 499643481U ) ; ssSetChecksumVal ( rtS , 1 ,
3733294652U ) ; ssSetChecksumVal ( rtS , 2 , 3467698729U ) ; ssSetChecksumVal
( rtS , 3 , 550543215U ) ; { static const sysRanDType rtAlwaysEnabled =
SUBSYS_RAN_BC_ENABLE ; static RTWExtModeInfo rt_ExtModeInfo ; static const
sysRanDType * systemRan [ 8 ] ; gblRTWExtModeInfo = & rt_ExtModeInfo ;
ssSetRTWExtModeInfo ( rtS , & rt_ExtModeInfo ) ;
rteiSetSubSystemActiveVectorAddresses ( & rt_ExtModeInfo , systemRan ) ;
systemRan [ 0 ] = & rtAlwaysEnabled ; systemRan [ 1 ] = & rtAlwaysEnabled ;
systemRan [ 2 ] = & rtAlwaysEnabled ; systemRan [ 3 ] = & rtAlwaysEnabled ;
systemRan [ 4 ] = & rtAlwaysEnabled ; systemRan [ 5 ] = & rtAlwaysEnabled ;
systemRan [ 6 ] = & rtAlwaysEnabled ; systemRan [ 7 ] = & rtAlwaysEnabled ;
rteiSetModelMappingInfoPtr ( ssGetRTWExtModeInfo ( rtS ) , &
ssGetModelMappingInfo ( rtS ) ) ; rteiSetChecksumsPtr ( ssGetRTWExtModeInfo (
rtS ) , ssGetChecksums ( rtS ) ) ; rteiSetTPtr ( ssGetRTWExtModeInfo ( rtS )
, ssGetTPtr ( rtS ) ) ; } ssSetNumSFunctions ( rtS , 2 ) ; { static SimStruct
childSFunctions [ 2 ] ; static SimStruct * childSFunctionPtrs [ 2 ] ; ( void
) memset ( ( void * ) & childSFunctions [ 0 ] , 0 , sizeof ( childSFunctions
) ) ; ssSetSFunctions ( rtS , & childSFunctionPtrs [ 0 ] ) ; ssSetSFunction (
rtS , 0 , & childSFunctions [ 0 ] ) ; ssSetSFunction ( rtS , 1 , &
childSFunctions [ 1 ] ) ; { SimStruct * rts = ssGetSFunction ( rtS , 0 ) ;
static time_T sfcnPeriod [ 1 ] ; static time_T sfcnOffset [ 1 ] ; static
int_T sfcnTsMap [ 1 ] ; ( void ) memset ( ( void * ) sfcnPeriod , 0 , sizeof
( time_T ) * 1 ) ; ( void ) memset ( ( void * ) sfcnOffset , 0 , sizeof (
time_T ) * 1 ) ; ssSetSampleTimePtr ( rts , & sfcnPeriod [ 0 ] ) ;
ssSetOffsetTimePtr ( rts , & sfcnOffset [ 0 ] ) ; ssSetSampleTimeTaskIDPtr (
rts , sfcnTsMap ) ; { static struct _ssBlkInfo2 _blkInfo2 ; struct
_ssBlkInfo2 * blkInfo2 = & _blkInfo2 ; ssSetBlkInfo2Ptr ( rts , blkInfo2 ) ;
} { static struct _ssPortInfo2 _portInfo2 ; struct _ssPortInfo2 * portInfo2 =
& _portInfo2 ; _ssSetBlkInfo2PortInfo2Ptr ( rts , portInfo2 ) ; }
ssSetMdlInfoPtr ( rts , ssGetMdlInfoPtr ( rtS ) ) ; { static struct
_ssSFcnModelMethods2 methods2 ; ssSetModelMethods2 ( rts , & methods2 ) ; } {
static struct _ssSFcnModelMethods3 methods3 ; ssSetModelMethods3 ( rts , &
methods3 ) ; } { static struct _ssSFcnModelMethods4 methods4 ;
ssSetModelMethods4 ( rts , & methods4 ) ; } { static struct _ssStatesInfo2
statesInfo2 ; static ssPeriodicStatesInfo periodicStatesInfo ;
ssSetStatesInfo2 ( rts , & statesInfo2 ) ; ssSetPeriodicStatesInfo ( rts , &
periodicStatesInfo ) ; } { static struct _ssPortInputs inputPortInfo [ 1 ] ;
_ssSetNumInputPorts ( rts , 1 ) ; ssSetPortInfoForInputs ( rts , &
inputPortInfo [ 0 ] ) ; { static struct _ssInPortUnit inputPortUnits [ 1 ] ;
_ssSetPortInfo2ForInputUnits ( rts , & inputPortUnits [ 0 ] ) ; }
ssSetInputPortUnit ( rts , 0 , 0 ) ; { static struct _ssInPortCoSimAttribute
inputPortCoSimAttribute [ 1 ] ; _ssSetPortInfo2ForInputCoSimAttribute ( rts ,
& inputPortCoSimAttribute [ 0 ] ) ; } ssSetInputPortIsContinuousQuantity (
rts , 0 , 0 ) ; { static real_T const * sfcnUPtrs [ 1 ] ; sfcnUPtrs [ 0 ] = &
rtB . phn44qhkql ; ssSetInputPortSignalPtrs ( rts , 0 , ( InputPtrsType ) &
sfcnUPtrs [ 0 ] ) ; _ssSetInputPortNumDimensions ( rts , 0 , 1 ) ;
ssSetInputPortWidth ( rts , 0 , 1 ) ; } } ssSetModelName ( rts ,
"S-Function1" ) ; ssSetPath ( rts , "Luanvancu/S-Function1" ) ; if (
ssGetRTModel ( rtS ) == ( NULL ) ) { ssSetParentSS ( rts , rtS ) ;
ssSetRootSS ( rts , ssGetRootSS ( rtS ) ) ; } else { ssSetRTModel ( rts ,
ssGetRTModel ( rtS ) ) ; ssSetParentSS ( rts , ( NULL ) ) ; ssSetRootSS ( rts
, rts ) ; } ssSetVersion ( rts , SIMSTRUCT_VERSION_LEVEL2 ) ; AdsWrite ( rts
) ; sfcnInitializeSizes ( rts ) ; sfcnInitializeSampleTimes ( rts ) ;
ssSetSampleTime ( rts , 0 , 0.0 ) ; ssSetOffsetTime ( rts , 0 , 0.0 ) ;
sfcnTsMap [ 0 ] = 0 ; ssSetInputPortWidth ( rts , 0 , 1 ) ;
ssSetInputPortDataType ( rts , 0 , SS_DOUBLE ) ; ssSetInputPortComplexSignal
( rts , 0 , 0 ) ; ssSetInputPortFrameData ( rts , 0 , 0 ) ;
ssSetInputPortUnit ( rts , 0 , 0 ) ; ssSetInputPortIsContinuousQuantity ( rts
, 0 , 0 ) ; ssSetNumNonsampledZCs ( rts , 0 ) ; _ssSetInputPortConnected (
rts , 0 , 1 ) ; ssSetInputPortBufferDstPort ( rts , 0 , - 1 ) ; } { SimStruct
* rts = ssGetSFunction ( rtS , 1 ) ; static time_T sfcnPeriod [ 1 ] ; static
time_T sfcnOffset [ 1 ] ; static int_T sfcnTsMap [ 1 ] ; ( void ) memset ( (
void * ) sfcnPeriod , 0 , sizeof ( time_T ) * 1 ) ; ( void ) memset ( ( void
* ) sfcnOffset , 0 , sizeof ( time_T ) * 1 ) ; ssSetSampleTimePtr ( rts , &
sfcnPeriod [ 0 ] ) ; ssSetOffsetTimePtr ( rts , & sfcnOffset [ 0 ] ) ;
ssSetSampleTimeTaskIDPtr ( rts , sfcnTsMap ) ; { static struct _ssBlkInfo2
_blkInfo2 ; struct _ssBlkInfo2 * blkInfo2 = & _blkInfo2 ; ssSetBlkInfo2Ptr (
rts , blkInfo2 ) ; } { static struct _ssPortInfo2 _portInfo2 ; struct
_ssPortInfo2 * portInfo2 = & _portInfo2 ; _ssSetBlkInfo2PortInfo2Ptr ( rts ,
portInfo2 ) ; } ssSetMdlInfoPtr ( rts , ssGetMdlInfoPtr ( rtS ) ) ; { static
struct _ssSFcnModelMethods2 methods2 ; ssSetModelMethods2 ( rts , & methods2
) ; } { static struct _ssSFcnModelMethods3 methods3 ; ssSetModelMethods3 (
rts , & methods3 ) ; } { static struct _ssSFcnModelMethods4 methods4 ;
ssSetModelMethods4 ( rts , & methods4 ) ; } { static struct _ssStatesInfo2
statesInfo2 ; static ssPeriodicStatesInfo periodicStatesInfo ;
ssSetStatesInfo2 ( rts , & statesInfo2 ) ; ssSetPeriodicStatesInfo ( rts , &
periodicStatesInfo ) ; } { static struct _ssPortInputs inputPortInfo [ 1 ] ;
_ssSetNumInputPorts ( rts , 1 ) ; ssSetPortInfoForInputs ( rts , &
inputPortInfo [ 0 ] ) ; { static struct _ssInPortUnit inputPortUnits [ 1 ] ;
_ssSetPortInfo2ForInputUnits ( rts , & inputPortUnits [ 0 ] ) ; }
ssSetInputPortUnit ( rts , 0 , 0 ) ; { static struct _ssInPortCoSimAttribute
inputPortCoSimAttribute [ 1 ] ; _ssSetPortInfo2ForInputCoSimAttribute ( rts ,
& inputPortCoSimAttribute [ 0 ] ) ; } ssSetInputPortIsContinuousQuantity (
rts , 0 , 0 ) ; { static real_T const * sfcnUPtrs [ 1 ] ; sfcnUPtrs [ 0 ] = &
rtB . h0kzcipt5k ; ssSetInputPortSignalPtrs ( rts , 0 , ( InputPtrsType ) &
sfcnUPtrs [ 0 ] ) ; _ssSetInputPortNumDimensions ( rts , 0 , 1 ) ;
ssSetInputPortWidth ( rts , 0 , 1 ) ; } } { static struct _ssPortOutputs
outputPortInfo [ 6 ] ; ssSetPortInfoForOutputs ( rts , & outputPortInfo [ 0 ]
) ; _ssSetNumOutputPorts ( rts , 6 ) ; { static struct _ssOutPortUnit
outputPortUnits [ 6 ] ; _ssSetPortInfo2ForOutputUnits ( rts , &
outputPortUnits [ 0 ] ) ; } ssSetOutputPortUnit ( rts , 0 , 0 ) ;
ssSetOutputPortUnit ( rts , 1 , 0 ) ; ssSetOutputPortUnit ( rts , 2 , 0 ) ;
ssSetOutputPortUnit ( rts , 3 , 0 ) ; ssSetOutputPortUnit ( rts , 4 , 0 ) ;
ssSetOutputPortUnit ( rts , 5 , 0 ) ; { static struct
_ssOutPortCoSimAttribute outputPortCoSimAttribute [ 6 ] ;
_ssSetPortInfo2ForOutputCoSimAttribute ( rts , & outputPortCoSimAttribute [ 0
] ) ; } ssSetOutputPortIsContinuousQuantity ( rts , 0 , 0 ) ;
ssSetOutputPortIsContinuousQuantity ( rts , 1 , 0 ) ;
ssSetOutputPortIsContinuousQuantity ( rts , 2 , 0 ) ;
ssSetOutputPortIsContinuousQuantity ( rts , 3 , 0 ) ;
ssSetOutputPortIsContinuousQuantity ( rts , 4 , 0 ) ;
ssSetOutputPortIsContinuousQuantity ( rts , 5 , 0 ) ; {
_ssSetOutputPortNumDimensions ( rts , 0 , 1 ) ; ssSetOutputPortWidth ( rts ,
0 , 1 ) ; ssSetOutputPortSignal ( rts , 0 , ( ( real_T * ) & rtB . ms0vucqlor
) ) ; } { _ssSetOutputPortNumDimensions ( rts , 1 , 1 ) ;
ssSetOutputPortWidth ( rts , 1 , 1 ) ; ssSetOutputPortSignal ( rts , 1 , ( (
real_T * ) & rtB . lqhuiqwr05 ) ) ; } { _ssSetOutputPortNumDimensions ( rts ,
2 , 1 ) ; ssSetOutputPortWidth ( rts , 2 , 1 ) ; ssSetOutputPortSignal ( rts
, 2 , ( ( real_T * ) & rtB . orrmcemgc5 ) ) ; } {
_ssSetOutputPortNumDimensions ( rts , 3 , 1 ) ; ssSetOutputPortWidth ( rts ,
3 , 1 ) ; ssSetOutputPortSignal ( rts , 3 , ( ( real_T * ) & rtB . fyo1xeq1wv
) ) ; } { _ssSetOutputPortNumDimensions ( rts , 4 , 1 ) ;
ssSetOutputPortWidth ( rts , 4 , 1 ) ; ssSetOutputPortSignal ( rts , 4 , ( (
real_T * ) & rtB . oagbppphto ) ) ; } { _ssSetOutputPortNumDimensions ( rts ,
5 , 1 ) ; ssSetOutputPortWidth ( rts , 5 , 1 ) ; ssSetOutputPortSignal ( rts
, 5 , ( ( real_T * ) & rtB . getjyqkigw ) ) ; } } ssSetModelName ( rts ,
"S-Function" ) ; ssSetPath ( rts , "Luanvancu/S-Function" ) ; if (
ssGetRTModel ( rtS ) == ( NULL ) ) { ssSetParentSS ( rts , rtS ) ;
ssSetRootSS ( rts , ssGetRootSS ( rtS ) ) ; } else { ssSetRTModel ( rts ,
ssGetRTModel ( rtS ) ) ; ssSetParentSS ( rts , ( NULL ) ) ; ssSetRootSS ( rts
, rts ) ; } ssSetVersion ( rts , SIMSTRUCT_VERSION_LEVEL2 ) ; { static
mxArray * sfcnParams [ 2 ] ; ssSetSFcnParamsCount ( rts , 2 ) ;
ssSetSFcnParamsPtr ( rts , & sfcnParams [ 0 ] ) ; ssSetSFcnParam ( rts , 0 ,
( mxArray * ) rtP . SFunction_P1_Size ) ; ssSetSFcnParam ( rts , 1 , (
mxArray * ) rtP . SFunction_P2_Size ) ; } AdsRead ( rts ) ;
sfcnInitializeSizes ( rts ) ; sfcnInitializeSampleTimes ( rts ) ;
ssSetSampleTime ( rts , 0 , 0.09 ) ; ssSetOffsetTime ( rts , 0 , 0.0 ) ;
sfcnTsMap [ 0 ] = 1 ; ssSetInputPortWidth ( rts , 0 , 1 ) ;
ssSetInputPortDataType ( rts , 0 , SS_DOUBLE ) ; ssSetInputPortComplexSignal
( rts , 0 , 0 ) ; ssSetInputPortFrameData ( rts , 0 , 0 ) ;
ssSetInputPortUnit ( rts , 0 , 0 ) ; ssSetInputPortIsContinuousQuantity ( rts
, 0 , 0 ) ; ssSetOutputPortWidth ( rts , 0 , 1 ) ; ssSetOutputPortDataType (
rts , 0 , SS_DOUBLE ) ; ssSetOutputPortComplexSignal ( rts , 0 , 0 ) ;
ssSetOutputPortFrameData ( rts , 0 , 0 ) ; ssSetOutputPortUnit ( rts , 0 , 0
) ; ssSetOutputPortIsContinuousQuantity ( rts , 0 , 0 ) ;
ssSetOutputPortWidth ( rts , 1 , 1 ) ; ssSetOutputPortDataType ( rts , 1 ,
SS_DOUBLE ) ; ssSetOutputPortComplexSignal ( rts , 1 , 0 ) ;
ssSetOutputPortFrameData ( rts , 1 , 0 ) ; ssSetOutputPortUnit ( rts , 1 , 0
) ; ssSetOutputPortIsContinuousQuantity ( rts , 1 , 0 ) ;
ssSetOutputPortWidth ( rts , 2 , 1 ) ; ssSetOutputPortDataType ( rts , 2 ,
SS_DOUBLE ) ; ssSetOutputPortComplexSignal ( rts , 2 , 0 ) ;
ssSetOutputPortFrameData ( rts , 2 , 0 ) ; ssSetOutputPortUnit ( rts , 2 , 0
) ; ssSetOutputPortIsContinuousQuantity ( rts , 2 , 0 ) ;
ssSetOutputPortWidth ( rts , 3 , 1 ) ; ssSetOutputPortDataType ( rts , 3 ,
SS_DOUBLE ) ; ssSetOutputPortComplexSignal ( rts , 3 , 0 ) ;
ssSetOutputPortFrameData ( rts , 3 , 0 ) ; ssSetOutputPortUnit ( rts , 3 , 0
) ; ssSetOutputPortIsContinuousQuantity ( rts , 3 , 0 ) ;
ssSetOutputPortWidth ( rts , 4 , 1 ) ; ssSetOutputPortDataType ( rts , 4 ,
SS_DOUBLE ) ; ssSetOutputPortComplexSignal ( rts , 4 , 0 ) ;
ssSetOutputPortFrameData ( rts , 4 , 0 ) ; ssSetOutputPortUnit ( rts , 4 , 0
) ; ssSetOutputPortIsContinuousQuantity ( rts , 4 , 0 ) ;
ssSetOutputPortWidth ( rts , 5 , 1 ) ; ssSetOutputPortDataType ( rts , 5 ,
SS_DOUBLE ) ; ssSetOutputPortComplexSignal ( rts , 5 , 0 ) ;
ssSetOutputPortFrameData ( rts , 5 , 0 ) ; ssSetOutputPortUnit ( rts , 5 , 0
) ; ssSetOutputPortIsContinuousQuantity ( rts , 5 , 0 ) ;
ssSetNumNonsampledZCs ( rts , 0 ) ; _ssSetInputPortConnected ( rts , 0 , 1 )
; _ssSetOutputPortConnected ( rts , 0 , 1 ) ; _ssSetOutputPortConnected ( rts
, 1 , 1 ) ; _ssSetOutputPortConnected ( rts , 2 , 1 ) ;
_ssSetOutputPortConnected ( rts , 3 , 1 ) ; _ssSetOutputPortConnected ( rts ,
4 , 1 ) ; _ssSetOutputPortConnected ( rts , 5 , 1 ) ;
_ssSetOutputPortBeingMerged ( rts , 0 , 0 ) ; _ssSetOutputPortBeingMerged (
rts , 1 , 0 ) ; _ssSetOutputPortBeingMerged ( rts , 2 , 0 ) ;
_ssSetOutputPortBeingMerged ( rts , 3 , 0 ) ; _ssSetOutputPortBeingMerged (
rts , 4 , 0 ) ; _ssSetOutputPortBeingMerged ( rts , 5 , 0 ) ;
ssSetInputPortBufferDstPort ( rts , 0 , - 1 ) ; } } return rtS ; }
#if defined(_MSC_VER)
#pragma optimize( "", on )
#endif
const int_T gblParameterTuningTid = 2 ; void MdlOutputsParameterSampleTime (
int_T tid ) { MdlOutputsTID2 ( tid ) ; }
