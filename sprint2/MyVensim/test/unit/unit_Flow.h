#pragma once
#include "../../src/FlowImpl.h"
#include "../../src/SystemImpl.h"
#include "../funcional/Flows/FlowExponencial.h"
#include <cassert>
#include <cmath>

/**
 * @brief Unit test for the default constructor of FlowImpl.
 *
 * This test creates a FlowImpl object using the default constructor and checks if the source and target systems are nullptr.
 */
void unit_Flow_default_constructor();
/**
 * @brief Unit test for the parameterized constructor of FlowImpl.
 *
 * This test creates a FlowImpl object with specified source and target systems, and verifies if they are set correctly.
 */
void unit_Flow_parameter_constructor();
/**
 * @brief Unit test for the destructor of FlowImpl.
 *
 * This test creates a FlowImpl object using the parameterized constructor and checks if the destructor releases the allocated resources correctly.
 */
void unit_Flow_destructor();
/**
 * @brief Unit test for the copy constructor of FlowImpl.
 *
 * This test creates an original FlowImpl object and then creates a copy using the copy constructor.
 * It checks if the source and target systems of the copied object match the original.
 */
void unit_Flow_copy_constructor();
/**
 * @brief Unit test for the setSource function of FlowImpl.
 *
 * This test creates a FlowImpl object and sets a new source system using the setSource function.
 * It then verifies if the source system is correctly updated.
 */
void unit_Flow_setSource();
/**
 * @brief Unit test for the getSource function of FlowImpl.
 *
 * This test creates a FlowImpl object with a specified source system and checks if the getSource function returns the expected source.
 */
void unit_Flow_getSource();
/**
 * @brief Unit test for the setTarget function of FlowImpl.
 *
 * This test creates a FlowImpl object and sets a new target system using the setTarget function.
 * It then verifies if the target system is correctly updated.
 */
void unit_Flow_setTarget();
/**
 * @brief Unit test for the getTarget function of FlowImpl.
 *
 * This test creates a FlowImpl object with a specified target system and checks if the getTarget function returns the expected target.
 */
void unit_Flow_getTarget();
/**
 * @brief Verifies the operator= function of  FlowImpl.
 *
 * This test creates two FlowImpl objects and assigns the values of the first object to the second using the assignment operator.
 * It verifies if the values of the second object are correctly updated.
 */
void unit_Flow_operator_equ();
/**
 * @brief Unit test for the equality operator of FlowImpl.
 *
 * This test creates two FlowImpl objects with equal source and target systems and checks if the equality operator returns true for these objects.
 */
void unit_Flow_operator_copy();
/**
 * @brief Run all unit tests
 */
void run_unit_test_Flow();