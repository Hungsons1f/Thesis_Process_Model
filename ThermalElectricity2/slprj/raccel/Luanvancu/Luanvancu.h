#include "__cf_Luanvancu.h"
#ifndef RTW_HEADER_Luanvancu_h_
#define RTW_HEADER_Luanvancu_h_
#include <string.h>
#include <stddef.h>
#include "rtw_modelmap.h"
#ifndef Luanvancu_COMMON_INCLUDES_
#define Luanvancu_COMMON_INCLUDES_
#include <stdlib.h>
#include "rtwtypes.h"
#include "simtarget/slSimTgtSigstreamRTW.h"
#include "simtarget/slSimTgtSlioCoreRTW.h"
#include "simtarget/slSimTgtSlioClientsRTW.h"
#include "simtarget/slSimTgtSlioSdiRTW.h"
#include "sigstream_rtw.h"
#include "simstruc.h"
#include "fixedpoint.h"
#include "raccel.h"
#include "slsv_diagnostic_codegen_c_api.h"
#include "rt_logging.h"
#include "dt_info.h"
#include "ext_work.h"
#endif
#include "Luanvancu_types.h"
#include "multiword_types.h"
#include "rtGetNaN.h"
#include "rt_nonfinite.h"
#include "mwmathutil.h"
#include "rt_defines.h"
#include "rtGetInf.h"
#define MODEL_NAME Luanvancu
#define NSAMPLE_TIMES (3) 
#define NINPUTS (0)       
#define NOUTPUTS (0)     
#define NBLOCKIO (36) 
#define NUM_ZC_EVENTS (0) 
#ifndef NCSTATES
#define NCSTATES (42)   
#elif NCSTATES != 42
#error Invalid specification of NCSTATES defined in compiler command
#endif
#ifndef rtmGetDataMapInfo
#define rtmGetDataMapInfo(rtm) (*rt_dataMapInfoPtr)
#endif
#ifndef rtmSetDataMapInfo
#define rtmSetDataMapInfo(rtm, val) (rt_dataMapInfoPtr = &val)
#endif
#ifndef IN_RACCEL_MAIN
#endif
typedef struct { real_T aoca5q4ss2 ; real_T htwqr5zjg1 ; real_T dbs5szu3hu ;
real_T jnen5c5srs ; real_T ft5o21avnp ; real_T b2pbu1n1pm ; real_T p2bs4tz44d
; real_T ho5gmcpx2t ; real_T nruvz0bur4 ; real_T on3fvwdnfd ; real_T
iesin1c131 ; real_T bszztyqh40 ; real_T jpo2be3j0l ; real_T icvzkup4wn ;
real_T ihxxraqvfh ; real_T ekiqmr4xcv ; real_T fio2xdkn1t ; real_T exaaxqgjgy
; real_T kcbltgbeur ; real_T omytbhyzix ; real_T eoa4dk2j0w ; real_T
cchttyvd1o ; real_T fq23gpnbhd ; real_T nnhqtkzwq5 ; real_T o2l0ex0xfl ;
real_T nqcqxfnc1r ; real_T isyon0iaye ; real_T phn44qhkql ; real_T h0kzcipt5k
; real_T ms0vucqlor ; real_T lqhuiqwr05 ; real_T orrmcemgc5 ; real_T
fyo1xeq1wv ; real_T oagbppphto ; real_T getjyqkigw ; real_T j0mkgu2zq5 ; } B
; typedef struct { struct { void * LoggedData ; } e1t4qyehrf ; struct { void
* LoggedData ; } etpmimicw0 ; struct { void * LoggedData ; } ji1fugwwrl ;
struct { void * LoggedData ; } kovfu253ai ; struct { void * LoggedData ; }
f5g5xdl1oy ; struct { void * LoggedData ; } b0zv3wapek ; struct { void *
LoggedData ; } o3tyvlszgf ; struct { void * LoggedData ; } bapp2mfa1m ;
struct { void * LoggedData ; } galwthsbgm ; struct { void * LoggedData ; }
kyctkwcfhr ; struct { void * LoggedData ; } grorg2vqze ; struct { void *
LoggedData ; } bywoy3pnfd ; struct { void * LoggedData ; } nfufv2zpqr ;
struct { void * LoggedData ; } d2qkeekeuc ; struct { void * LoggedData ; }
dljstdvhan ; struct { void * LoggedData ; } cmcyeswwml ; } DW ; typedef
struct { real_T nhvvzifkqp ; real_T hhmpdifc3c ; real_T ihx3414sey ; real_T
od40m5krxv ; real_T fx3csoaabd ; real_T odw5wlvb34 ; real_T giibywb0cl ;
real_T owgw4zk0aw ; real_T kw1qdc4cz4 ; real_T nbf2k2ygc5 ; real_T jldrrte2lv
; real_T db4yvsthvi ; real_T m0lhrxcp1u ; real_T ercyf5cds5 ; real_T
ox12x4mejg ; real_T dihfkl1cxl ; real_T p0rhkfpw4c ; real_T jd4z5evhqm [ 2 ]
; real_T b1ules1l2z [ 2 ] ; real_T itoxce2i1h ; real_T eript4fjyj [ 2 ] ;
real_T ilkxtfb4ug ; real_T bnlilehha5 [ 2 ] ; real_T lezqgh4iib ; real_T
eyyaxrnhkv [ 2 ] ; real_T j1vh5quwhc ; real_T aiz44fnxee [ 2 ] ; real_T
lyb4dk020l ; real_T jlgmxxrcez ; real_T fyz3cfwrlk ; real_T iykniuxd30 ;
real_T d50zixyk2y ; real_T djver23ubx [ 2 ] ; real_T ekxhmwwutz [ 2 ] ; } X ;
typedef struct { real_T nhvvzifkqp ; real_T hhmpdifc3c ; real_T ihx3414sey ;
real_T od40m5krxv ; real_T fx3csoaabd ; real_T odw5wlvb34 ; real_T giibywb0cl
; real_T owgw4zk0aw ; real_T kw1qdc4cz4 ; real_T nbf2k2ygc5 ; real_T
jldrrte2lv ; real_T db4yvsthvi ; real_T m0lhrxcp1u ; real_T ercyf5cds5 ;
real_T ox12x4mejg ; real_T dihfkl1cxl ; real_T p0rhkfpw4c ; real_T jd4z5evhqm
[ 2 ] ; real_T b1ules1l2z [ 2 ] ; real_T itoxce2i1h ; real_T eript4fjyj [ 2 ]
; real_T ilkxtfb4ug ; real_T bnlilehha5 [ 2 ] ; real_T lezqgh4iib ; real_T
eyyaxrnhkv [ 2 ] ; real_T j1vh5quwhc ; real_T aiz44fnxee [ 2 ] ; real_T
lyb4dk020l ; real_T jlgmxxrcez ; real_T fyz3cfwrlk ; real_T iykniuxd30 ;
real_T d50zixyk2y ; real_T djver23ubx [ 2 ] ; real_T ekxhmwwutz [ 2 ] ; }
XDot ; typedef struct { boolean_T nhvvzifkqp ; boolean_T hhmpdifc3c ;
boolean_T ihx3414sey ; boolean_T od40m5krxv ; boolean_T fx3csoaabd ;
boolean_T odw5wlvb34 ; boolean_T giibywb0cl ; boolean_T owgw4zk0aw ;
boolean_T kw1qdc4cz4 ; boolean_T nbf2k2ygc5 ; boolean_T jldrrte2lv ;
boolean_T db4yvsthvi ; boolean_T m0lhrxcp1u ; boolean_T ercyf5cds5 ;
boolean_T ox12x4mejg ; boolean_T dihfkl1cxl ; boolean_T p0rhkfpw4c ;
boolean_T jd4z5evhqm [ 2 ] ; boolean_T b1ules1l2z [ 2 ] ; boolean_T
itoxce2i1h ; boolean_T eript4fjyj [ 2 ] ; boolean_T ilkxtfb4ug ; boolean_T
bnlilehha5 [ 2 ] ; boolean_T lezqgh4iib ; boolean_T eyyaxrnhkv [ 2 ] ;
boolean_T j1vh5quwhc ; boolean_T aiz44fnxee [ 2 ] ; boolean_T lyb4dk020l ;
boolean_T jlgmxxrcez ; boolean_T fyz3cfwrlk ; boolean_T iykniuxd30 ;
boolean_T d50zixyk2y ; boolean_T djver23ubx [ 2 ] ; boolean_T ekxhmwwutz [ 2
] ; } XDis ; typedef struct { rtwCAPI_ModelMappingInfo mmi ; } DataMapInfo ;
struct P_ { real_T SliderGain_gain ; real_T SliderGain1_gain ; real_T
Gain3_Gain ; real_T Switch1_Threshold ; real_T Gain3_Gain_mhi1gc12x1 ; real_T
Switch1_Threshold_gztv0arq0y ; real_T Constant7_Value ; real_T Gianhithp_A ;
real_T Gianhithp_C ; real_T Lulngchtlng_A ; real_T Lulngchtlng_C ; real_T
Gain2_Gain ; real_T Gain1_Gain ; real_T Switch_Threshold ; real_T
Gianhitcaop_A ; real_T Gianhitcaop_C ; real_T Gianhitcaop_A_gp1isrh1zt ;
real_T Gianhitcaop_C_cuxjfl0bny ; real_T Lulngchtlng_A_lttlvilq1r ; real_T
Lulngchtlng_C_byw0yw2g0l ; real_T Gain2_Gain_dt33lrcogy ; real_T
Gain1_Gain_ajrshsszpr ; real_T Switch_Threshold_bfiwed5r3a ; real_T Bhm_A ;
real_T Bhm_C ; real_T Water_Heat_Absorbing_A ; real_T Water_Heat_Absorbing_C
; real_T psutbmnn_A ; real_T psutbmnn_C ; real_T Constant_Value ; real_T
Tuabinhp_A ; real_T Tuabinhp_C ; real_T Tuabinhp_A_p4fqdq0nyf ; real_T
Tuabinhp_C_iunwv5jncy ; real_T Tlcaop_A ; real_T Tlcaop_C ; real_T Tltrungp_A
; real_T Tltrungp_C ; real_T Tlhp_A ; real_T Tlhp_C ; real_T linhittc_Gain ;
real_T Ngngt_A ; real_T Ngngt_C ; real_T psutbmnn_A_krrl5senh5 ; real_T
psutbmnn_C_fpy55gg1x5 ; real_T Constant_Value_gi4rxypddg ; real_T Vit_A ;
real_T Vit_C ; real_T Overheated_Pressure_A ; real_T Overheated_Pressure_C ;
real_T Gain3_Gain_nyi3yuqbkz ; real_T Motor_A [ 2 ] ; real_T Motor_C [ 2 ] ;
real_T Motor_A_mm1y0efbc2 [ 2 ] ; real_T Motor_C_bulm522rai [ 2 ] ; real_T
Condense_Flow_A ; real_T Condense_Flow_C ; real_T Motor_A_d5m4c15oua [ 2 ] ;
real_T Motor_C_nowl0zxxl1 [ 2 ] ; real_T Constant2_Value ; real_T
Constant3_Value ; real_T Constant4_Value ; real_T Constant5_Value ; real_T
Constant6_Value ; real_T Constant8_Value ; real_T Heat_Power_A ; real_T
Heat_Power_C ; real_T Motor_A_bv5eyzqlpk [ 2 ] ; real_T Motor_C_khazapi3pb [
2 ] ; real_T Heat_Power_A_egs5tnb4gq ; real_T Heat_Power_C_n44yvipdtx ;
real_T Motor_A_adem45aw5v [ 2 ] ; real_T Motor_C_eszjmj2kpa [ 2 ] ; real_T
Heat_Power_A_mwhpd1vf2d ; real_T Heat_Power_C_jpuwdm244t ; real_T
Motor_A_eeuscavczf [ 2 ] ; real_T Motor_C_b3zi30mm3g [ 2 ] ; real_T
Saturation_UpperSat ; real_T Saturation_LowerSat ; real_T Btisy_A ; real_T
Btisy_C ; real_T Tuabincaop_A ; real_T Tuabincaop_C ; real_T Tuabintrungp_A ;
real_T Tuabintrungp_C ; real_T Tuabincaop_A_nvs4biyz0y ; real_T
Tuabincaop_C_pab1ysi2qy ; real_T Tuabintrungp_A_ir4nhbzr3q ; real_T
Tuabintrungp_C_ijxomeac24 ; real_T Motor_1_A [ 2 ] ; real_T Motor_1_C [ 2 ] ;
real_T Constant1_Value ; real_T Constant9_Value ; real_T SFunction_P1_Size [
2 ] ; real_T SFunction_P1 [ 6 ] ; real_T SFunction_P2_Size [ 2 ] ; real_T
SFunction_P2 ; real_T ngcAC_A [ 2 ] ; real_T ngcAC_C [ 2 ] ; uint8_T
ManualSwitch_CurrentSetting ; } ; extern const char *
RT_MEMORY_ALLOCATION_ERROR ; extern B rtB ; extern X rtX ; extern DW rtDW ;
extern P rtP ; extern const rtwCAPI_ModelMappingStaticInfo *
Luanvancu_GetCAPIStaticMap ( void ) ; extern SimStruct * const rtS ; extern
const int_T gblNumToFiles ; extern const int_T gblNumFrFiles ; extern const
int_T gblNumFrWksBlocks ; extern rtInportTUtable * gblInportTUtables ; extern
const char * gblInportFileName ; extern const int_T gblNumRootInportBlks ;
extern const int_T gblNumModelInputs ; extern const int_T
gblInportDataTypeIdx [ ] ; extern const int_T gblInportDims [ ] ; extern
const int_T gblInportComplex [ ] ; extern const int_T gblInportInterpoFlag [
] ; extern const int_T gblInportContinuous [ ] ; extern const int_T
gblParameterTuningTid ; extern DataMapInfo * rt_dataMapInfoPtr ; extern
rtwCAPI_ModelMappingInfo * rt_modelMapInfoPtr ; void MdlOutputs ( int_T tid )
; void MdlOutputsParameterSampleTime ( int_T tid ) ; void MdlUpdate ( int_T
tid ) ; void MdlTerminate ( void ) ; void MdlInitializeSizes ( void ) ; void
MdlInitializeSampleTimes ( void ) ; SimStruct * raccel_register_model ( void
) ;
#endif
