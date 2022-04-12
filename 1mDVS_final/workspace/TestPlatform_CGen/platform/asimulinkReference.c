/**
 * @file    asimulinkReference.h
 *
 * @author  ETAS GmbH
 *
 * @brief   defines API for managing pointer to ASCET model elements
 *
 * @details This header file is used for Simulink win64 build.
 *
 * @version 1.0
 *
 * @copyright ETAS GmbH, Stuttgart, Germany. All rights reserved
 **/

#include "simstruc.h"
#include "asimulinkreference.h"

asimulinkReferencedPointer* initSimulinkReferences(int_T numberOfStaticElements, int_T numberOfElements) {
	asimulinkReferencedPointer* referencedPointers = (asimulinkReferencedPointer*)calloc(1, sizeof(asimulinkReferencedPointer));

	referencedPointers->staticElementIndex = 0;
	referencedPointers->localElementIndex = numberOfStaticElements;
	referencedPointers->numberOfElements = numberOfElements;
	referencedPointers->references = (void**) calloc(numberOfElements, sizeof(void*));

	return referencedPointers;
}

void releaseSimulinkReferences(asimulinkReferencedPointer* referencedPointers) {
	if (0 != referencedPointers) {
		if (0 != referencedPointers->references) {
			free(referencedPointers->references);
		}
		free(referencedPointers);
	}
}

void* getReferencedPointer(asimulinkReferencedPointer* referencedPointers, int_T index) {
	return referencedPointers->references[index];
}
