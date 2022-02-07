/********************************************************************************
 * DO NOT EDIT!
 * AUTOMATICALLY GENERATED
 * DESCRIPTION:
 *   Implements scheduling configuration for S-Function
 ********************************************************************************/
#include "asimulinkManager.h"
#include "components_Component_Automatic.h"
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
    {1, 1, SS_SINGLE, SCALAR, 1, 0, 0}, /* components.Filter.K1 */
    {2, 2, SS_SINGLE, SCALAR, 1, 0, 0}, /* components.PID.PressSet */
    {3, 3, SS_SINGLE, SCALAR, 1, 0, 0}, /* components.PID.qP */
    {4, 4, SS_SINGLE, SCALAR, 1, 0, 0}, /* components.PID.qI */
    {5, 5, SS_SINGLE, SCALAR, 1, 0, 0}, /* components.PID.qD */
    {6, 6, SS_SINGLE, SCALAR, 1, 0, 0}, /* components.PID.TsPID */
    {7, 7, SS_SINGLE, SCALAR, 1, 0, 0}, /* components.InpOut.Input */
};

asimulinkVariableEntry ascet_simulink_outputPorts[] = {
    {0, 8, SS_SINGLE, SCALAR, 1, 0, 0}, /* components.InpOut.P_Out */
    {1, 9, SS_SINGLE, SCALAR, 1, 0, 0}, /* components.InpOut.I_Out */
    {2, 10, SS_SINGLE, SCALAR, 1, 0, 0}, /* components.InpOut.D_Out */
};

asimulinkVariableEntry ascet_simulink_outputVariables[] = {
    {0, 11, SS_DOUBLE, SCALAR, 1, 0, 0}, /* components.Component.PID_instance.DelayValue_instance_5.memory1 */
    {1, 12, SS_DOUBLE, SCALAR, 1, 0, 0}, /* components.Component.PID_instance.DelayValue_instance_5.memory2 */
    {2, 13, SS_SINGLE, SCALAR, 1, 0, 0}, /* components.Component.PID_instance.pMemory */
    {3, 20, SS_SINGLE, SCALAR, 1, 0, 0}, /* components.Component.PID_instance.afterP */
    {4, 21, SS_SINGLE, SCALAR, 1, 0, 0}, /* components.Component.PID_instance.afterI */
    {5, 22, SS_SINGLE, SCALAR, 1, 0, 0}, /* components.Component.PID_instance.afterD */
    {6, 23, SS_SINGLE, SCALAR, 1, 0, 0}, /* components.Component.PID_instance.Error */
    {7, 24, SS_SINGLE, SCALAR, 1, 0, 0}, /* components.Component.PID_instance.InpOsc */
    {8, 25, SS_DOUBLE, SCALAR, 1, 0, 0}, /* components.Component.RunningAverage_instance.DelayValue_instance.memory1 */
    {9, 26, SS_DOUBLE, SCALAR, 1, 0, 0}, /* components.Component.RunningAverage_instance.DelayValue_instance.memory2 */
    {10, 27, SS_DOUBLE, SCALAR, 1, 0, 0}, /* components.Component.RunningAverage_instance.DelayValue_instance_2.memory1 */
    {11, 28, SS_DOUBLE, SCALAR, 1, 0, 0}, /* components.Component.RunningAverage_instance.DelayValue_instance_2.memory2 */
    {12, 29, SS_DOUBLE, SCALAR, 1, 0, 0}, /* components.Component.RunningAverage_instance.DelayValue_instance_3.memory1 */
    {13, 30, SS_DOUBLE, SCALAR, 1, 0, 0}, /* components.Component.RunningAverage_instance.DelayValue_instance_3.memory2 */
    {14, 31, SS_DOUBLE, SCALAR, 1, 0, 0}, /* components.Component.RunningAverage_instance.DelayValue_instance_4.memory1 */
    {15, 32, SS_DOUBLE, SCALAR, 1, 0, 0}, /* components.Component.RunningAverage_instance.DelayValue_instance_4.memory2 */
    {16, 33, SS_DOUBLE, SCALAR, 1, 0, 0}, /* components.Component.RunningAverage_instance.DelayValue_instance_5.memory1 */
    {17, 34, SS_DOUBLE, SCALAR, 1, 0, 0}, /* components.Component.RunningAverage_instance.DelayValue_instance_5.memory2 */
    {18, 35, SS_DOUBLE, SCALAR, 1, 0, 0}, /* components.Component.RunningAverage_instance.DelayValue_instance_6.memory1 */
    {19, 36, SS_DOUBLE, SCALAR, 1, 0, 0}, /* components.Component.RunningAverage_instance.DelayValue_instance_6.memory2 */
    {20, 37, SS_DOUBLE, SCALAR, 1, 0, 0}, /* components.Component.RunningAverage_instance.DelayValue_instance_7.memory1 */
    {21, 38, SS_DOUBLE, SCALAR, 1, 0, 0}, /* components.Component.RunningAverage_instance.DelayValue_instance_7.memory2 */
    {22, 39, SS_DOUBLE, SCALAR, 1, 0, 0}, /* components.Component.RunningAverage_instance.DelayValue_instance_8.memory1 */
    {23, 40, SS_DOUBLE, SCALAR, 1, 0, 0}, /* components.Component.RunningAverage_instance.DelayValue_instance_8.memory2 */
    {24, 41, SS_DOUBLE, SCALAR, 1, 0, 0}, /* components.Component.RunningAverage_instance.DelayValue_instance_9.memory1 */
    {25, 42, SS_DOUBLE, SCALAR, 1, 0, 0}, /* components.Component.RunningAverage_instance.DelayValue_instance_9.memory2 */
    {26, 44, SS_DOUBLE, SCALAR, 1, 0, 0}, /* components.Component.FilterBy_instance.DelayValue_instance.memory1 */
    {27, 45, SS_DOUBLE, SCALAR, 1, 0, 0}, /* components.Component.FilterBy_instance.DelayValue_instance.memory2 */
    {28, 47, SS_DOUBLE, SCALAR, 1, 0, 0}, /* components.Component.PID_instance_3.DelayValue_instance_5.memory1 */
    {29, 48, SS_DOUBLE, SCALAR, 1, 0, 0}, /* components.Component.PID_instance_3.DelayValue_instance_5.memory2 */
    {30, 49, SS_SINGLE, SCALAR, 1, 0, 0}, /* components.Component.PID_instance_3.pMemory */
    {31, 56, SS_SINGLE, SCALAR, 1, 0, 0}, /* components.Component.PID_instance_3.afterP */
    {32, 57, SS_SINGLE, SCALAR, 1, 0, 0}, /* components.Component.PID_instance_3.afterI */
    {33, 58, SS_SINGLE, SCALAR, 1, 0, 0}, /* components.Component.PID_instance_3.afterD */
    {34, 59, SS_SINGLE, SCALAR, 1, 0, 0}, /* components.Component.PID_instance_3.Error */
    {35, 60, SS_SINGLE, SCALAR, 1, 0, 0}, /* components.Component.PID_instance_3.InpOsc */
    {36, 61, SS_SINGLE, SCALAR, 1, 0, 0}, /* components.Component.afterInp */
    {37, 62, SS_SINGLE, SCALAR, 1, 0, 0}, /* components.Component.afterFilt */
    {38, 63, SS_SINGLE, SCALAR, 1, 0, 0}, /* components.Component.afterRunAv */
};

