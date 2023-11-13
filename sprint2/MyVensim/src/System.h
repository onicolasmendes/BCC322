#pragma once
#include <iostream>
#include <string>

using namespace std;

/**
 * @file System.h
 * @brief System class header file
 */

/**
 * @class System
 * @brief Class that represents a System in the simulator of systems theory
 */
class System
{
protected:
    string name;  ///< a string that represents the name of the System, like a id
    double value; ///< a double value that represents the value associated with the system
public:
    /**
     * @brief default constructor
     */
    System();
    /**
     * @brief Parameterized constructor that receives the name of the system and sets the name
     * @param n a referente to the string that represents the name of the system
     */
    System(const string &n);
     /**
     * @brief Parameterized constructor that receives the name of the system and the initial value associated with and sets both
     * @param n a reference to the string that represents the name of the system
     * @param v a reference to the double initial value associated with the system
     */
    System(const string &n, const double &v);
    /**
     * @brief constructor that copies the name and the double value of an existing system to a newly created one
     * @param s a reference to the system that will be copied
     */
    System(System &s);

    /**
     * @brief virtual class destructor
     */
    virtual ~System();

    /**
     * @brief a setter that receives a reference to a string name and sets as the name of the system associated
     * @param n a reference to the string name
     * @return if the string name is set successfully, the method returns true. otherwise, false
     */
    bool setName(const string &n);
    /**
     * @brief a getter that returns the string name of the system associated
     * @return a string with the name of the system associated
     */
    string getName() const;
    /**
     * @brief a setter that receives a reference to a double value and sets as the value of the system associated
     * @param v a reference to the double value
     * @return if the double value is set successfully, the method returns true. otherwise, false
     */
    bool setValue(const double &v);
    /**
     * @brief a getter that returns the double value of the system associated
     * @return a double value of the system associated
     */
    double getValue() const;

   /**
     * @brief overloading the "=" operator that copies the attributes of one system to another
     * @param s a reference to the system will be copied
     * @return a reference to the system that received the copy data
     */
    System &operator=(const System &s);
    /**
     * @brief overloading the "==" operator which compares the equality between two systems
     * @param s a reference to the system will be compared
     * @return if the systems are the same (same name and value) returns true, otherwise false
     */
    bool operator==(const System &s) const;
};