/**
 * @file    asimulinkManager.h
 *
 * @author  ETAS GmbH
 *
 * @brief   defines types for Simulink manager
 *
 * @details This header file is used for Simulink win64 build.
 *
 * @version 1.0
 *
 * @copyright ETAS GmbH, Stuttgart, Germany. All rights reserved
 **/

#ifndef ASIMULINK_MANAGER_H
#define ASIMULINK_MANAGER_H

#include "simstruc.h"
#include "asimulinkSchedule.h"
#include "asimulinkReference.h"
#include "asimulinkVariables.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct _simulinkManager {
	int_T numberOfTasks;						// number of tasks
	asimulinkTaskEntry *tasks;					// task list
	void (*startup)();							// function pointer to an optional startup hook
	void (*shutdown)();							// function pointer to an optional shutdown hook

	int_T numberOfInputPorts;					// number of variables
	asimulinkVariableEntry* inputPorts;			// input message list

	int_T numberOfOutputPorts;					// number of out messages
	asimulinkVariableEntry* outputPorts;		// output message list

	int_T numberOfOutputVariables;				// number of variables
	asimulinkVariableEntry* outputVariables;	// variable list

	int_T numberOfCharacteristisc;				// number of characteristics
	asimulinkVariableEntry* characteristics;	// characteristic list
} asimulinkManagerType;

extern asimulinkManagerType simulinkManager;

void initReferencedPointer(asimulinkReferencedPointer* referencedPointer);

#ifdef __cplusplus
}
#endif

#endif
