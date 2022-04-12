/**
 * @file    asimulinkSchedule.h
 *
 * @author  ETAS GmbH
 *
 * @brief   defines types for Simulink scheduling
 *
 * @details This header file is used for Simulink win64 build
 *
 * @version 1.0
 *
 * @copyright ETAS GmbH, Stuttgart, Germany. All rights reserved
 **/

#ifndef ASIMULINK_SCHEDULE_H
#define ASIMULINK_SCHEDULE_H

#include "simstruc.h"

#ifdef __cplusplus
extern "C" {
#endif

#define ASIMULINK_NS(x) aSim ## x
#define TASK(x) void ASIMULINK_NS(x)(void)
#define TASK_REF(x) ASIMULINK_NS(x)

typedef struct _TaskEntry {
	real64_T period;						// schedule time in [s]
	real64_T lastActivation;				// last activation of the task
	void (*task)();							// function pointer to task
} asimulinkTaskEntry;

void ASIMULINK_NS(InitTaskEntry)(asimulinkTaskEntry taskEntry, real64_T startTime);
void ASIMULINK_NS(ScheduleTask)(asimulinkTaskEntry* taskEntry, real64_T actualSimulationTime);
void setTaskActivationTolerance(real64_T tolerance);

#ifdef __cplusplus
}
#endif

#endif
