/********************************************************************************
 * DO NOT EDIT!
 * AUTOMATICALLY GENERATED
 * DESCRIPTION:
 *   Implements S-Function API
 ********************************************************************************/

#include "esdl_defines.h"
#include "simstruc.h"
#include "asimulinkManager.h"
#include "asimulinkHelper.h"

#ifdef ESDL_DEFINE_OUTPUT_BUS
#include "esdl_local_measurements.h"
#endif

#ifdef __cplusplus
extern "C" {
#endif

#ifdef ESDL_ENABLE_CALIBRATION
#define MDL_CHECK_PARAMETERS
static void mdlCheckParameters(SimStruct *S) {
    for (int i = 0; i < simulinkManager.numberOfCharacteristisc; i++) {
        const mxArray* parameter = ssGetSFcnParam(S,i);
        const asimulinkVariableEntry entry = simulinkManager.characteristics[i];
        if (mxIsEmpty(parameter) ||
            mxIsSparse(parameter) ||
            mxIsComplex(parameter)) {
            ssSetErrorStatus(S,"Parameters must be real finite vectors.");
            return;
        }
        if (!checkDataType(entry, parameter)) {
            ssSetErrorStatus(S,"Mismatch in data types.");
            return;
        }
    }
}
#endif

static void mdlInitializeSizes(SimStruct *S) {
    // Initialize the instance tree to get the references to the visible elements.
    asimulinkReferencedPointer* referencedPointers = initSimulinkReferences(ESDL_NUMBER_STATIC_ELEMENTS, ESDL_NUMBER_ELEMENTS);
    initReferencedPointer(referencedPointers);
    ssSetUserData(S, referencedPointers);

    #ifdef ESDL_ENABLE_CALIBRATION
    ssSetNumSFcnParams(S, simulinkManager.numberOfCharacteristisc);

    if (ssGetNumSFcnParams(S) == ssGetSFcnParamsCount(S)) {
        mdlCheckParameters(S);
        if (ssGetErrorStatus(S) != NULL) {
            return;
        }
    } else {
        // Parameter mismatch will be reported by Simulink.
        return; 
    }
    #endif

    // Initialize input ports.
    if (!ssSetNumInputPorts(S, simulinkManager.numberOfInputPorts)) {
        ssSetErrorStatus(S, "Number of input ports not defined.\nSee command window for detailed information.");
        return;
    }

    for (int i = 0; i < simulinkManager.numberOfInputPorts; ++i) {
        setInputPort(S, i, simulinkManager.inputPorts + i);
        ssSetInputPortDirectFeedThrough(S, i, 1);
    }

    // Initialize output ports.
    int totalNumberOfOutputPorts = simulinkManager.numberOfOutputPorts;
	#ifdef ESDL_DEFINE_OUTPUT_BUS
		++totalNumberOfOutputPorts;
	#endif
    if (!ssSetNumOutputPorts(S, totalNumberOfOutputPorts)) {
        ssSetErrorStatus(S, "Number of output ports not defined.\nSee command window for detailed information.");
        return;
    }

    // Initialize output messages.
    for (int i = 0; i < simulinkManager.numberOfOutputPorts; ++i) {
        setOutputPort(S, i, simulinkManager.outputPorts + i);
    }

    #ifdef ESDL_DEFINE_OUTPUT_BUS
    int busIndex = simulinkManager.numberOfOutputPorts;
    
    ssSetBusOutputObjectName(S, busIndex, (void*) "LocalMeasurements" ESDL_PROJECT_NAME);
    ssSetOutputPortWidth(S, busIndex, 1);
    ssSetOutputPortComplexSignal(S, 1, COMPLEX_NO);
    ssSetBusOutputAsStruct(S, busIndex, 1);
    ssSetOutputPortBusMode(S, busIndex, SL_BUS_MODE);
    
    if (ssGetSimMode(S) != SS_SIMMODE_SIZES_CALL_ONLY) {
        DTypeId dataTypeIdReg;
        ssRegisterTypeFromNamedObject(S, "LocalMeasurements" ESDL_PROJECT_NAME, &dataTypeIdReg);
    
        if(dataTypeIdReg == INVALID_DTYPE_ID) {
            ssSetErrorStatus(S, "Data type for bus structure not defined.");
            return;
        }
    
        ssSetOutputPortDataType(S, busIndex, dataTypeIdReg);
    }
    
    if (!ssSetNumDWork(S, 0)) {
        ssSetErrorStatus(S, "Error at 'ssSetNumDWork'.");
        return;
    }
    #endif

    // Specify the sim state compliance to be same as a built-in block.
    ssSetNumSampleTimes(S, USE_DEFAULT_SIM_STATE);
    ssSetOptions(S, SS_OPTION_WORKS_WITH_CODE_REUSE | SS_OPTION_USE_TLC_WITH_ACCELERATOR | SS_OPTION_CALL_TERMINATE_ON_EXIT);
}

static void mdlInitializeSampleTimes(SimStruct *S) {
    ssSetSampleTime(S, 0, ESDL_STEP_SIZE);
    ssSetOffsetTime(S, 0, 0.0);
}

#ifdef ESDL_ENABLE_CALIBRATION
#define MDL_INITIALIZE_CONDITIONS
static void mdlInitializeConditions(SimStruct *S) {
    asimulinkReferencedPointer* referencedPointers = (asimulinkReferencedPointer*)ssGetUserData(S);

    for (int i = 0; i < simulinkManager.numberOfCharacteristisc; i++) {
        const mxArray* parameter = ssGetSFcnParam(S,i);
        const asimulinkVariableEntry entry = simulinkManager.characteristics[i];
        void *modelPointer = getReferencedPointer(referencedPointers, entry.reference);

        copyMatlabParametersToModel(entry, modelPointer, mxGetData(parameter));
    }
}
#endif

#define MDL_START
static void mdlStart(SimStruct *S) {
    for (int i = 0; i < simulinkManager.numberOfTasks; ++i) {
        ASIMULINK_NS(InitTaskEntry)(simulinkManager.tasks[i], 0.0);
    }

    simulinkManager.startup();
}

static void mdlOutputs(SimStruct *S, int_T tid) {
    double t = ssGetTaskTime(S,0);
    asimulinkReferencedPointer* referencedPointers = (asimulinkReferencedPointer*)ssGetUserData(S);

    // Copy input messages.
    for (int i = 0; i < simulinkManager.numberOfInputPorts; ++i) {
        asimulinkVariableEntry entry = simulinkManager.inputPorts[i];
        void* reference = getReferencedPointer(referencedPointers, entry.reference);

        copyMatlabInputToModelInput(ssGetInputPortSignalPtrs(S, i), reference, entry.typeId);
    }

    // Call tasks.
    for (int i = 0; i < simulinkManager.numberOfTasks; ++i) {
        ASIMULINK_NS(ScheduleTask)(&simulinkManager.tasks[i], t);
    }

    // Copy output messages.
    for (int i = 0; i < simulinkManager.numberOfOutputPorts; ++i) {
        asimulinkVariableEntry entry = simulinkManager.outputPorts[i];
        void* reference = getReferencedPointer(referencedPointers, entry.reference);

        copyModelOutputToMatlabOutput(reference, ssGetOutputPortSignal(S, i), ssGetOutputPortWidth(S, i), entry.typeId);
    }

    #ifdef ESDL_DEFINE_OUTPUT_BUS
    // Copy visible model variables.
    int busIndex = simulinkManager.numberOfOutputPorts;
    char* pMatlab = (char *)ssGetOutputPortSignal(S, busIndex);
    DTypeId busType = ssGetOutputPortDataType(S, busIndex);

    for(int i = 0; i < simulinkManager.numberOfOutputVariables; ++i) {
        char *pElement = (pMatlab + ssGetBusElementOffset(S, busType, i));
        asimulinkVariableEntry entry = simulinkManager.outputVariables[i];
        void* reference = getReferencedPointer(referencedPointers, entry.reference);

        copyModelOutputToMatlabOutput(reference, pElement, entry.numberOfElements, entry.typeId);
    }
    #endif
}

static void mdlTerminate(SimStruct *S) {
    simulinkManager.shutdown();
    releaseSimulinkReferences((asimulinkReferencedPointer*) ssGetUserData(S));
}

#ifdef __cplusplus
}
#endif

#ifdef  MATLAB_MEX_FILE
    #include "simulink.c"
#else
    // Code generation registration function
    #include "cg_sfun.h"
#endif
