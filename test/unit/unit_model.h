#ifndef UNIT_MODEL_H
#define UNIT_MODEL_H

#include <iostream>
#include <cmath>
#include <cstring>
#include <assert.h>
#include "../../src/flowConcrete.h"
#include "../../src/systemConcrete.h"
#include "../../src/modelConcrete.h"
#include "../funcional/flowExponential.h"
#include "../funcional/flowLogistical.h"

void unit_Model_constructor(void);
void unit_Model_destructor(void);
void unit_Model_getName(void);
void unit_Model_setName(void);
void unit_Model_add(void);
void unit_Model_remove(void);
void unit_Model_clear(void);
void unit_Model_run(void);
void run_unit_tests_Model(void);

#endif