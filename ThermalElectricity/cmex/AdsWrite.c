#define NumVar 1
#define Offset 0

#define S_FUNCTION_NAME  AdsWrite
#define S_FUNCTION_LEVEL 2
#include "simstruc.h"
#include "TcAdsDef.h"
#include "TcAdsAPI.h"

long      nErr, nPort;
AmsAddr   Addr;
PAmsAddr  pAddr = &Addr;
double    dwData[NumVar];

static void mdlInitializeSizes(SimStruct *S)
{
    ssSetNumSFcnParams(S, 0);
    if (ssGetNumSFcnParams(S) != ssGetSFcnParamsCount(S)) {
        return; /* Parameter mismatch reported by the Simulink engine*/
    }

    if (!ssSetNumInputPorts(S, NumVar)) return;
    for (int_T i=0; i<NumVar; i++)
    {
    ssSetInputPortWidth(S, i, DYNAMICALLY_SIZED);
    ssSetInputPortDirectFeedThrough(S, i, 1);
    }
    
    if (!ssSetNumOutputPorts(S,0)) return;

    ssSetNumSampleTimes(S, 1);

    /* Take care when specifying exception free code - see sfuntmpl.doc */
    ssSetOptions(S, SS_OPTION_EXCEPTION_FREE_CODE);
    
    nPort = AdsPortOpen();
	nErr = AdsGetLocalAddress(pAddr);
	pAddr->port = 851;
}
static void mdlInitializeSampleTimes(SimStruct *S)
{
    ssSetSampleTime(S, 0, INHERITED_SAMPLE_TIME);
    ssSetOffsetTime(S, 0, 0.0);
}
static void mdlOutputs(SimStruct *S, int_T tid)
{
    InputRealPtrsType uPtrs = ssGetInputPortRealSignalPtrs(S,0);
    for (int_T i=0;i< NumVar;i++)
    {
        dwData[i] = *uPtrs[i];
    }
    nErr = AdsSyncWriteReq(pAddr, 0x4020, Offset, 8*NumVar, dwData);
}

static void mdlTerminate(SimStruct *S){
    nErr = AdsPortClose();
}

#ifdef MATLAB_MEX_FILE /* Is this file being compiled as a MEX-file? */
#include "simulink.c" /* MEX-file interface mechanism */
#else
#include "cg_sfun.h" /* Code generation registration function */
#endif