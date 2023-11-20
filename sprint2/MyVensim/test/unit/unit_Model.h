#pragma once
#include "../../src/ModelImpl.h"
#include "../../src/FlowImpl.h"
#include "../../src/SystemImpl.h"
#include "../funcional/Flows/FlowExponencial.h"
#include <cassert>
#include <cmath>
#include "vector"

/**
 * @brief Unit test for the default constructor of ModelImpl.
 *
 * This test creates a ModelImpl object using the default constructor and verifies that its initial state is as expected.
 */
void unit_Model_default_constructor();
/**
 * @brief Unit test for the parameterized constructor of ModelImpl.
 *
 * This test creates a ModelImpl object using the parameterized constructor with a specified name and checks if the name is set correctly.
 */
void unit_Model_parameter_constructor();
/**
 * @brief Unit test for the full constructor of ModelImpl.
 *
 * This test creates a ModelImpl object using the full constructor with specified name, systems, and flows. It checks if the object is initialized correctly.
 */
void unit_Model_full_constructor() ;
/**
 * @brief Unit test for the destructor of ModelImpl.
 *
 * This test creates a ModelImpl object, and then deletes it, ensuring proper memory deallocation and cleanup.
 */
void unit_Model_destructor();
/**
 * @brief Unit test for the add system function of ModelImpl.
 *
 * This test creates a ModelImpl object, adds systems to it, and checks if the systems are added successfully.
 */
void unit_Model_add_system();
/**
 * @brief Unit test for the add flow function of ModelImpl.
 *
 * This test creates a ModelImpl object, adds flows to it, and checks if the flows are added successfully.
 */
void unit_Model_add_flow() ;
/**
 * @brief Unit test for the remove system function of ModelImpl.
 *
 * This test creates a ModelImpl object, adds and removes systems, and checks if the removal is successful.
 */
void unit_Model_remove_system() ;
/**
 * @brief Unit test for the remove flow function of ModelImpl.
 *
 * This test creates a ModelImpl object, adds and removes flows, and checks if the removal is successful.
 */
void unit_Model_remove_flow() ;
/**
 * @brief Unit test for the setName function of ModelImpl.
 *
 * This test creates a ModelImpl object, sets a name using the setName function, and checks if the name is set correctly.
 */
void unit_Model_setName() ;
/**
 * @brief Unit test for the getName function of ModelImpl.
 *
 * This test creates a ModelImpl object with an initial name, retrieves the name using getName, and checks if it matches the initial name.
 */
void unit_Model_getName() ;
/**
 * @brief Verifies the operator= function of ModelImpl.
 *
 * This test creates two ModelImpl objects with equal properties and checks if the equality operator returns true for these objects.
 */
void unit_Model_operator_equal();
/**
 * @brief Unit test for the beginFlows function of ModelImpl.
 *
 * This test creates a ModelImpl object, adds flows to it, and checks if the beginFlows function returns the correct iterator.
 */
void unit_Model_beginFlows() ;
/**
 * @brief Unit test for the endFlows function of ModelImpl.
 *
 * This test creates a ModelImpl object, adds flows to it, and checks if the endFlows function returns the correct iterator.
 */
void unit_Model_endFlows() ;
/**
 * @brief Unit test for the beginSystems function of ModelImpl.
 *
 * This test creates a ModelImpl object, adds systems to it, and checks if the beginSystems function returns the correct iterator.
 */
void unit_Model_beginSystems() ;
/**
 * @brief Unit test for the endSystems function of ModelImpl.
 *
 * This test creates a ModelImpl object, adds systems to it, and checks if the endSystems function returns the correct iterator.
 */
void unit_Model_endSystems() ;
/**
 * @brief Unit test for the run function of ModelImpl.
 *
 * This test creates a ModelImpl object with systems and flows, runs the simulation, and checks if the values are updated as expected.
 */
void unit_Model_run() ;
/**
 * @brief Unit test for the getFlows function of ModelImpl.
 *
 * This test creates a ModelImpl object, adds flows to it, and checks if the expected iterations happen as expected.
 */
void unit_Model_getFlows() ;
/**
 * @brief Unit test for the getSystems function of ModelImpl.
 *
 * This test creates a ModelImpl object, adds systems to it, and checks if the getSystems function returns the correct iterator.
 */
void unit_Model_getSystems() ;
/**
 * @brief Run all unit tests
 */
void run_unit_test_Model();

