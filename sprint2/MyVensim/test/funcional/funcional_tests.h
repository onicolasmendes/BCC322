#pragma once
#include "../../src/Model.h"
#include "Flows/FlowExponencial.h"
#include "Flows/FlowLogistica.h"
#include "Flows/FlowMaior.h"

/**
 * @file funcional_tests.h
 * @brief Funcional tests header file
 */

/**
 * @brief validate a case with exponentialFlow, where two systems are created (pop1 and pop2), with 100 and 0 as initial values.
 * pop1 is defined as source and pop2 is defined as target of a flow expo. The simulation runs 0 to 100, and the expected results are
 * 36.6032 for pop1 and 63.3968 for pop2.
 * @return true on success, false on failure
 */
bool exponentialFuncionalTest();
/**
 * @brief validate a case with logisticFlow, where two systems are created (p1 and p2), with 100 and 10 as initial values.
 * p1 is defined as source and p2 is defined as target of a flow log. The simulation runs 0 to 100, and the expected results are
 * 88.2167 for p1 and 21.7833 for p2.
 * @return true on success, false on failure
 */
bool logisticalFuncionalTest();
/**
 * @brief validate a case with flowMaior, where five systems are created (q1, q2, q3, q4 and q5), with 100, 0, 100, 0 and 0 as initial values respectively.
 * q1 is defined as source and q2 is defined as target of a f (a flow log). q1 is defined as source and q3 is defined as target of a g (a flow log).
 * q3 is defined as source and q4 is defined as target of a u (a flow log). q4 is defined as source and q1 is defined as target of a v (a flow log).
 * q2 is defined as source and q3 is defined as target of a t (a flow log). q2 is defined as source and q5 is defined as target of a r (a flow log).  
 * The simulation runs 0 to 100, and the expected results are 31.8513 for q1, 18.4003 for q2, 77.1143 for q3, 56.1428 for q4 and 16.4612 for q5.
 * @return true on success, false on failure
 */
bool complexFuncionalTest();



