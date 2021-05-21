#include "__cf_Luanvancu.h"
#ifndef RTW_HEADER_Luanvancu_acc_h_
#define RTW_HEADER_Luanvancu_acc_h_
#include <stddef.h>
#include <float.h>
#ifndef Luanvancu_acc_COMMON_INCLUDES_
#define Luanvancu_acc_COMMON_INCLUDES_
#include <stdlib.h>
#define S_FUNCTION_NAME simulink_only_sfcn 
#define S_FUNCTION_LEVEL 2
#define RTW_GENERATED_S_FUNCTION
#include "rtwtypes.h"
#include "simstruc.h"
#include "fixedpoint.h"
#endif
#include "Luanvancu_acc_types.h"
#include "multiword_types.h"
#include "mwmathutil.h"
#include "rt_defines.h"
#include "rt_nonfinite.h"
typedef struct { real_T B_7_0_0 ; real_T B_7_2_0 ; real_T B_7_3_0 ; real_T
B_7_4_0 ; real_T B_7_5_0 ; real_T B_7_6_0 ; real_T B_7_8_0 ; real_T B_7_9_0 ;
real_T B_7_10_0 ; real_T B_7_11_0 ; real_T B_7_18_0 ; real_T B_7_20_0 ;
real_T B_7_22_0 ; real_T B_7_23_0 ; real_T B_7_24_0 ; real_T B_7_31_0 ;
real_T B_7_35_0 ; real_T B_7_37_0 ; real_T B_7_42_0 ; real_T B_7_43_0 ;
real_T B_7_44_0 ; real_T B_7_46_0 ; real_T B_7_47_0 ; real_T B_7_49_0 ;
real_T B_7_50_0 ; real_T B_7_51_0 ; real_T B_7_51_1 ; real_T B_7_51_2 ;
real_T B_7_51_3 ; real_T B_7_51_4 ; real_T B_7_51_5 ; real_T B_7_67_0 ;
real_T B_7_68_0 ; real_T B_7_69_0 ; real_T B_7_70_0 ; real_T B_7_71_0 ;
real_T B_7_72_0 ; real_T B_7_73_0 ; real_T B_7_74_0 ; real_T B_7_76_0 ;
real_T B_7_78_0 ; real_T B_7_81_0 ; real_T B_7_82_0 ; real_T B_7_83_0 ;
real_T B_7_84_0 ; real_T B_6_0_1 ; } B_Luanvancu_T ; typedef struct { struct
{ real_T modelTStart ; } TransportDelay_RWORK ; void * Scope5_PWORK ; struct
{ void * TUbufferPtrs [ 2 ] ; } TransportDelay_PWORK ; void * Scope1_PWORK ;
void * Scope10_PWORK ; void * Scope11_PWORK ; void * Scope12_PWORK ; void *
Scope13_PWORK ; void * Scope14_PWORK ; void * Scope15_PWORK ; void *
Scope16_PWORK ; void * Scope2_PWORK ; void * Scope25_PWORK ; void *
Scope26_PWORK ; void * Scope6_PWORK ; void * Scope7_PWORK ; void *
Scope8_PWORK ; void * Scope9_PWORK ; int32_T Baohi_sysIdxToRun ; int32_T
TmpAtomicSubsysAtSwitchInport1_sysIdxToRun ; int32_T
TmpAtomicSubsysAtSwitchInport3_sysIdxToRun ; int32_T
TmpAtomicSubsysAtSwitch1Inport3_sysIdxToRun ; int32_T
TmpAtomicSubsysAtSwitchInport1_sysIdxToRun_p ; int32_T
TmpAtomicSubsysAtSwitchInport3_sysIdxToRun_m ; int32_T
TmpAtomicSubsysAtSwitch1Inport3_sysIdxToRun_e ; struct { int_T Tail ; int_T
Head ; int_T Last ; int_T CircularBufSize ; int_T MaxNewBufSize ; }
TransportDelay_IWORK ; } DW_Luanvancu_T ; typedef struct { real_T
Motor_1_CSTATE [ 2 ] ; real_T Heat_Power_CSTATE ; real_T Heat_Power_CSTATE_k
; real_T Heat_Power_CSTATE_kq ; real_T Vit_CSTATE ; real_T psutbmnn_CSTATE ;
real_T Lulngchtlng_CSTATE ; real_T Gianhithp_CSTATE ; real_T
psutbmnn_CSTATE_j ; real_T Lulngchtlng_CSTATE_c ; real_T Gianhitcaop_CSTATE ;
real_T Bhm_CSTATE ; real_T Water_Heat_Absorbing_CSTATE ; real_T
Overheated_Pressure_CSTATE ; real_T Tlcaop_CSTATE ; real_T Tltrungp_CSTATE ;
real_T Tlhp_CSTATE ; real_T Tuabinhp_CSTATE ; real_T Tuabinhp_CSTATE_b ;
real_T Ngngt_CSTATE ; real_T Condense_Flow_CSTATE ; real_T
Gianhitcaop_CSTATE_n ; real_T Motor_CSTATE [ 2 ] ; real_T Motor_CSTATE_f [ 2
] ; real_T Motor_CSTATE_m [ 2 ] ; real_T Motor_CSTATE_j [ 2 ] ; real_T
Motor_CSTATE_k [ 2 ] ; real_T Motor_CSTATE_mu [ 2 ] ; real_T Btisy_CSTATE ;
real_T Tuabincaop_CSTATE ; real_T Tuabintrungp_CSTATE ; real_T
Tuabincaop_CSTATE_b ; real_T Tuabintrungp_CSTATE_i ; real_T ngcAC_CSTATE [ 2
] ; } X_Luanvancu_T ; typedef struct { real_T Motor_1_CSTATE [ 2 ] ; real_T
Heat_Power_CSTATE ; real_T Heat_Power_CSTATE_k ; real_T Heat_Power_CSTATE_kq
; real_T Vit_CSTATE ; real_T psutbmnn_CSTATE ; real_T Lulngchtlng_CSTATE ;
real_T Gianhithp_CSTATE ; real_T psutbmnn_CSTATE_j ; real_T
Lulngchtlng_CSTATE_c ; real_T Gianhitcaop_CSTATE ; real_T Bhm_CSTATE ; real_T
Water_Heat_Absorbing_CSTATE ; real_T Overheated_Pressure_CSTATE ; real_T
Tlcaop_CSTATE ; real_T Tltrungp_CSTATE ; real_T Tlhp_CSTATE ; real_T
Tuabinhp_CSTATE ; real_T Tuabinhp_CSTATE_b ; real_T Ngngt_CSTATE ; real_T
Condense_Flow_CSTATE ; real_T Gianhitcaop_CSTATE_n ; real_T Motor_CSTATE [ 2
] ; real_T Motor_CSTATE_f [ 2 ] ; real_T Motor_CSTATE_m [ 2 ] ; real_T
Motor_CSTATE_j [ 2 ] ; real_T Motor_CSTATE_k [ 2 ] ; real_T Motor_CSTATE_mu [
2 ] ; real_T Btisy_CSTATE ; real_T Tuabincaop_CSTATE ; real_T
Tuabintrungp_CSTATE ; real_T Tuabincaop_CSTATE_b ; real_T
Tuabintrungp_CSTATE_i ; real_T ngcAC_CSTATE [ 2 ] ; } XDot_Luanvancu_T ;
typedef struct { boolean_T Motor_1_CSTATE [ 2 ] ; boolean_T Heat_Power_CSTATE
; boolean_T Heat_Power_CSTATE_k ; boolean_T Heat_Power_CSTATE_kq ; boolean_T
Vit_CSTATE ; boolean_T psutbmnn_CSTATE ; boolean_T Lulngchtlng_CSTATE ;
boolean_T Gianhithp_CSTATE ; boolean_T psutbmnn_CSTATE_j ; boolean_T
Lulngchtlng_CSTATE_c ; boolean_T Gianhitcaop_CSTATE ; boolean_T Bhm_CSTATE ;
boolean_T Water_Heat_Absorbing_CSTATE ; boolean_T Overheated_Pressure_CSTATE
; boolean_T Tlcaop_CSTATE ; boolean_T Tltrungp_CSTATE ; boolean_T Tlhp_CSTATE
; boolean_T Tuabinhp_CSTATE ; boolean_T Tuabinhp_CSTATE_b ; boolean_T
Ngngt_CSTATE ; boolean_T Condense_Flow_CSTATE ; boolean_T
Gianhitcaop_CSTATE_n ; boolean_T Motor_CSTATE [ 2 ] ; boolean_T
Motor_CSTATE_f [ 2 ] ; boolean_T Motor_CSTATE_m [ 2 ] ; boolean_T
Motor_CSTATE_j [ 2 ] ; boolean_T Motor_CSTATE_k [ 2 ] ; boolean_T
Motor_CSTATE_mu [ 2 ] ; boolean_T Btisy_CSTATE ; boolean_T Tuabincaop_CSTATE
; boolean_T Tuabintrungp_CSTATE ; boolean_T Tuabincaop_CSTATE_b ; boolean_T
Tuabintrungp_CSTATE_i ; boolean_T ngcAC_CSTATE [ 2 ] ; } XDis_Luanvancu_T ;
struct P_Luanvancu_T_ { real_T P_0 ; real_T P_1 ; real_T P_2 ; real_T P_3 ;
real_T P_4 [ 2 ] ; real_T P_5 [ 2 ] ; real_T P_6 ; real_T P_7 ; real_T P_8 ;
real_T P_9 ; real_T P_10 ; real_T P_11 ; real_T P_12 ; real_T P_13 ; real_T
P_14 ; real_T P_15 ; real_T P_16 ; real_T P_17 ; real_T P_18 ; real_T P_19 ;
real_T P_20 ; real_T P_21 ; real_T P_22 ; real_T P_23 ; real_T P_24 ; real_T
P_25 ; real_T P_26 ; real_T P_27 ; real_T P_28 ; real_T P_29 ; real_T P_30 ;
real_T P_31 ; real_T P_32 ; real_T P_33 ; real_T P_34 ; real_T P_35 ; real_T
P_36 ; real_T P_37 ; real_T P_38 ; real_T P_39 ; real_T P_40 ; real_T P_41 ;
real_T P_42 ; real_T P_43 ; real_T P_44 ; real_T P_45 ; real_T P_46 ; real_T
P_47 ; real_T P_48 ; real_T P_49 ; real_T P_50 ; real_T P_51 ; real_T P_52 ;
real_T P_53 ; real_T P_54 ; real_T P_55 ; real_T P_56 ; real_T P_57 ; real_T
P_58 ; real_T P_59 ; real_T P_60 [ 2 ] ; real_T P_61 [ 6 ] ; real_T P_62 [ 2
] ; real_T P_63 ; real_T P_64 ; real_T P_65 [ 2 ] ; real_T P_66 [ 6 ] ;
real_T P_67 [ 2 ] ; real_T P_68 ; real_T P_69 ; real_T P_70 ; real_T P_71 [ 2
] ; real_T P_72 [ 2 ] ; real_T P_73 [ 2 ] ; real_T P_74 [ 2 ] ; real_T P_75 [
2 ] ; real_T P_76 [ 2 ] ; real_T P_77 [ 2 ] ; real_T P_78 [ 2 ] ; real_T P_79
[ 2 ] ; real_T P_80 [ 2 ] ; real_T P_81 [ 2 ] ; real_T P_82 [ 2 ] ; real_T
P_83 ; real_T P_84 ; real_T P_85 ; real_T P_86 ; real_T P_87 ; real_T P_88 ;
real_T P_89 ; real_T P_90 ; real_T P_91 ; real_T P_92 ; real_T P_93 ; real_T
P_94 ; real_T P_95 ; real_T P_96 ; real_T P_97 [ 2 ] ; real_T P_98 [ 2 ] ;
uint8_T P_99 ; char_T pad_P_99 [ 7 ] ; } ; extern P_Luanvancu_T
Luanvancu_rtDefaultP ;
#endif
