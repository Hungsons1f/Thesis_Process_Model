#include "__cf_Luanvancu.h"
#include "rtw_capi.h"
#ifdef HOST_CAPI_BUILD
#include "Luanvancu_capi_host.h"
#define sizeof(s) ((size_t)(0xFFFF))
#undef rt_offsetof
#define rt_offsetof(s,el) ((uint16_T)(0xFFFF))
#define TARGET_CONST
#define TARGET_STRING(s) (s)    
#else
#include "builtin_typeid_types.h"
#include "Luanvancu.h"
#include "Luanvancu_capi.h"
#include "Luanvancu_private.h"
#ifdef LIGHT_WEIGHT_CAPI
#define TARGET_CONST                  
#define TARGET_STRING(s)               (NULL)                    
#else
#define TARGET_CONST                   const
#define TARGET_STRING(s)               (s)
#endif
#endif
static const rtwCAPI_Signals rtBlockSignals [ ] = { { 0 , 0 , TARGET_STRING (
"Luanvancu/S-Function" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 1 ,
0 , TARGET_STRING ( "Luanvancu/S-Function" ) , TARGET_STRING ( "" ) , 1 , 0 ,
0 , 0 , 0 } , { 2 , 0 , TARGET_STRING ( "Luanvancu/S-Function" ) ,
TARGET_STRING ( "" ) , 2 , 0 , 0 , 0 , 0 } , { 3 , 0 , TARGET_STRING (
"Luanvancu/S-Function" ) , TARGET_STRING ( "" ) , 3 , 0 , 0 , 0 , 0 } , { 4 ,
0 , TARGET_STRING ( "Luanvancu/S-Function" ) , TARGET_STRING ( "" ) , 4 , 0 ,
0 , 0 , 0 } , { 5 , 0 , TARGET_STRING ( "Luanvancu/S-Function" ) ,
TARGET_STRING ( "" ) , 5 , 0 , 0 , 0 , 0 } , { 6 , 0 , TARGET_STRING (
"Luanvancu/Manual Switch" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , {
7 , 0 , TARGET_STRING ( "Luanvancu/B&#xEC;nh kh&#x1EED; khí/Sum" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 8 , 0 , TARGET_STRING (
"Luanvancu/B&#xEC;nh ngýng/Sum" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1
} , { 9 , 0 , TARGET_STRING ( "Luanvancu/Bõm c&#x1EA5;p/Sum" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 10 , 0 , TARGET_STRING (
"Luanvancu/Bõm c&#x1EA5;p/Lýu lý&#x1EE3;ng ch&#x1EA5;t l&#x1ECF;ng" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 11 , 0 , TARGET_STRING (
"Luanvancu/Bõm c&#x1EA5;p/Motor" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1
} , { 12 , 0 , TARGET_STRING ( "Luanvancu/Bõm ngýng/Sum" ) , TARGET_STRING (
"" ) , 0 , 0 , 0 , 0 , 1 } , { 13 , 0 , TARGET_STRING (
"Luanvancu/Bõm ngýng/Lýu lý&#x1EE3;ng ch&#x1EA5;t l&#x1ECF;ng" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 14 , 0 , TARGET_STRING (
"Luanvancu/Bõm ngýng/Motor" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } ,
{ 15 , 0 , TARGET_STRING (
"Luanvancu/B&#x1ED9; ph&#x1EAD;n ð&#x1ED1;t/V&#xF2;i ð&#x1ED1;t" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 16 , 0 , TARGET_STRING (
"Luanvancu/Condense_Pump/Condense_Flow" ) , TARGET_STRING ( "" ) , 0 , 0 , 0
, 0 , 1 } , { 17 , 0 , TARGET_STRING ( "Luanvancu/Condense_Pump/Motor" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 18 , 0 , TARGET_STRING (
"Luanvancu/Conveyor/Motor_1" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } ,
{ 19 , 0 , TARGET_STRING ( "Luanvancu/Force_Fan/Motor" ) , TARGET_STRING ( ""
) , 0 , 0 , 0 , 0 , 1 } , { 20 , 0 , TARGET_STRING (
"Luanvancu/Force_Fan1/Motor" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } ,
{ 21 , 0 , TARGET_STRING ( "Luanvancu/Force_Fan2/Motor" ) , TARGET_STRING (
"" ) , 0 , 0 , 0 , 0 , 1 } , { 22 , 0 , TARGET_STRING (
"Luanvancu/Gia nhi&#x1EC7;t cao áp/Sum1" ) , TARGET_STRING ( "" ) , 0 , 0 , 0
, 0 , 1 } , { 23 , 0 , TARGET_STRING (
"Luanvancu/Gia nhi&#x1EC7;t h&#x1EA1; áp/Sum" ) , TARGET_STRING ( "" ) , 0 ,
0 , 0 , 0 , 1 } , { 24 , 7 , TARGET_STRING ( "Luanvancu/L&#xF2; hõi/Bao hõi"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 25 , 0 , TARGET_STRING (
"Luanvancu/Slider Gain/Slider Gain" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0
, 2 } , { 26 , 0 , TARGET_STRING ( "Luanvancu/Slider Gain1/Slider Gain" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 27 , 0 , TARGET_STRING (
"Luanvancu/L&#xF2; hõi/B&#x1ED9; quá nhi&#x1EC7;t/Gain3" ) , TARGET_STRING (
"" ) , 0 , 0 , 0 , 0 , 1 } , { 28 , 0 , TARGET_STRING (
"Luanvancu/L&#xF2; hõi/B&#x1ED9; quá nhi&#x1EC7;t/Sum" ) , TARGET_STRING ( ""
) , 0 , 0 , 0 , 0 , 1 } , { 29 , 0 , TARGET_STRING (
"Luanvancu/Tua bin/Tua bin-Nhi&#x1EC7;t/Sum" ) , TARGET_STRING ( "" ) , 0 , 0
, 0 , 0 , 1 } , { 30 , 0 , TARGET_STRING (
"Luanvancu/Tua bin/Tua bin-Nhi&#x1EC7;t/Tua bin h&#x1EA1; áp" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 31 , 0 , TARGET_STRING (
"Luanvancu/Tua bin/Tua bin-Nhi&#x1EC7;t/Tua bin trung áp" ) , TARGET_STRING (
"" ) , 0 , 0 , 0 , 0 , 1 } , { 32 , 0 , TARGET_STRING (
 "Luanvancu/Tua bin/Tua bin-T&#x1ED1;c ð&#x1ED9;/Ð&#x1ED9; l&#x1EE3;i nhi&#x1EC7;t-t&#x1ED1;c ð&#x1ED9;"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 33 , 0 , TARGET_STRING (
"Luanvancu/Tua bin/Tua bin-Áp/Tua bin cao áp" ) , TARGET_STRING ( "" ) , 0 ,
0 , 0 , 0 , 1 } , { 34 , 0 , TARGET_STRING (
"Luanvancu/Tua bin/Tua bin-Áp/Tua bin h&#x1EA1; áp" ) , TARGET_STRING ( "" )
, 0 , 0 , 0 , 0 , 1 } , { 35 , 0 , TARGET_STRING (
"Luanvancu/Tua bin/Tua bin-Áp/Tua bin trung áp" ) , TARGET_STRING ( "" ) , 0
, 0 , 0 , 0 , 1 } , { 0 , 0 , ( NULL ) , ( NULL ) , 0 , 0 , 0 , 0 , 0 } } ;
static const rtwCAPI_BlockParameters rtBlockParameters [ ] = { { 36 ,
TARGET_STRING ( "Luanvancu/Slider Gain" ) , TARGET_STRING ( "gain" ) , 0 , 0
, 0 } , { 37 , TARGET_STRING ( "Luanvancu/Slider Gain1" ) , TARGET_STRING (
"gain" ) , 0 , 0 , 0 } , { 38 , TARGET_STRING ( "Luanvancu/Constant1" ) ,
TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 39 , TARGET_STRING (
"Luanvancu/Constant2" ) , TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 40 ,
TARGET_STRING ( "Luanvancu/Constant3" ) , TARGET_STRING ( "Value" ) , 0 , 0 ,
0 } , { 41 , TARGET_STRING ( "Luanvancu/Constant4" ) , TARGET_STRING (
"Value" ) , 0 , 0 , 0 } , { 42 , TARGET_STRING ( "Luanvancu/Constant5" ) ,
TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 43 , TARGET_STRING (
"Luanvancu/Constant6" ) , TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 44 ,
TARGET_STRING ( "Luanvancu/Constant7" ) , TARGET_STRING ( "Value" ) , 0 , 0 ,
0 } , { 45 , TARGET_STRING ( "Luanvancu/Constant8" ) , TARGET_STRING (
"Value" ) , 0 , 0 , 0 } , { 46 , TARGET_STRING ( "Luanvancu/Constant9" ) ,
TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 47 , TARGET_STRING (
"Luanvancu/S-Function" ) , TARGET_STRING ( "P1" ) , 0 , 1 , 0 } , { 48 ,
TARGET_STRING ( "Luanvancu/S-Function" ) , TARGET_STRING ( "P2" ) , 0 , 0 , 0
} , { 49 , TARGET_STRING ( "Luanvancu/Manual Switch" ) , TARGET_STRING (
"CurrentSetting" ) , 1 , 0 , 0 } , { 50 , TARGET_STRING (
"Luanvancu/B&#xEC;nh kh&#x1EED; khí/Gia nhi&#x1EC7;t cao áp" ) ,
TARGET_STRING ( "A" ) , 0 , 0 , 0 } , { 51 , TARGET_STRING (
"Luanvancu/B&#xEC;nh kh&#x1EED; khí/Gia nhi&#x1EC7;t cao áp" ) ,
TARGET_STRING ( "C" ) , 0 , 0 , 0 } , { 52 , TARGET_STRING (
"Luanvancu/B&#xEC;nh ngýng/Ngýng t&#x1EE5;" ) , TARGET_STRING ( "A" ) , 0 , 0
, 0 } , { 53 , TARGET_STRING ( "Luanvancu/B&#xEC;nh ngýng/Ngýng t&#x1EE5;" )
, TARGET_STRING ( "C" ) , 0 , 0 , 0 } , { 54 , TARGET_STRING (
"Luanvancu/Bõm c&#x1EA5;p/Constant" ) , TARGET_STRING ( "Value" ) , 0 , 0 , 0
} , { 55 , TARGET_STRING (
"Luanvancu/Bõm c&#x1EA5;p/Lýu lý&#x1EE3;ng ch&#x1EA5;t l&#x1ECF;ng" ) ,
TARGET_STRING ( "A" ) , 0 , 0 , 0 } , { 56 , TARGET_STRING (
"Luanvancu/Bõm c&#x1EA5;p/Lýu lý&#x1EE3;ng ch&#x1EA5;t l&#x1ECF;ng" ) ,
TARGET_STRING ( "C" ) , 0 , 0 , 0 } , { 57 , TARGET_STRING (
"Luanvancu/Bõm c&#x1EA5;p/Motor" ) , TARGET_STRING ( "A" ) , 0 , 2 , 0 } , {
58 , TARGET_STRING ( "Luanvancu/Bõm c&#x1EA5;p/Motor" ) , TARGET_STRING ( "C"
) , 0 , 3 , 0 } , { 59 , TARGET_STRING (
"Luanvancu/Bõm c&#x1EA5;p/Áp su&#x1EA5;t bõm nén" ) , TARGET_STRING ( "A" ) ,
0 , 0 , 0 } , { 60 , TARGET_STRING (
"Luanvancu/Bõm c&#x1EA5;p/Áp su&#x1EA5;t bõm nén" ) , TARGET_STRING ( "C" ) ,
0 , 0 , 0 } , { 61 , TARGET_STRING ( "Luanvancu/Bõm ngýng/Constant" ) ,
TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 62 , TARGET_STRING (
"Luanvancu/Bõm ngýng/Lýu lý&#x1EE3;ng ch&#x1EA5;t l&#x1ECF;ng" ) ,
TARGET_STRING ( "A" ) , 0 , 0 , 0 } , { 63 , TARGET_STRING (
"Luanvancu/Bõm ngýng/Lýu lý&#x1EE3;ng ch&#x1EA5;t l&#x1ECF;ng" ) ,
TARGET_STRING ( "C" ) , 0 , 0 , 0 } , { 64 , TARGET_STRING (
"Luanvancu/Bõm ngýng/Motor" ) , TARGET_STRING ( "A" ) , 0 , 2 , 0 } , { 65 ,
TARGET_STRING ( "Luanvancu/Bõm ngýng/Motor" ) , TARGET_STRING ( "C" ) , 0 , 3
, 0 } , { 66 , TARGET_STRING ( "Luanvancu/Bõm ngýng/Áp su&#x1EA5;t bõm nén" )
, TARGET_STRING ( "A" ) , 0 , 0 , 0 } , { 67 , TARGET_STRING (
"Luanvancu/Bõm ngýng/Áp su&#x1EA5;t bõm nén" ) , TARGET_STRING ( "C" ) , 0 ,
0 , 0 } , { 68 , TARGET_STRING (
"Luanvancu/B&#x1ED9; ph&#x1EAD;n ð&#x1ED1;t/V&#xF2;i ð&#x1ED1;t" ) ,
TARGET_STRING ( "A" ) , 0 , 0 , 0 } , { 69 , TARGET_STRING (
"Luanvancu/B&#x1ED9; ph&#x1EAD;n ð&#x1ED1;t/V&#xF2;i ð&#x1ED1;t" ) ,
TARGET_STRING ( "C" ) , 0 , 0 , 0 } , { 70 , TARGET_STRING (
"Luanvancu/Condense_Pump/Condense_Flow" ) , TARGET_STRING ( "A" ) , 0 , 0 , 0
} , { 71 , TARGET_STRING ( "Luanvancu/Condense_Pump/Condense_Flow" ) ,
TARGET_STRING ( "C" ) , 0 , 0 , 0 } , { 72 , TARGET_STRING (
"Luanvancu/Condense_Pump/Motor" ) , TARGET_STRING ( "A" ) , 0 , 2 , 0 } , {
73 , TARGET_STRING ( "Luanvancu/Condense_Pump/Motor" ) , TARGET_STRING ( "C"
) , 0 , 3 , 0 } , { 74 , TARGET_STRING ( "Luanvancu/Conveyor/Motor_1" ) ,
TARGET_STRING ( "A" ) , 0 , 2 , 0 } , { 75 , TARGET_STRING (
"Luanvancu/Conveyor/Motor_1" ) , TARGET_STRING ( "C" ) , 0 , 3 , 0 } , { 76 ,
TARGET_STRING ( "Luanvancu/Force_Fan/Heat_Power" ) , TARGET_STRING ( "A" ) ,
0 , 0 , 0 } , { 77 , TARGET_STRING ( "Luanvancu/Force_Fan/Heat_Power" ) ,
TARGET_STRING ( "C" ) , 0 , 0 , 0 } , { 78 , TARGET_STRING (
"Luanvancu/Force_Fan/Motor" ) , TARGET_STRING ( "A" ) , 0 , 2 , 0 } , { 79 ,
TARGET_STRING ( "Luanvancu/Force_Fan/Motor" ) , TARGET_STRING ( "C" ) , 0 , 3
, 0 } , { 80 , TARGET_STRING ( "Luanvancu/Force_Fan1/Heat_Power" ) ,
TARGET_STRING ( "A" ) , 0 , 0 , 0 } , { 81 , TARGET_STRING (
"Luanvancu/Force_Fan1/Heat_Power" ) , TARGET_STRING ( "C" ) , 0 , 0 , 0 } , {
82 , TARGET_STRING ( "Luanvancu/Force_Fan1/Motor" ) , TARGET_STRING ( "A" ) ,
0 , 2 , 0 } , { 83 , TARGET_STRING ( "Luanvancu/Force_Fan1/Motor" ) ,
TARGET_STRING ( "C" ) , 0 , 3 , 0 } , { 84 , TARGET_STRING (
"Luanvancu/Force_Fan2/Heat_Power" ) , TARGET_STRING ( "A" ) , 0 , 0 , 0 } , {
85 , TARGET_STRING ( "Luanvancu/Force_Fan2/Heat_Power" ) , TARGET_STRING (
"C" ) , 0 , 0 , 0 } , { 86 , TARGET_STRING ( "Luanvancu/Force_Fan2/Motor" ) ,
TARGET_STRING ( "A" ) , 0 , 2 , 0 } , { 87 , TARGET_STRING (
"Luanvancu/Force_Fan2/Motor" ) , TARGET_STRING ( "C" ) , 0 , 3 , 0 } , { 88 ,
TARGET_STRING ( "Luanvancu/Gia nhi&#x1EC7;t cao áp/Gain1" ) , TARGET_STRING (
"Gain" ) , 0 , 0 , 0 } , { 89 , TARGET_STRING (
"Luanvancu/Gia nhi&#x1EC7;t cao áp/Gain2" ) , TARGET_STRING ( "Gain" ) , 0 ,
0 , 0 } , { 90 , TARGET_STRING ( "Luanvancu/Gia nhi&#x1EC7;t cao áp/Gain3" )
, TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 91 , TARGET_STRING (
"Luanvancu/Gia nhi&#x1EC7;t cao áp/Switch" ) , TARGET_STRING ( "Threshold" )
, 0 , 0 , 0 } , { 92 , TARGET_STRING (
"Luanvancu/Gia nhi&#x1EC7;t cao áp/Switch1" ) , TARGET_STRING ( "Threshold" )
, 0 , 0 , 0 } , { 93 , TARGET_STRING (
"Luanvancu/Gia nhi&#x1EC7;t cao áp/Gia nhi&#x1EC7;t cao áp" ) , TARGET_STRING
( "A" ) , 0 , 0 , 0 } , { 94 , TARGET_STRING (
"Luanvancu/Gia nhi&#x1EC7;t cao áp/Gia nhi&#x1EC7;t cao áp" ) , TARGET_STRING
( "C" ) , 0 , 0 , 0 } , { 95 , TARGET_STRING (
"Luanvancu/Gia nhi&#x1EC7;t h&#x1EA1; áp/Gain1" ) , TARGET_STRING ( "Gain" )
, 0 , 0 , 0 } , { 96 , TARGET_STRING (
"Luanvancu/Gia nhi&#x1EC7;t h&#x1EA1; áp/Gain2" ) , TARGET_STRING ( "Gain" )
, 0 , 0 , 0 } , { 97 , TARGET_STRING (
"Luanvancu/Gia nhi&#x1EC7;t h&#x1EA1; áp/Gain3" ) , TARGET_STRING ( "Gain" )
, 0 , 0 , 0 } , { 98 , TARGET_STRING (
"Luanvancu/Gia nhi&#x1EC7;t h&#x1EA1; áp/Switch" ) , TARGET_STRING (
"Threshold" ) , 0 , 0 , 0 } , { 99 , TARGET_STRING (
"Luanvancu/Gia nhi&#x1EC7;t h&#x1EA1; áp/Switch1" ) , TARGET_STRING (
"Threshold" ) , 0 , 0 , 0 } , { 100 , TARGET_STRING (
"Luanvancu/Gia nhi&#x1EC7;t h&#x1EA1; áp/Gia nhi&#x1EC7;t h&#x1EA1; áp" ) ,
TARGET_STRING ( "A" ) , 0 , 0 , 0 } , { 101 , TARGET_STRING (
"Luanvancu/Gia nhi&#x1EC7;t h&#x1EA1; áp/Gia nhi&#x1EC7;t h&#x1EA1; áp" ) ,
TARGET_STRING ( "C" ) , 0 , 0 , 0 } , { 102 , TARGET_STRING (
"Luanvancu/L&#xF2; hõi/Saturation" ) , TARGET_STRING ( "UpperLimit" ) , 0 , 0
, 0 } , { 103 , TARGET_STRING ( "Luanvancu/L&#xF2; hõi/Saturation" ) ,
TARGET_STRING ( "LowerLimit" ) , 0 , 0 , 0 } , { 104 , TARGET_STRING (
"Luanvancu/L&#xF2; hõi/B&#x1ED9; hâm" ) , TARGET_STRING ( "A" ) , 0 , 0 , 0 }
, { 105 , TARGET_STRING ( "Luanvancu/L&#xF2; hõi/B&#x1ED9; hâm" ) ,
TARGET_STRING ( "C" ) , 0 , 0 , 0 } , { 106 , TARGET_STRING (
"Luanvancu/Ð&#x1ED9;ng cõ/Ð&#x1ED9;ng cõ AC" ) , TARGET_STRING ( "A" ) , 0 ,
2 , 0 } , { 107 , TARGET_STRING (
"Luanvancu/Ð&#x1ED9;ng cõ/Ð&#x1ED9;ng cõ AC" ) , TARGET_STRING ( "C" ) , 0 ,
3 , 0 } , { 108 , TARGET_STRING (
"Luanvancu/L&#xF2; hõi/B&#x1ED9; quá nhi&#x1EC7;t/Gain3" ) , TARGET_STRING (
"Gain" ) , 0 , 0 , 0 } , { 109 , TARGET_STRING (
"Luanvancu/L&#xF2; hõi/B&#x1ED9; quá nhi&#x1EC7;t/Overheated_Pressure" ) ,
TARGET_STRING ( "A" ) , 0 , 0 , 0 } , { 110 , TARGET_STRING (
"Luanvancu/L&#xF2; hõi/B&#x1ED9; quá nhi&#x1EC7;t/Overheated_Pressure" ) ,
TARGET_STRING ( "C" ) , 0 , 0 , 0 } , { 111 , TARGET_STRING (
"Luanvancu/L&#xF2; hõi/B&#x1ED9; quá nhi&#x1EC7;t/Water_Heat_Absorbing" ) ,
TARGET_STRING ( "A" ) , 0 , 0 , 0 } , { 112 , TARGET_STRING (
"Luanvancu/L&#xF2; hõi/B&#x1ED9; quá nhi&#x1EC7;t/Water_Heat_Absorbing" ) ,
TARGET_STRING ( "C" ) , 0 , 0 , 0 } , { 113 , TARGET_STRING (
"Luanvancu/Tua bin/Tua bin-Nhi&#x1EC7;t/B&#x1ED9; tái s&#x1EA5;y" ) ,
TARGET_STRING ( "A" ) , 0 , 0 , 0 } , { 114 , TARGET_STRING (
"Luanvancu/Tua bin/Tua bin-Nhi&#x1EC7;t/B&#x1ED9; tái s&#x1EA5;y" ) ,
TARGET_STRING ( "C" ) , 0 , 0 , 0 } , { 115 , TARGET_STRING (
"Luanvancu/Tua bin/Tua bin-Nhi&#x1EC7;t/Tua bin cao áp" ) , TARGET_STRING (
"A" ) , 0 , 0 , 0 } , { 116 , TARGET_STRING (
"Luanvancu/Tua bin/Tua bin-Nhi&#x1EC7;t/Tua bin cao áp" ) , TARGET_STRING (
"C" ) , 0 , 0 , 0 } , { 117 , TARGET_STRING (
"Luanvancu/Tua bin/Tua bin-Nhi&#x1EC7;t/Tua bin h&#x1EA1; áp" ) ,
TARGET_STRING ( "A" ) , 0 , 0 , 0 } , { 118 , TARGET_STRING (
"Luanvancu/Tua bin/Tua bin-Nhi&#x1EC7;t/Tua bin h&#x1EA1; áp" ) ,
TARGET_STRING ( "C" ) , 0 , 0 , 0 } , { 119 , TARGET_STRING (
"Luanvancu/Tua bin/Tua bin-Nhi&#x1EC7;t/Tua bin trung áp" ) , TARGET_STRING (
"A" ) , 0 , 0 , 0 } , { 120 , TARGET_STRING (
"Luanvancu/Tua bin/Tua bin-Nhi&#x1EC7;t/Tua bin trung áp" ) , TARGET_STRING (
"C" ) , 0 , 0 , 0 } , { 121 , TARGET_STRING (
 "Luanvancu/Tua bin/Tua bin-T&#x1ED1;c ð&#x1ED9;/Ð&#x1ED9; l&#x1EE3;i nhi&#x1EC7;t-t&#x1ED1;c ð&#x1ED9;"
) , TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 122 , TARGET_STRING (
"Luanvancu/Tua bin/Tua bin-T&#x1ED1;c ð&#x1ED9;/T&#x1EC9; l&#x1EC7; cao áp" )
, TARGET_STRING ( "A" ) , 0 , 0 , 0 } , { 123 , TARGET_STRING (
"Luanvancu/Tua bin/Tua bin-T&#x1ED1;c ð&#x1ED9;/T&#x1EC9; l&#x1EC7; cao áp" )
, TARGET_STRING ( "C" ) , 0 , 0 , 0 } , { 124 , TARGET_STRING (
 "Luanvancu/Tua bin/Tua bin-T&#x1ED1;c ð&#x1ED9;/T&#x1EC9; l&#x1EC7; h&#x1EA1; áp"
) , TARGET_STRING ( "A" ) , 0 , 0 , 0 } , { 125 , TARGET_STRING (
 "Luanvancu/Tua bin/Tua bin-T&#x1ED1;c ð&#x1ED9;/T&#x1EC9; l&#x1EC7; h&#x1EA1; áp"
) , TARGET_STRING ( "C" ) , 0 , 0 , 0 } , { 126 , TARGET_STRING (
"Luanvancu/Tua bin/Tua bin-T&#x1ED1;c ð&#x1ED9;/T&#x1EC9; l&#x1EC7; trung áp"
) , TARGET_STRING ( "A" ) , 0 , 0 , 0 } , { 127 , TARGET_STRING (
"Luanvancu/Tua bin/Tua bin-T&#x1ED1;c ð&#x1ED9;/T&#x1EC9; l&#x1EC7; trung áp"
) , TARGET_STRING ( "C" ) , 0 , 0 , 0 } , { 128 , TARGET_STRING (
"Luanvancu/Tua bin/Tua bin-Áp/Tua bin cao áp" ) , TARGET_STRING ( "A" ) , 0 ,
0 , 0 } , { 129 , TARGET_STRING (
"Luanvancu/Tua bin/Tua bin-Áp/Tua bin cao áp" ) , TARGET_STRING ( "C" ) , 0 ,
0 , 0 } , { 130 , TARGET_STRING (
"Luanvancu/Tua bin/Tua bin-Áp/Tua bin h&#x1EA1; áp" ) , TARGET_STRING ( "A" )
, 0 , 0 , 0 } , { 131 , TARGET_STRING (
"Luanvancu/Tua bin/Tua bin-Áp/Tua bin h&#x1EA1; áp" ) , TARGET_STRING ( "C" )
, 0 , 0 , 0 } , { 132 , TARGET_STRING (
"Luanvancu/Tua bin/Tua bin-Áp/Tua bin trung áp" ) , TARGET_STRING ( "A" ) , 0
, 0 , 0 } , { 133 , TARGET_STRING (
"Luanvancu/Tua bin/Tua bin-Áp/Tua bin trung áp" ) , TARGET_STRING ( "C" ) , 0
, 0 , 0 } , { 0 , ( NULL ) , ( NULL ) , 0 , 0 , 0 } } ; static const
rtwCAPI_ModelParameters rtModelParameters [ ] = { { 0 , ( NULL ) , 0 , 0 , 0
} } ;
#ifndef HOST_CAPI_BUILD
static void * rtDataAddrMap [ ] = { & rtB . ms0vucqlor , & rtB . lqhuiqwr05 ,
& rtB . orrmcemgc5 , & rtB . fyo1xeq1wv , & rtB . oagbppphto , & rtB .
getjyqkigw , & rtB . h0kzcipt5k , & rtB . dbs5szu3hu , & rtB . iesin1c131 , &
rtB . bszztyqh40 , & rtB . jnen5c5srs , & rtB . ihxxraqvfh , & rtB .
p2bs4tz44d , & rtB . aoca5q4ss2 , & rtB . ekiqmr4xcv , & rtB . jpo2be3j0l , &
rtB . fio2xdkn1t , & rtB . exaaxqgjgy , & rtB . phn44qhkql , & rtB .
kcbltgbeur , & rtB . omytbhyzix , & rtB . eoa4dk2j0w , & rtB . ft5o21avnp , &
rtB . htwqr5zjg1 , & rtB . j0mkgu2zq5 , & rtB . cchttyvd1o , & rtB .
fq23gpnbhd , & rtB . icvzkup4wn , & rtB . b2pbu1n1pm , & rtB . nnhqtkzwq5 , &
rtB . ho5gmcpx2t , & rtB . o2l0ex0xfl , & rtB . on3fvwdnfd , & rtB .
nqcqxfnc1r , & rtB . nruvz0bur4 , & rtB . isyon0iaye , & rtP .
SliderGain_gain , & rtP . SliderGain1_gain , & rtP . Constant1_Value , & rtP
. Constant2_Value , & rtP . Constant3_Value , & rtP . Constant4_Value , & rtP
. Constant5_Value , & rtP . Constant6_Value , & rtP . Constant7_Value , & rtP
. Constant8_Value , & rtP . Constant9_Value , & rtP . SFunction_P1 [ 0 ] , &
rtP . SFunction_P2 , & rtP . ManualSwitch_CurrentSetting , & rtP .
Gianhitcaop_A , & rtP . Gianhitcaop_C , & rtP . Ngngt_A , & rtP . Ngngt_C , &
rtP . Constant_Value_gi4rxypddg , & rtP . Lulngchtlng_A_lttlvilq1r , & rtP .
Lulngchtlng_C_byw0yw2g0l , & rtP . Motor_A [ 0 ] , & rtP . Motor_C [ 0 ] , &
rtP . psutbmnn_A_krrl5senh5 , & rtP . psutbmnn_C_fpy55gg1x5 , & rtP .
Constant_Value , & rtP . Lulngchtlng_A , & rtP . Lulngchtlng_C , & rtP .
Motor_A_mm1y0efbc2 [ 0 ] , & rtP . Motor_C_bulm522rai [ 0 ] , & rtP .
psutbmnn_A , & rtP . psutbmnn_C , & rtP . Vit_A , & rtP . Vit_C , & rtP .
Condense_Flow_A , & rtP . Condense_Flow_C , & rtP . Motor_A_d5m4c15oua [ 0 ]
, & rtP . Motor_C_nowl0zxxl1 [ 0 ] , & rtP . Motor_1_A [ 0 ] , & rtP .
Motor_1_C [ 0 ] , & rtP . Heat_Power_A , & rtP . Heat_Power_C , & rtP .
Motor_A_bv5eyzqlpk [ 0 ] , & rtP . Motor_C_khazapi3pb [ 0 ] , & rtP .
Heat_Power_A_egs5tnb4gq , & rtP . Heat_Power_C_n44yvipdtx , & rtP .
Motor_A_adem45aw5v [ 0 ] , & rtP . Motor_C_eszjmj2kpa [ 0 ] , & rtP .
Heat_Power_A_mwhpd1vf2d , & rtP . Heat_Power_C_jpuwdm244t , & rtP .
Motor_A_eeuscavczf [ 0 ] , & rtP . Motor_C_b3zi30mm3g [ 0 ] , & rtP .
Gain1_Gain_ajrshsszpr , & rtP . Gain2_Gain_dt33lrcogy , & rtP . Gain3_Gain ,
& rtP . Switch_Threshold_bfiwed5r3a , & rtP . Switch1_Threshold , & rtP .
Gianhitcaop_A_gp1isrh1zt , & rtP . Gianhitcaop_C_cuxjfl0bny , & rtP .
Gain1_Gain , & rtP . Gain2_Gain , & rtP . Gain3_Gain_mhi1gc12x1 , & rtP .
Switch_Threshold , & rtP . Switch1_Threshold_gztv0arq0y , & rtP . Gianhithp_A
, & rtP . Gianhithp_C , & rtP . Saturation_UpperSat , & rtP .
Saturation_LowerSat , & rtP . Bhm_A , & rtP . Bhm_C , & rtP . ngcAC_A [ 0 ] ,
& rtP . ngcAC_C [ 0 ] , & rtP . Gain3_Gain_nyi3yuqbkz , & rtP .
Overheated_Pressure_A , & rtP . Overheated_Pressure_C , & rtP .
Water_Heat_Absorbing_A , & rtP . Water_Heat_Absorbing_C , & rtP . Btisy_A , &
rtP . Btisy_C , & rtP . Tuabincaop_A , & rtP . Tuabincaop_C , & rtP .
Tuabinhp_A , & rtP . Tuabinhp_C , & rtP . Tuabintrungp_A , & rtP .
Tuabintrungp_C , & rtP . linhittc_Gain , & rtP . Tlcaop_A , & rtP . Tlcaop_C
, & rtP . Tlhp_A , & rtP . Tlhp_C , & rtP . Tltrungp_A , & rtP . Tltrungp_C ,
& rtP . Tuabincaop_A_nvs4biyz0y , & rtP . Tuabincaop_C_pab1ysi2qy , & rtP .
Tuabinhp_A_p4fqdq0nyf , & rtP . Tuabinhp_C_iunwv5jncy , & rtP .
Tuabintrungp_A_ir4nhbzr3q , & rtP . Tuabintrungp_C_ijxomeac24 , } ; static
int32_T * rtVarDimsAddrMap [ ] = { ( NULL ) } ;
#endif
static TARGET_CONST rtwCAPI_DataTypeMap rtDataTypeMap [ ] = { { "double" ,
"real_T" , 0 , 0 , sizeof ( real_T ) , SS_DOUBLE , 0 , 0 } , {
"unsigned char" , "uint8_T" , 0 , 0 , sizeof ( uint8_T ) , SS_UINT8 , 0 , 0 }
} ;
#ifdef HOST_CAPI_BUILD
#undef sizeof
#endif
static TARGET_CONST rtwCAPI_ElementMap rtElementMap [ ] = { { ( NULL ) , 0 ,
0 , 0 , 0 } , } ; static const rtwCAPI_DimensionMap rtDimensionMap [ ] = { {
rtwCAPI_SCALAR , 0 , 2 , 0 } , { rtwCAPI_VECTOR , 2 , 2 , 0 } , {
rtwCAPI_VECTOR , 4 , 2 , 0 } , { rtwCAPI_VECTOR , 6 , 2 , 0 } } ; static
const uint_T rtDimensionArray [ ] = { 1 , 1 , 1 , 6 , 2 , 1 , 1 , 2 } ;
static const real_T rtcapiStoredFloats [ ] = { 0.09 , 0.0 } ; static const
rtwCAPI_FixPtMap rtFixPtMap [ ] = { { ( NULL ) , ( NULL ) ,
rtwCAPI_FIX_RESERVED , 0 , 0 , 0 } , } ; static const rtwCAPI_SampleTimeMap
rtSampleTimeMap [ ] = { { ( const void * ) & rtcapiStoredFloats [ 0 ] , (
const void * ) & rtcapiStoredFloats [ 1 ] , 1 , 0 } , { ( const void * ) &
rtcapiStoredFloats [ 1 ] , ( const void * ) & rtcapiStoredFloats [ 1 ] , 0 ,
0 } , { ( NULL ) , ( NULL ) , 2 , 0 } } ; static
rtwCAPI_ModelMappingStaticInfo mmiStatic = { { rtBlockSignals , 36 , ( NULL )
, 0 , ( NULL ) , 0 } , { rtBlockParameters , 98 , rtModelParameters , 0 } , {
( NULL ) , 0 } , { rtDataTypeMap , rtDimensionMap , rtFixPtMap , rtElementMap
, rtSampleTimeMap , rtDimensionArray } , "float" , { 499643481U , 3733294652U
, 3467698729U , 550543215U } , ( NULL ) , 0 , 0 } ; const
rtwCAPI_ModelMappingStaticInfo * Luanvancu_GetCAPIStaticMap ( void ) { return
& mmiStatic ; }
#ifndef HOST_CAPI_BUILD
void Luanvancu_InitializeDataMapInfo ( void ) { rtwCAPI_SetVersion ( ( *
rt_dataMapInfoPtr ) . mmi , 1 ) ; rtwCAPI_SetStaticMap ( ( *
rt_dataMapInfoPtr ) . mmi , & mmiStatic ) ; rtwCAPI_SetLoggingStaticMap ( ( *
rt_dataMapInfoPtr ) . mmi , ( NULL ) ) ; rtwCAPI_SetDataAddressMap ( ( *
rt_dataMapInfoPtr ) . mmi , rtDataAddrMap ) ; rtwCAPI_SetVarDimsAddressMap (
( * rt_dataMapInfoPtr ) . mmi , rtVarDimsAddrMap ) ;
rtwCAPI_SetInstanceLoggingInfo ( ( * rt_dataMapInfoPtr ) . mmi , ( NULL ) ) ;
rtwCAPI_SetChildMMIArray ( ( * rt_dataMapInfoPtr ) . mmi , ( NULL ) ) ;
rtwCAPI_SetChildMMIArrayLen ( ( * rt_dataMapInfoPtr ) . mmi , 0 ) ; }
#else
#ifdef __cplusplus
extern "C" {
#endif
void Luanvancu_host_InitializeDataMapInfo ( Luanvancu_host_DataMapInfo_T *
dataMap , const char * path ) { rtwCAPI_SetVersion ( dataMap -> mmi , 1 ) ;
rtwCAPI_SetStaticMap ( dataMap -> mmi , & mmiStatic ) ;
rtwCAPI_SetDataAddressMap ( dataMap -> mmi , NULL ) ;
rtwCAPI_SetVarDimsAddressMap ( dataMap -> mmi , NULL ) ; rtwCAPI_SetPath (
dataMap -> mmi , path ) ; rtwCAPI_SetFullPath ( dataMap -> mmi , NULL ) ;
rtwCAPI_SetChildMMIArray ( dataMap -> mmi , ( NULL ) ) ;
rtwCAPI_SetChildMMIArrayLen ( dataMap -> mmi , 0 ) ; }
#ifdef __cplusplus
}
#endif
#endif
