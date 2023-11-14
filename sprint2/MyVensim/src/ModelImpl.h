#pragma once
#include "Flow.h"
#include "vector"
#include "Model.h"

/**
 * @file ModelImpl.h
 * @brief ModelImpl class header file
 */

/**
 * @class ModelImpl
 * @brief Model concrete class that implements the interface Model and represents a Model in systems theory.
 */

class ModelImpl : public Model
{
protected:
    string name;              ///< Variable to store a name of the Model
    vector<System *> systems; ///< Vector to store pointers to System objects
    vector<Flow *> flows;     ///< Vector to store pointers to Flow objects

public:
    using SystemsIterator = vector<System *>::iterator;
    using FlowsIterator = vector<Flow *>::iterator;
    /**
     * @brief Default constructor
     */
    ModelImpl();
    /**
     * @brief Parameterized constructor that receives a reference for a string with the name of the Model class
     * @param n a reference to a string representing the name of the Model
     */
    ModelImpl(const string &n);
    /**
     * @brief Parameterized constructor that receives a reference for a string name, for a vector of System* and for a vector of Flow*
     * @param n a string representing the name of the Model
     * @param s a vector of pointers to System objects
     * @param f a vector of pointers to Flow objects
     */
    ModelImpl(const string &n, const vector<System *> &s, const vector<Flow *> &f);

private:
    /**
     * @brief copy constructor for the Model class
     * @param m reference to the Model object will be copied
     */
    ModelImpl(const ModelImpl &m);
    /**
     * @brief overloading the "=" operator that copies the attributes of one Model to another
     * @param m a reference to the Model object to be assigned
     * @return a reference to the Model that received the copy data
     */
    ModelImpl &operator=(const ModelImpl &m);

public:
    /**
     * @brief virtual class destructor
     */
    virtual ~ModelImpl();

    /**
     * @brief add a System to the Model
     * @param s a pointer to the System to be added
     * @return true if the System was successfully added, false otherwise
     */
    virtual bool add(System *s);
    /**
     * @brief add a Flow to the Model
     * @param f a pointer to the Flow to be added
     * @return true if the Flow was successfully added, false otherwise
     */
    virtual bool add(Flow *f);
    /**
     * @brief remove a System from the Model
     * @param s a pointer to the System to be removed
     * @return true if the System was successfully removed, false otherwise
     */
    virtual bool remove(const System *s);
    /**
     * @brief remove a Flow from the Model
     * @param f a pointer to the Flow to be removed
     * @return true if the Flow was successfully removed, false otherwise
     */
    virtual bool remove(const Flow *f);
    /**
     * @brief run the Model simulation from a specified initial time to a final time
     * @param t_initial double initial time of the simulation
     * @param t_final double final time of the simulation
     * @return true if the simulation was successful, false otherwise
     */
    virtual double run(const double &t_initial, const double &t_final);

    /**
     * @brief set the name of the Model.
     * @param n a reference for a string with the new name for the Model
     * @return true if the name was successfully set, false otherwise
     */
    virtual bool setName(const string &n);
    /**
     * @brief get the name of the Model
     * @return a string with the name of the Model
     */
    virtual string getName() const;
    /**
     * @brief get an iterator to the beginning of the Systems vector
     * @return a SystemsIterator to the beginning of the Systems vector
     */
    virtual SystemsIterator getSystems();
    /**
     * @brief get an iterator to the beginning of the Flows vector
     * @return a FlowsIterator to the beginning of the Flows vector
     */
    virtual FlowsIterator getFlows();
    /**
     * @brief overloading the "==" operator which compares the equality between two Models
     * @param m a reference to the Model to be compared
     * @return if the attributes are the same (name, vector<Flow*> and vector<System*>) returns true, otherwise false
     */
    bool operator==(const ModelImpl &m) const;

    /**
     * @brief get an iterator to the beginning of the Flows vector
     * @return a FlowsIterator to the beginning of the Flows vector
     */
    virtual FlowsIterator beginFlows();
    /**
     * @brief get an iterator to the end of the Flows vector
     * @return a FlowsIterator to the end of the Flows vector
     */
    virtual FlowsIterator endFlows();
    /**
     * @brief get an iterator to the beginning of the Systems vector
     * @return a SystemsIterator to the beginning of the Systems vector
     */
    virtual SystemsIterator beginSystems();
    /**
     * @brief get an iterator to the end of the Systems vector
     * @return a SystemsIterator to the end of the Systems vector
     */
    virtual SystemsIterator endSystems();
};