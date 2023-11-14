#pragma once
#include "System.h"

using namespace std;

/**
 * @file Flow.h
 * @brief Flow Interface class header file
 */

/**
 * @class Flow
 * @brief Interface that represents a Flow in the simulator of systems theory
 */

class Flow
{
public:
    /**
     * @brief virtual class destructor
     */
    virtual ~Flow(){};

    /**
     * @brief Set the System object as the source for the Flow (pure virtual)
     * @param s Pointer to the System object to be set as the source
     * @return True if the operation is successful, indicating the System is set as the source, false otherwise
     */
    virtual bool setSource(System *s) = 0;

    /**
     * @brief Get the System object serving as the source for the Flow (pure virtual).
     * @return Pointer to the System object serving as the source.
     */
    virtual System *getSource() const = 0;

    /**
     * @brief Set the System object as the target for the Flow (pure virtual).
     * @param s Pointer to the System object to be set as the target.
     * @return True if the operation is successful, indicating the System is set as the target, false otherwise.
     */
    virtual bool setTarget(System *s) = 0;

    /**
     * @brief Get the System object serving as the target for the Flow (pure virtual).
     * @return Pointer to the System object serving as the target.
     */
    virtual System *getTarget() const = 0;

    /**
     * @brief Calculate and retrieve the result of the equation (pure virtual).
     * @return The result of the equation as a double.
     */
    virtual double equation() const = 0;
};