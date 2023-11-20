#pragma once
#include "../../src/SystemImpl.h"
#include <cassert>
#include <cmath>

/**
 * @brief Unit test for the default constructor of SystemImpl.
 *
 * This test creates a SystemImpl object using the default constructor and checks if the name is empty and the value is 0.0.
 */
void unit_System_default_constructor();
/**
 * @brief Unit test for the parameterized constructor of SystemImpl.
 *
 * This test creates a SystemImpl object with a specified name using the parameterized constructor.
 * It verifies if the name is set correctly and, if a value is not provided, the value defaults to 0.0.
 * If a value is provided, it checks if both the name and value are set correctly.
 */
void unit_System_parameter_constructor();

/**
 * @brief Unit test for the destructor of the SystemImpl class.
 *
 * This test dynamically creates a SystemImpl object and deletes it to ensure proper destruction.
 */
void unit_System_destructor();
/**
 * @brief Unit test for the copy constructor of the SystemImpl class.
 *
 * This test creates an original SystemImpl object and then creates a copy using the copy constructor.
 * It checks if the values of the copied object match the values of the original.
 */
void unit_System_copy_constructor();
/**
 * @brief Unit test for the setName function of the SystemImpl class.
 *
 * This test creates a SystemImpl object and sets a new name using the setName function.
 * It then verifies if the name is correctly updated.
 */
void unit_System_set_name();
/**
 * @brief Unit test for the getName function of the SystemImpl class.
 *
 * This test creates a SystemImpl object with a specific name and checks if the getName function
 * returns the expected name.
 */
void unit_System_get_name();
/**
 * @brief Unit test for the setValue function of the SystemImpl class.
 *
 * This test creates a SystemImpl object and sets a new value using the setValue function.
 * It then verifies if the value is correctly updated.
 */
void unit_System_set_value();
/**
 * @brief Unit test for the getValue function of the SystemImpl class.
 *
 * This test creates a SystemImpl object with a specific value and checks if the getValue function
 * returns the expected value.
 */
void unit_System_get_value();
/**
 * @brief Unit test for the equality operator of the SystemImpl class.
 *
 * This test creates two SystemImpl objects with equal values and checks if the equality operator
 * returns true for these objects.
 */
void unit_System_operator_equi();
/**
 * @brief Unit test for the assignment operator of the SystemImpl class.
 *
 * This test creates two SystemImpl objects, assigns the values of the first object to the second
 * using the assignment operator, and verifies if the values are correctly updated.
 */
void unit_System_operator_copy();
/**
 * @brief Run all unit tests
 */
void run_unit_test_System();