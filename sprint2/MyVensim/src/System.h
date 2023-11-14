#pragma once
#include <iostream>
#include <string>

using namespace std;

/**
 * @file System.h
 * @brief System interface class header file
 */

/**
 * @class System
 * @brief Interface that represents a System in the simulator of systems theory
 */

class System
{
public:
    /**
     * @brief virtual class destructor
     */
    virtual ~System(){};
    /**
     * @brief Set the name of the System (pure virtual).
     * @param n A constant reference to the string representing the new name.
     * @return True if the operation is successful, indicating the name is set, false otherwise.
     */
    virtual bool setName(const string &n) = 0;
    /**
     * @brief Retrieve the name of the System (pure virtual).
     * @return A string representing the name of the System.
     */
    virtual string getName() const = 0;
    /**
     * @brief Set the value for the System (pure virtual).
     * @param v A constant reference to the double representing the new value.
     * @return True if the operation is successful, indicating the value is set, false otherwise.
     */
    virtual bool setValue(const double &v) = 0;

    /**
     * @brief Retrieve the value of the System (pure virtual).
     * @return The value of the System as a double.
     */
    virtual double getValue() const = 0;
};