asimulinkVariableEntry ascet_simulink_characteristics[] = {
    {0, 14, SS_SINGLE, SCALAR, 1, 0, 0}, /* components.Component.PID_instance.cP_Max */
    {1, 15, SS_SINGLE, SCALAR, 1, 0, 0}, /* components.Component.PID_instance.cP_Min */
    {2, 16, SS_SINGLE, SCALAR, 1, 0, 0}, /* components.Component.PID_instance.cI_Max */
    {3, 17, SS_SINGLE, SCALAR, 1, 0, 0}, /* components.Component.PID_instance.cD_Max */
    {4, 18, SS_SINGLE, SCALAR, 1, 0, 0}, /* components.Component.PID_instance.cD_Min */
    {5, 19, SS_SINGLE, SCALAR, 1, 0, 0}, /* components.Component.PID_instance.cI_Min */
    {6, 43, SS_SINGLE, SCALAR, 1, 0, 0}, /* components.Component.RunningAverage_instance.c1 */
    {7, 46, SS_SINGLE, SCALAR, 1, 0, 0}, /* components.Component.FilterBy_instance.K2 */
    {8, 50, SS_SINGLE, SCALAR, 1, 0, 0}, /* components.Component.PID_instance_3.cP_Max */
    {9, 51, SS_SINGLE, SCALAR, 1, 0, 0}, /* components.Component.PID_instance_3.cP_Min */
    {10, 52, SS_SINGLE, SCALAR, 1, 0, 0}, /* components.Component.PID_instance_3.cI_Max */
    {11, 53, SS_SINGLE, SCALAR, 1, 0, 0}, /* components.Component.PID_instance_3.cD_Max */
    {12, 54, SS_SINGLE, SCALAR, 1, 0, 0}, /* components.Component.PID_instance_3.cD_Min */
    {13, 55, SS_SINGLE, SCALAR, 1, 0, 0}, /* components.Component.PID_instance_3.cI_Min */
};

asimulinkManagerType simulinkManager = {
    1, /* number of tasks */
    ascet_simulink_tasks, /* tasks table */
    TASK_REF(Startup), /* the optional startup hook */
    TASK_REF(Shutdown), /* the optional shutdown hook */
    8, /* number of input ports */
    ascet_simulink_inputPorts, /* input port table */
    3, /* number of output messages */
    ascet_simulink_outputPorts, /* output message table */
    39, /* number of visible model variables */
    ascet_simulink_outputVariables, /* list of visible output variables */
    14, /* number of characteristics */
    ascet_simulink_characteristics, /* list of characteristics */
};

