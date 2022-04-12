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

#ifndef ASIMULINK_REEFERENCES_H
#define ASIMULINK_REEFERENCES_H

#include "simstruc.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct _simulinkReferencedPointer {
	int_T staticElementIndex;			// static Element index
	int_T localElementIndex;			// local element index
	int_T numberOfElements;				// number of references
	void** references;					// references to pointer of characteristics and measurements
} asimulinkReferencedPointer;

asimulinkReferencedPointer* initSimulinkReferences(int_T numberOfStaticElements, int_T numberOfElements);
void releaseSimulinkReferences(asimulinkReferencedPointer* referencedPointers);
void* getReferencedPointer(asimulinkReferencedPointer* referencedPointers, int_T index);

#ifdef __cplusplus
}
#endif

#endif
