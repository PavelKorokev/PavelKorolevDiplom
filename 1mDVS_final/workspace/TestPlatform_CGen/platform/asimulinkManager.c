/********************************************************************************
 * DO NOT EDIT!
 * AUTOMATICALLY GENERATED
 * DESCRIPTION:
 *   Implements scheduling configuration for S-Function
 ********************************************************************************/
#include "asimulinkManager.h"
#include "components_Filter_Automatic.h"
#include "components_PID_Automatic.h"
#include "components_InpOut_Automatic.h"


TASK(Startup) {
}


TASK(Shutdown) {
}

extern void components_Component_Automatic_Spid();

TASK(Task0) {
    components_Component_Automatic_Spid();
}


// task list
asimulinkTaskEntry ascet_simulink_tasks[] = {
    {0.01, 0.0, TASK_REF(Task0)},
};

asimulinkVariableEntry ascet_simulink_inputPorts[] = {
    {0, 0, SS_SINGLE, SCALAR, 1, 0, 0}, /* components.Filter.TsFilter */
    {1, 1, SS_SINGLE, SCALAR, 1, 0, 0}, /* components.PID.PressSet */
    {2, 2, SS_SINGLE, SCALAR, 1, 0, 0}, /* components.PID.qP */
    {3, 3, SS_SINGLE, SCALAR, 1, 0, 0}, /* components.PID.qI */
    {4, 4, SS_SINGLE, SCALAR, 1, 0, 0}, /* components.PID.qD */
    {5, 5, SS_SINGLE, SCALAR, 1, 0, 0}, /* components.PID.TsPID */
    {6, 6, SS_SINGLE, SCALAR, 1, 0, 0}, /* components.InpOut.Input */
};

asimulinkVariableEntry ascet_simulink_outputPorts[] = {
    {0, 7, SS_SINGLE, SCALAR, 1, 0, 0}, /* components.InpOut.Output */
};

asimulinkVariableEntry ascet_simulink_outputVariables[] = {
    0
};

asimulinkVariableEntry ascet_simulink_characteristics[] = {
    0
};

asimulinkManagerType simulinkManager = {
    1, /* number of tasks */
    ascet_simulink_tasks, /* tasks table */
    TASK_REF(Startup), /* the optional startup hook */
    TASK_REF(Shutdown), /* the optional shutdown hook */
    7, /* number of input ports */
    ascet_simulink_inputPorts, /* input port table */
    1, /* number of output messages */
    ascet_simulink_outputPorts, /* output message table */
    0, /* number of visible model variables */
    ascet_simulink_outputVariables, /* list of visible output variables */
    0, /* number of characteristics */
    ascet_simulink_characteristics, /* list of characteristics */
};

void initReferencedPointer(asimulinkReferencedPointer* referencedPointer) {
	void** references = referencedPointer->references;
	references[0] = &components_Filter_TsFilter;
	references[1] = &components_PID_PressSet;
	references[2] = &components_PID_qP;
	references[3] = &components_PID_qI;
	references[4] = &components_PID_qD;
	references[5] = &components_PID_TsPID;
	references[6] = &components_InpOut_Input;
	references[7] = &components_InpOut_Output;
}
