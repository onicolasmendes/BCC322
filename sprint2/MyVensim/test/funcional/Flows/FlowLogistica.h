#pragma once

#include "../../../src/FlowImpl.h"

/**
 * @file FlowLogistica.h
 * @brief FlowLogistica class header file
 */

/**
 * @class FlowLogistica
 * @brief Class intended for testing that inherits from Flow and implements equation()
 */
class FlowLogistica : public FlowImpl
{
public:
    /**
     * @brief default constructor
     */
    FlowLogistica();
    /**
     * @brief parameterized constructor that receives a pointer to a source System and a target System
     * @param s a pointer to the source System
     * @param t a pointer to the target System
     */
    FlowLogistica(System *s, System *t);
    /**
     * @brief virtual destructor
     */
    virtual ~FlowLogistica();
    /**
     * @brief virtual method to compute the equation governing the FlowLogistica (0.01 * target System value * (1 - target System value / 70))
     * @return the result of the equation as a double
     */
    virtual double equation() const;
};