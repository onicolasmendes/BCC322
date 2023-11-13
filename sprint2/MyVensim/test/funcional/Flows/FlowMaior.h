#pragma once

#include "../../../src/Flow.h"

/**
 * @file FlowMaior.h
 * @brief FlowMaior class header file
 */

/**
 * @class FlowMaior
 * @brief Class intended for testing that inherits from Flow and implements equation()
 */
class FlowMaior : public Flow
{
public:
    /**
     * @brief Default constructor
     */
    FlowMaior();
    /**
     * @brief parameterized constructor that receives a pointer to a source System and a target System
     * @param s a pointer to the source System.
     * @param t a pointer to the target System.
     */
    FlowMaior(System *s, System *t);
    /**
     * @brief virtual destructor
     */
    virtual ~FlowMaior();
    /**
     * @brief virtual method to compute the equation governing the FlowMaior (0.01 * source System value)
     * @return the result of the equation as a double.
     */
    virtual double equation() const;
};
