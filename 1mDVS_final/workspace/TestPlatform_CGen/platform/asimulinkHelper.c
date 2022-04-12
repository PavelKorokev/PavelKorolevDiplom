/**
 * @file    asimulinkHelper.c
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

#include "simstruc.h"
#include "asimulinkHelper.h"
#include "asimulinkManager.h"
#include "globalH.h"

void setOutputPort(SimStruct *S, int_T index, asimulinkVariableEntry* entry) 
{
	switch(entry->variableType) {
		case SCALAR:
			ssSetOutputPortWidth(S, index, 1);
			break;
		case ARRAY:
			ssSetOutputPortVectorDimension(S, index, entry->sizeX);
			break;
		case MATRIX:
			 ssSetOutputPortMatrixDimensions(S, index, entry->sizeY, entry->sizeX);
			break;
	}
	ssSetOutputPortDataType(S, index, entry->typeId);
}

void setInputPort(SimStruct *S, int_T index, asimulinkVariableEntry* entry) 
{
	switch(entry->variableType) {
		case SCALAR:
			ssSetInputPortWidth(S, index, 1);
			break;
		case ARRAY:
			ssSetInputPortVectorDimension(S, index, entry->sizeX);
			break;
		case MATRIX:
			ssSetInputPortMatrixDimensions(S, index, entry->sizeY, entry->sizeX);
			break;
	}
	ssSetInputPortDataType(S, index, entry->typeId);
}

void copyMatlabInputToModelInput(InputPtrsType pointerToInput, void *modelPointer, BuiltInDTypeId type) {
	switch (type) {
		case SS_DOUBLE:
			*((real_T*)modelPointer) = *((real_T*)pointerToInput[0]);
			break;
		case SS_SINGLE:
			*((real32_T*)modelPointer) = *((real32_T*)pointerToInput[0]);
			break;
		case SS_INT32:
			*((int32_T*)modelPointer) = *((int32_T*)pointerToInput[0]);
			break;
		case SS_INT16:
			*((int16_T*)modelPointer) = *((int16_T*)pointerToInput[0]);
			break;
		case SS_INT8:
			*((int8_T*)modelPointer) = *((int8_T*)pointerToInput[0]);
			break;
		case SS_UINT32:
			*((uint32_T*)modelPointer) = *((uint32_T*)pointerToInput[0]);
			break;
		case SS_UINT16:
			*((uint16_T*)modelPointer) = *((uint16_T*)pointerToInput[0]);
			break;
		case SS_UINT8:
			*((uint8_T*)modelPointer) = *((uint8_T*)pointerToInput[0]);
			break;
		case SS_BOOLEAN:
			*((boolean*)modelPointer) = (*((boolean_T*)pointerToInput[0])) ? TRUE : FALSE;
			break;
	};
}

void copyModelOutputToMatlabOutput(void* modelPointer, void* pointerToOutput, int_T size, BuiltInDTypeId type) {
	switch (type) {
		case SS_DOUBLE:
		{
			real_T* pMatlab = (real_T*)pointerToOutput;
			real_T* pModel = (real_T*)modelPointer;
			
			for(int_T i=0;i<size;++i) {
				pMatlab[i] = pModel[i];
			}
			break;
		}   
		case SS_SINGLE:
		{
			real32_T* pMatlab = (real32_T*)pointerToOutput;
			real32_T* pModel = (real32_T*)modelPointer;
			
			for(int_T i=0;i<size;++i) {
				pMatlab[i] = pModel[i];
			}
			break;
		}    
		case SS_INT32:
		{
			int32_T* pMatlab = (int32_T*)pointerToOutput;
			int32_T* pModel = (int32_T*)modelPointer;
			
			for(int_T i=0;i<size;++i) {
				pMatlab[i] = pModel[i];
			}
			break;
		}
		case SS_INT16:
		{
			int16_T* pMatlab = (int16_T*)pointerToOutput;
			int16_T* pModel = (int16_T*)modelPointer;
			
			for(int i=0;i<size;++i) {
				pMatlab[i] = pModel[i];
			}
		}
		case SS_INT8:
		{
			int8_T* pMatlab = (int8_T*)pointerToOutput;
			int8_T* pModel = (int8_T*)modelPointer;
			
			for(int i=0;i<size;++i) {
				pMatlab[i] = pModel[i];
			}
		}
		case SS_UINT32:
		{
			uint32_T* pMatlab = (uint32_T*)pointerToOutput;
			uint32_T* pModel = (uint32_T*)modelPointer;
			
			for(int i=0;i<size;++i) {
				pMatlab[i] = pModel[i];
			}
			break;
		}
		case SS_UINT16:
		{
			uint16_T* pMatlab = (uint16_T*)pointerToOutput;
			uint16_T* pModel = (uint16_T*)modelPointer;
			
			for(int i=0;i<size;++i) {
				pMatlab[i] = pModel[i];
			}
			break;
		}
		case SS_UINT8:
		{
			uint8_T* pMatlab = (uint8_T*)pointerToOutput;
			uint8_T* pModel = (uint8_T*)modelPointer;
			
			for(int i=0;i<size;++i) {
				pMatlab[i] = pModel[i];
			}
			break;
		}
		case SS_BOOLEAN:
		{
			uint8_T* pMatlab = (uint8_T*)pointerToOutput;
			boolean* pModel = (boolean*)modelPointer;
			
			for(int_T i=0;i<size;++i) {
				pMatlab[i] = pModel[i] ? 1 : 0;
			}
			break;
		}
	};
}

boolean_T checkDataType(asimulinkVariableEntry entry, const mxArray* parameter) {
	if (entry.numberOfElements != mxGetNumberOfElements(parameter)) {
		return FALSE;
	}
	
	switch(entry.typeId) {
		case SS_BOOLEAN:
			return mxIsLogical(parameter);
		case SS_SINGLE:
			return mxIsSingle(parameter);
		case SS_DOUBLE:
			return mxIsDouble(parameter);
		case SS_INT8:
			return mxIsInt8(parameter);
		case SS_INT16:
			return mxIsInt16(parameter);
		case SS_INT32:
			return mxIsInt32(parameter);
		case SS_UINT8:
			return mxIsUint8(parameter);
		case SS_UINT16:
			return mxIsUint16(parameter);
		case SS_UINT32:
			return mxIsUint32(parameter);
	}

	return FALSE;
}

void copyMatlabParameterToModel(void* matlabPointer, void* modelPointer, BuiltInDTypeId typeId, int_T indexMatlab, int_T indexModel) {
	switch(typeId) {
		case SS_BOOLEAN:
			((boolean_T*) modelPointer)[indexModel] =  ((boolean_T*) matlabPointer)[indexMatlab];
			break;
		case SS_SINGLE:
			((real32_T*) modelPointer)[indexModel] =  ((real32_T*) matlabPointer)[indexMatlab];
			break;
		case SS_DOUBLE:
			((real64_T*) modelPointer)[indexModel] =  ((real64_T*) matlabPointer)[indexMatlab];
			break;
		case SS_INT8:
			((int8_T*) modelPointer)[indexModel] =  ((int8_T*) matlabPointer)[indexMatlab];
			break;
		case SS_INT16:
			((int16_T*) modelPointer)[indexModel] =  ((int16_T*) matlabPointer)[indexMatlab];
			break;
		case SS_INT32:
			((int32_T*) modelPointer)[indexModel] =  ((int32_T*) matlabPointer)[indexMatlab];
			break;
		case SS_UINT8:
			((uint8_T*) modelPointer)[indexModel] =  ((uint8_T*) matlabPointer)[indexMatlab];
			break;
		case SS_UINT16:
			((uint16_T*) modelPointer)[indexModel] =  ((uint16_T*) matlabPointer)[indexMatlab];
			break;
		case SS_UINT32:
			((uint32_T*) modelPointer)[indexModel] =  ((uint32_T*) matlabPointer)[indexMatlab];
			break;
	}
}

void copyMatlabParametersToModel(asimulinkVariableEntry entry, void* modelPointer, void* matlabPointer) {
	if (MATRIX == entry.variableType) {
			for (int_T i=0;i<entry.sizeX;i++) {
				for(int_T j=0;j<entry.sizeY;++j) {
					copyMatlabParameterToModel(matlabPointer, modelPointer, entry.typeId, i + j * entry.sizeX, i * entry.sizeY + j);
				}
			}
	} else { // SCALAR and ARRAY
		for(int_T i=0;i<entry.numberOfElements;++i) {
			copyMatlabParameterToModel(matlabPointer, modelPointer, entry.typeId, i, i);
		}
	}
}
