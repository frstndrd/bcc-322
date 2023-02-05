/**
 * @file funcional_tests.h
 * @author Iago Andrade (iago.andrade@aluno.ufop.edu.br)
 * @brief Runs the functional tests
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "../../src/model.h"
#include "../../src/system.h"
#include "../../src/flow.h"
#include "flowExponential.h"
#include "flowLogistical.h"

#include <assert.h>
#include <cmath>
#include <iostream>
#include <cstdlib>
#include <cstring>

#ifndef FUNCIONAL_TESTS
#define FUNCIONAL_TESTS

/**
 * @brief Run the exponential test
 * 
 */
void exponentialFuncionalTest();
/**
 * @brief Run the logistical test
 * 
 */
void logisticalFuncionalTest();
/**
 * @brief Run the complex test, with multiple systems and flows
 * 
 */
void complexFuncionalTest();

#endif