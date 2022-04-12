/**
 * @file    asimulinkHelper.h
 *
 * @author  ETAS GmbH
 *
 * @brief   defines API to interact between S-Function and ASCET model
 *
 * @details This header file is used for Simulink win64 build.
 *
 * @version 1.0
 *
 * @copyright ETAS GmbH, Stuttgart, Germany. All rights reserved
 **/

#ifndef ASIMULINK_HELPER_H
#define ASIMULINK_HELPER_H

#include "simstruc.h"
#include "asimulinkReference.h"
#include "asimulinkVariables.h"

#ifdef __cplusplus
extern "C" {
#endif

void setOutputPort(SimStruct *S, int_T index, asimulinkVariableEntry* entry);
void setInputPort(SimStruct *S, int_T index, asimulinkVariableEntry* entry);
void copyMatlabInputToModelInput(InputPtrsType pointerToInput, void* modelPointer, BuiltInDTypeId type);
void copyModelOutputToMatlabOutput(void* modelPointer, void* pointerToOutput, int_T size, BuiltInDTypeId type);
boolean_T checkDataType(asimulinkVariableEntry entry, const mxArray* parameter);
void copyMatlabParametersToModel(asimulinkVariableEntry entry, void * modelPointer, void* matlabPointer);

#ifdef __cplusplus
}
#endif

#endif
