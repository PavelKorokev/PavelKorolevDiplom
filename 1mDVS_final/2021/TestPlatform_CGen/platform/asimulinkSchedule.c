/**
 * @file    asimulinkSchedule.c
 *
 * @author  ETAS GmbH
 *
 * @brief   implements the helper functions for scheduling
 *
 * @details This code file is used for Simulink win64 build
 *
 * @version 1.0
 *
 * @copyright ETAS GmbH, Stuttgart, Germany. All rights reserved
 **/

#include "asimulinkSchedule.h"
#include "platform_defs.h"

#ifdef __cplusplus
extern "C" {
#endif

real64_T taskTolerance = 0.0;

void setTaskActivationTolerance(real64_T tolerance) {
	taskTolerance = tolerance;
}

void ASIMULINK_NS(InitTaskEntry)(asimulinkTaskEntry taskEntry, real64_T startTime) {
	taskEntry.lastActivation = startTime - taskEntry.period;
}

void ASIMULINK_NS(ScheduleTask)(asimulinkTaskEntry* taskEntry, real64_T actualSimulationTime) {
	double deltaT = actualSimulationTime - taskEntry->lastActivation;
	
	if (deltaT >= (taskEntry->period - taskTolerance)) {
	    ASCET_SET_MODEL_DT(deltaT);
		taskEntry->lastActivation = actualSimulationTime;
		taskEntry->task();
	}
}

#ifdef __cplusplus
}
#endif
