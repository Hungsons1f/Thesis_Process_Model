#define S_FUNCTION_NAME  ModbusWrite
#define S_FUNCTION_LEVEL 2
#include "simstruc.h"
#include "matrix.h"
#include "modbus.h"

#define Address 99
#define NumVar 1

modbus_t *mb;
uint16_t tab_reg[NumVar*2];

static void mdlInitializeSizes(SimStruct *S)
{
    ssSetNumSFcnParams(S, 2);
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
   
    
    char ip[20] ;
    int_T buflen = mxGetN((ssGetSFcnParam(S, 0)))*sizeof(mxChar)+1;
    mxGetString((ssGetSFcnParam(S, 0)), ip,buflen);   
    const real_T Port = ( mxGetPr(ssGetSFcnParam(S,1)) )[0];
    
    mb = modbus_new_tcp(ip, (uint16_T)Port);
    modbus_connect(mb);
    modbus_set_slave(mb, 1);
}

static void mdlInitializeSampleTimes(SimStruct *S)
{
    ssSetSampleTime(S, 0, INHERITED_SAMPLE_TIME);
    ssSetOffsetTime(S, 0, 0.0);
}

static void mdlOutputs(SimStruct *S, int_T tid)
{
    InputRealPtrsType uPtrs = ssGetInputPortRealSignalPtrs(S,0);
    for (int_T i=0;i<NumVar;i++)
    {
        modbus_set_float((float)*uPtrs[i],tab_reg + i * 2);
    }
    modbus_write_registers(mb, Address, NumVar*2, tab_reg);
}

static void mdlTerminate(SimStruct *S){
    modbus_close(mb);
    modbus_free(mb);
}

#ifdef MATLAB_MEX_FILE /* Is this file being compiled as a MEX-file? */
#include "simulink.c" /* MEX-file interface mechanism */
#else
#include "cg_sfun.h" /* Code generation registration function */
#endif