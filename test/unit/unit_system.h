#ifndef UNIT_SYSTEM_H
#define UNIT_SYSTEM_H

#include <iostream>
#include <cmath>
#include <cstring>
#include <assert.h>
#include "../../src/systemConcrete.h"

void unit_System_constructor(void);
void unit_System_destructor(void);
void unit_System_getValue(void);
void unit_System_setValue(void);
void unit_System_getName(void);
void unit_System_setName(void);
void run_unit_tests_System(void);

#endif