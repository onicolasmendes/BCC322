#pragma once
#include "../../src/Model.h"
#include "../../src/SystemImpl.h"
#include "../funcional/Flows/FlowExponencial.h"
#include "../funcional/Flows/FlowLogistica.h"
#include <cassert>

/**
 * @brief Unit test for the handling and manipulation of Model, System, and SystemHandle objects.
 *
 * This unit test demonstrates the creation and manipulation of Model, System, and SystemHandle objects.
 * It focuses on testing different aspects of object creation, assignment, and deletion within the model.
 *
 * The test scenario involves creating a model with two systems and a flow, then manipulating the systems
 * using references and handles. It also includes checks for the number of created and deleted handles and bodies.
 *
 * The test covers scenarios with and without the use of curly braces, showcasing the usage of object handles
 * and delegation. Assertions are used to validate the expected number of created and deleted handles and bodies.
 *
 **/
void unit_handleBody();
/**
 * @brief Run all tests for handle body
 **/
void run_unit_test_handleBody();