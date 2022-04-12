/**
 * @file    asimulinkVariables.h
 *
 * @author  ETAS GmbH
 *
 * @brief   defines types to describe a variable entry
 *
 * @details This header file is used for Simulink win64 build.
 *
 * @version 1.0
 *
 * @copyright ETAS GmbH, Stuttgart, Germany. All rights reserved
 **/

#ifndef ASIMULINK_VARIABLES_H
#define ASIMULINK_VARIABLES_H

#include "simstruc.h"
#include "asimulinkSchedule.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum {
	SCALAR,
	ARRAY,
	MATRIX,
} VariableType;

typedef struct {
	int_T index;					// index of the variable
	int_T reference;				// index in pointer list
	BuiltInDTypeId typeId;			// type of the variable
	VariableType variableType;		// type of Variable
	int_T numberOfElements;			// number of elements
	int_T sizeX;					// size of array/matrix x
	int_T sizeY;					// size of matrix y
} asimulinkVariableEntry;

#ifdef __cplusplus
}
#endif

#endif