void initReferencedPointer(asimulinkReferencedPointer* referencedPointer) {
	void** references = referencedPointer->references;
	references[0] = &components_Filter_TsFilter;
	references[1] = &components_Filter_K1;
	references[2] = &components_PID_PressSet;
	references[3] = &components_PID_qP;
	references[4] = &components_PID_qI;
	references[5] = &components_PID_qD;
	references[6] = &components_PID_TsPID;
	references[7] = &components_InpOut_Input;
	references[8] = &components_InpOut_P_Out;
	references[9] = &components_InpOut_I_Out;
	references[10] = &components_InpOut_D_Out;
	references[11] = &components_Component_RAM.PID_instance.DelayValue_instance_5.memory1;
	references[12] = &components_Component_RAM.PID_instance.DelayValue_instance_5.memory2;
	references[13] = &components_Component_RAM.PID_instance.pMemory;
	references[20] = &components_Component_RAM.PID_instance.afterP;
	references[21] = &components_Component_RAM.PID_instance.afterI;
	references[22] = &components_Component_RAM.PID_instance.afterD;
	references[23] = &components_Component_RAM.PID_instance.Error;
	references[24] = &components_Component_RAM.PID_instance.InpOsc;
	references[25] = &components_Component_RAM.RunningAverage_instance.DelayValue_instance.memory1;
	references[26] = &components_Component_RAM.RunningAverage_instance.DelayValue_instance.memory2;
	references[27] = &components_Component_RAM.RunningAverage_instance.DelayValue_instance_2.memory1;
	references[28] = &components_Component_RAM.RunningAverage_instance.DelayValue_instance_2.memory2;
	references[29] = &components_Component_RAM.RunningAverage_instance.DelayValue_instance_3.memory1;
	references[30] = &components_Component_RAM.RunningAverage_instance.DelayValue_instance_3.memory2;
	references[31] = &components_Component_RAM.RunningAverage_instance.DelayValue_instance_4.memory1;
	references[32] = &components_Component_RAM.RunningAverage_instance.DelayValue_instance_4.memory2;
	references[33] = &components_Component_RAM.RunningAverage_instance.DelayValue_instance_5.memory1;
	references[34] = &components_Component_RAM.RunningAverage_instance.DelayValue_instance_5.memory2;
	references[35] = &components_Component_RAM.RunningAverage_instance.DelayValue_instance_6.memory1;
	references[36] = &components_Component_RAM.RunningAverage_instance.DelayValue_instance_6.memory2;
	references[37] = &components_Component_RAM.RunningAverage_instance.DelayValue_instance_7.memory1;
	references[38] = &components_Component_RAM.RunningAverage_instance.DelayValue_instance_7.memory2;
	references[39] = &components_Component_RAM.RunningAverage_instance.DelayValue_instance_8.memory1;
	references[40] = &components_Component_RAM.RunningAverage_instance.DelayValue_instance_8.memory2;
	references[41] = &components_Component_RAM.RunningAverage_instance.DelayValue_instance_9.memory1;
	references[42] = &components_Component_RAM.RunningAverage_instance.DelayValue_instance_9.memory2;
	references[44] = &components_Component_RAM.FilterBy_instance.DelayValue_instance.memory1;
	references[45] = &components_Component_RAM.FilterBy_instance.DelayValue_instance.memory2;
	references[47] = &components_Component_RAM.PID_instance_3.DelayValue_instance_5.memory1;
	references[48] = &components_Component_RAM.PID_instance_3.DelayValue_instance_5.memory2;
	references[49] = &components_Component_RAM.PID_instance_3.pMemory;
	references[56] = &components_Component_RAM.PID_instance_3.afterP;
	references[57] = &components_Component_RAM.PID_instance_3.afterI;
	references[58] = &components_Component_RAM.PID_instance_3.afterD;
	references[59] = &components_Component_RAM.PID_instance_3.Error;
	references[60] = &components_Component_RAM.PID_instance_3.InpOsc;
	references[61] = &components_Component_RAM.afterInp;
	references[62] = &components_Component_RAM.afterFilt;
	references[63] = &components_Component_RAM.afterRunAv;
	references[14] = &components_Component_CAL_MEM.PID_instance.cP_Max;
	references[15] = &components_Component_CAL_MEM.PID_instance.cP_Min;
	references[16] = &components_Component_CAL_MEM.PID_instance.cI_Max;
	references[17] = &components_Component_CAL_MEM.PID_instance.cD_Max;
	references[18] = &components_Component_CAL_MEM.PID_instance.cD_Min;
	references[19] = &components_Component_CAL_MEM.PID_instance.cI_Min;
	references[43] = &components_Component_CAL_MEM.RunningAverage_instance.c1;
	references[46] = &components_Component_CAL_MEM.FilterBy_instance.K2;
	references[50] = &components_Component_CAL_MEM.PID_instance_3.cP_Max;
	references[51] = &components_Component_CAL_MEM.PID_instance_3.cP_Min;
	references[52] = &components_Component_CAL_MEM.PID_instance_3.cI_Max;
	references[53] = &components_Component_CAL_MEM.PID_instance_3.cD_Max;
	references[54] = &components_Component_CAL_MEM.PID_instance_3.cD_Min;
	references[55] = &components_Component_CAL_MEM.PID_instance_3.cI_Min;
}
