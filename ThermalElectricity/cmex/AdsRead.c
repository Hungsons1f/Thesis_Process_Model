#define S_FUNCTION_NAME  AdsRead
#define S_FUNCTION_LEVEL 2
#include "simstruc.h"
#include "TcAdsDef.h"
#include "TcAdsAPI.h"

long      nErr, nPort;
AmsAddr   Addr;
PAmsAddr  pAddr = &Addr;
double    dwData[7];

static void mdlInitializeSizes(SimStruct *S)
{
    ssSetNumSFcnParams(S, 0);
    if (ssGetNumSFcnParams(S) != ssGetSFcnParamsCount(S)) {
        return; /* Parameter mismatch reported by the Simulink engine*/
    }

    if (!ssSetNumInputPorts(S, 1)) return;
    ssSetInputPortWidth(S, 0, DYNAMICALLY_SIZED);
    ssSetInputPortDirectFeedThrough(S, 0, 1);

    if (!ssSetNumOutputPorts(S,7)) return;
    ssSetOutputPortWidth(S, 0, DYNAMICALLY_SIZED);
    ssSetOutputPortWidth(S, 1, DYNAMICALLY_SIZED);
    ssSetOutputPortWidth(S, 2, DYNAMICALLY_SIZED);
    ssSetOutputPortWidth(S, 3, DYNAMICALLY_SIZED);
    ssSetOutputPortWidth(S, 4, DYNAMICALLY_SIZED);
    ssSetOutputPortWidth(S, 5, DYNAMICALLY_SIZED);
    ssSetOutputPortWidth(S, 6, DYNAMICALLY_SIZED);

    ssSetNumSampleTimes(S, 1);

    /* Take care when specifying exception free code - see sfuntmpl.doc */
    ssSetOptions(S, SS_OPTION_EXCEPTION_FREE_CODE);
        
    nPort = AdsPortOpen();
	nErr = AdsGetLocalAddress(pAddr);
	pAddr->port = 851;         //851;
}
static void mdlInitializeSampleTimes(SimStruct *S)
{
    ssSetSampleTime(S, 0, INHERITED_SAMPLE_TIME);
    ssSetOffsetTime(S, 0, 0.0);
}
static void mdlOutputs(SimStruct *S, int_T tid)
{
    int_T i;
    InputRealPtrsType uPtrs = ssGetInputPortRealSignalPtrs(S,0);
    real_T *y[7];
    for (i=0;i<7;i++)
    {
        y[i] = ssGetOutputPortRealSignal(S,i);
    }

    nErr = AdsSyncReadReq(pAddr, 0x4040, 385072, 56, dwData);
    for (i=0; i<7; i++) {
        *y[i] = dwData[i];
    }
}

static void mdlTerminate(SimStruct *S){
    nErr = AdsPortClose();
}

#ifdef MATLAB_MEX_FILE /* Is this file being compiled as a MEX-file? */
#include "simulink.c" /* MEX-file interface mechanism */
#else
#include "cg_sfun.h" /* Code generation registration function */
#endif