#pragma once
#include "Flow.h"
#include "vector"

/**
 * @brief Iterator type for iterating over a vector of System pointers.
 */
typedef vector<System *>::iterator SystemsIterator;
/**
 * @brief Iterator type for iterating over a vector of Flow pointers.
 */
typedef vector<Flow *>::iterator FlowsIterator;

using namespace std;
/**
 * @file Model.h
 * @brief Model class header file
 */

/**
 * @class Model
 * @brief Class that represents a Model in the simulator of systems theory
 */
class Model
{
protected:
    string name;              ///< Variable to store a name of the Model
    vector<System *> systems; ///< Vector to store pointers to System objects
    vector<Flow *> flows;     ///< Vector to store pointers to Flow objects
public:
    /**
     * @brief Default constructor
     */
    Model();
    /**
     * @brief Parameterized constructor that receives a reference for a string with the name of the Model class
     * @param n a reference to a string representing the name of the Model
     */
    Model(const string &n);
    /**
     * @brief Parameterized constructor that receives a reference for a string name, for a vector of System* and for a vector of Flow*
     * @param n a string representing the name of the Model
     * @param s a vector of pointers to System objects
     * @param f a vector of pointers to Flow objects
     */
    Model(const string &n, const vector<System *> &s, const vector<Flow *> &f);

private:
    /**
     * @brief copy constructor for the Model class
     * @param m reference to the Model object will be copied
     */
    Model(const Model &m);
    /**
     * @brief overloading the "=" operator that copies the attributes of one Model to another
     * @param m a reference to the Model object to be assigned
     * @return a reference to the Model that received the copy data
     */
    Model &operator=(const Model &m);

public:
    /**
     * @brief virtual class destructor
     */
    virtual ~Model();

    /**
     * @brief add a System to the Model
     * @param s a pointer to the System to be added
     * @return true if the System was successfully added, false otherwise
     */
    bool add(System *s);
    /**
     * @brief add a Flow to the Model
     * @param f a pointer to the Flow to be added
     * @return true if the Flow was successfully added, false otherwise
     */
    bool add(Flow *f);
    /**
     * @brief update the properties of a System in the Model
     * @param s a pointer to the System to be updated
     * @param n a reference to a string with new name for the System
     * @param v a reference to a double new value for the System
     * @return true if the System was successfully updated, false otherwise
     */
    bool update(System *s, const string &n, const double &v);
    /**
     * @brief update the connections of a Flow in the Model
     * @param f a pointer to the Flow to be updated
     * @param s a pointer to the new source System for the Flow
     * @param t a pointer to the new target System for the Flow
     * @return true if the Flow was successfully updated, false otherwise
     */
    bool update(const Flow *f, System *s, System *t);
    /**
     * @brief remove a System from the Model
     * @param s a pointer to the System to be removed
     * @return true if the System was successfully removed, false otherwise
     */
    bool remove(const System *s);
    /**
     * @brief remove a Flow from the Model
     * @param f a pointer to the Flow to be removed
     * @return true if the Flow was successfully removed, false otherwise
     */
    bool remove(const Flow *f);

    /**
     * @brief run the Model simulation from a specified initial time to a final time
     * @param t_initial double initial time of the simulation
     * @param t_final double final time of the simulation
     * @return true if the simulation was successful, false otherwise
     */
    bool run(const double &t_initial, const double &t_final);

    typedef vector<System *>::iterator SystemsIterator;
    typedef vector<Flow *>::iterator FlowsIterator;

    /**
     * @brief set the name of the Model.
     * @param n a reference for a string with the new name for the Model
     * @return true if the name was successfully set, false otherwise
     */
    bool setName(const string &n);
    /**
     * @brief get the name of the Model
     * @return a string with the name of the Model
     */
    string getName() const;
    /**
     * @brief get an iterator to the beginning of the Systems vector
     * @return a SystemsIterator to the beginning of the Systems vector
     */
    SystemsIterator getSystems();
    /**
     * @brief get an iterator to the beginning of the Flows vector
     * @return a FlowsIterator to the beginning of the Flows vector
     */
    FlowsIterator getFlows();
    /**
     * @brief overloading the "==" operator which compares the equality between two Models
     * @param m a reference to the Model to be compared
     * @return if the attributes are the same (name, vector<Flow*> and vector<System*>) returns true, otherwise false
     */
    bool operator==(const Model &m) const;

    /**
     * @brief get an iterator to the beginning of the Flows vector
     * @return a FlowsIterator to the beginning of the Flows vector
     */
    FlowsIterator beginFlows();
    /**
     * @brief get an iterator to the end of the Flows vector
     * @return a FlowsIterator to the end of the Flows vector
     */
    FlowsIterator endFlows();
    /**
     * @brief get an iterator to the beginning of the Systems vector
     * @return a SystemsIterator to the beginning of the Systems vector
     */
    SystemsIterator beginSystems();
    /**
     * @brief get an iterator to the end of the Systems vector
     * @return a SystemsIterator to the end of the Systems vector
     */
    SystemsIterator endSystems();
};