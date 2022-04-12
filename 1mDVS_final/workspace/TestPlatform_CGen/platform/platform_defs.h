/**
 * Copyright ETAS GmbH, Stuttgart, Germany. All rights reserved.
 *
 * version: 2.0
 *
 * SIMULINK platform definitions.
 * This header file is used in Mathlab/Simulink build for S-Functions
 */

#ifndef ESDL_PLATFORM_DEFS_H
#define ESDL_PLATFORM_DEFS_H

// SIMULINK platform do not use OSEK like operating system environment, so just set OSENV_SINGLE_THREADED
// since no message protection is needed and scheduler executes task in a single thread.
#define OSENV_SINGLE_THREADED

#include "esdl_types.h"
#include "esdl_deltaTimeDefs.h"

#endif
