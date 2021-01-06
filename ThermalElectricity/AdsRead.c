#define NumVar 6
#define Offset 168

#define S_FUNCTION_NAME  AdsRead
#define S_FUNCTION_LEVEL 2
#include "simstruc.h"
#include "matrix.h"
#include "TcAdsDef.h"
#include "TcAdsAPI.h"

long      nErr, nPort;
AmsAddr   Addr;
PAmsAddr  pAddr = &Addr;
double    dwData[NumVar];

#define IS_PARAM_DOUBLE(pVal) (mxIsNumeric(pVal) && !mxIsLogical(pVal) &&\
!mxIsEmpty(pVal) && !mxIsSparse(pVal) && !mxIsComplex(pVal) && mxIsDouble(pVal))
#define MDL_CHECK_PARAMETERS
#if defined(MDL_CHECK_PARAMETERS)  && defined(MATLAB_MEX_FILE)
/*
 * Check to make sure that each parameter is feasible and positive
 */
static void mdlCheckParameters(SimStruct *S)
{
    const mxArray *pVal0 = ssGetSFcnParam(S,0);
    const mxArray *pVal1 = ssGetSFcnParam(S,1);

    if ( mxGetNumberOfElements(ssGetSFcnParam(S,0)) != 6 || !IS_PARAM_DOUBLE(pVal0)) {
        ssSetErrorStatus(S, "Number of Parameters to S-function must be six");
        return;
    } 
//     else if (mxGetPr(ssGetSFcnParam(S,0))[0] < 0) {
//         ssSetErrorStatus(S, "Parameter to S-function must be non-negative");
//         return;
//     }
    if (mxGetNumberOfElements(ssGetSFcnParam(S,1)) != 1 || !IS_PARAM_DOUBLE(pVal1)) {
        ssSetErrorStatus(S, "Parameter to S-function must be a scalar");
        return;
    } 
    else if (mxGetPr(ssGetSFcnParam(S,1))[0] < 0) {
        ssSetErrorStatus(S, "Parameter to S-function must be non-negative");
        return;
    } 
}
#endif

static void mdlInitializeSizes(SimStruct *S)
{
    ssSetNumSFcnParams(S, 2);
    if (ssGetNumSFcnParams(S) != ssGetSFcnParamsCount(S)) {
        return; /* Parameter mismatch reported by the Simulink engine*/
    }
    
    if (!ssSetNumInputPorts(S, 1)) return;
    ssSetInputPortWidth(S, 0, DYNAMICALLY_SIZED);
    ssSetInputPortDirectFeedThrough(S, 0, 1);

    if (!ssSetNumOutputPorts(S,NumVar)) return;
    for (int_T i=0; i<NumVar; i++)
    {
        ssSetOutputPortWidth(S, i, DYNAMICALLY_SIZED);
    }

    ssSetNumSampleTimes(S, 1);

    /* Take care when specifying exception free code - see sfuntmpl.doc */
    ssSetOptions(S, SS_OPTION_EXCEPTION_FREE_CODE);
    
    const real_T *NetID = ( mxGetPr(ssGetSFcnParam(S,0)) );
    const real_T Port = ( mxGetPr(ssGetSFcnParam(S,1)) )[0];
    
    nPort = AdsPortOpen();
    for (int_T i=0; i<6; i++)
    {
        pAddr->netId.b[i] = (uint8_T)*(NetID+i);    //nErr = AdsGetLocalAddress(pAddr);
    }
 	pAddr->port = (uint16_T)Port;         //851;
}

static void mdlInitializeSampleTimes(SimStruct *S)
{
    ssSetSampleTime(S, 0, INHERITED_SAMPLE_TIME);
    ssSetOffsetTime(S, 0, 0.0);
}

static void mdlOutputs(SimStruct *S, int_T tid)
{
    InputRealPtrsType uPtrs = ssGetInputPortRealSignalPtrs(S,0);
    real_T *y[NumVar];
    for (int_T i=0;i<NumVar;i++)
    {
        y[i] = ssGetOutputPortRealSignal(S,i);
    }

    nErr = AdsSyncReadReq(pAddr, 0x4020, Offset, 8*NumVar, dwData);
    for (int_T i=0; i<NumVar; i++) {
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