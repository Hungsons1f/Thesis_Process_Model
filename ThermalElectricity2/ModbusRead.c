#define S_FUNCTION_NAME  ModbusRead
#define S_FUNCTION_LEVEL 2
#include "simstruc.h"
#include "matrix.h"
#include "modbus.h"

#define Address (12288+21*2)
#define NumVar 10

modbus_t *mb;
uint16_t tab_reg[NumVar*2];

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
    real_T *y[NumVar];
    for (int_T i=0;i<NumVar;i++)
    {
        y[i] = ssGetOutputPortRealSignal(S,i);
    }

    modbus_read_registers(mb, Address, NumVar*2, tab_reg);
    
    for (int_T i=0; i<NumVar; i++) {
        float a = modbus_get_float(tab_reg + i * 2);
        *y[i] = a;//(real_T)tab_reg[i];
    }
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