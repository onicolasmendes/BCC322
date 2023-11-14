#pragma once

#include "../../../src/FlowImpl.h"

/**
 * @file FlowExponencial.h
 * @brief FlowExponencial class header file
 */

/**
 * @class FlowExponencial
 * @brief Class intended for testing that inherits from Flow and implements equation()
 */
class FlowExponencial : public FlowImpl
{
public:
    /**
     * @brief default constructor
     */
    FlowExponencial();
    /**
     * @brief parameterized constructor that receives a pointer to a source System and a target System
     * @param s a pointer to the source System
     * @param t a pointer to the target System
     */
    FlowExponencial(System *s, System *t);
    /**
     * @brief virtual destructor
     */
    virtual ~FlowExponencial();
    /**
     * @brief virtual method to compute the equation governing the FlowExponencial (0.01 * source System value)
     * @return the result of the equation as a double.
     */
    virtual double equation() const;
};
