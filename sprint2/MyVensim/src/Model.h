#pragma once
#include "Flow.h"
#include "vector"

/**
 * @file Model.h
 * @brief Model Interface class header file
 */

/**
 * @class Model
 * @brief Interface that represents a Flow in the simulator of systems theory
 */

class Model
{
public:
    /**
     * @brief virtual class destructor
     */
    virtual ~Model(){};

    /**
     * @brief Set the name of the Model (pure virtual).
     * @param n A constant reference to the string representing the new name.
     * @return True if the operation is successful, indicating the name is set, false otherwise.
     */
    virtual bool setName(const string &n) = 0;
    /**
     * @brief Retrieve the name of the Model (pure virtual).
     * @return A string representing the name of the Model.
     */
    virtual string getName() const = 0;

    /**
     * @brief Add a System to the Model (pure virtual).
     * @param s Pointer to the System to be added to the Model.
     * @return True if the operation is successful, indicating the System is added, false otherwise.
     */
    virtual bool add(System *s) = 0;
    /**
     * @brief Add a Flow to the Model (pure virtual).
     * @param f Pointer to the Flow to be added to the Model.
     * @return True if the operation is successful, indicating the Flow is added, false otherwise.
     */
    virtual bool add(Flow *f) = 0;
    /**
     * @brief Remove a System from the Model (pure virtual).
     * @param s Pointer to the System to be removed from the Model.
     * @return True if the operation is successful, indicating the System is removed, false otherwise.
     */
    virtual bool remove(const System *s) = 0;
    /**
     * @brief Remove a Flow from the Model (pure virtual).
     * @param f Pointer to the Flow to be removed from the Model.
     * @return True if the operation is successful, indicating the Flow is removed, false otherwise.
     */
    virtual bool remove(const Flow *f) = 0;
    /**
     * @brief Run the Model simulation from t_initial to t_final (pure virtual).
     * @param t_initial The initial time of the simulation.
     * @param t_final The final time of the simulation.
     * @return True if the simulation runs successfully, false otherwise.
     */
    virtual double run(const double &t_initial, const double &t_final) = 0;

    // Typedefs
    typedef vector<System *>::iterator SystemsIterator;
    typedef vector<Flow *>::iterator FlowsIterator;

    /**
     * @brief get an iterator to the beginning of the Systems vector (pure virtual)
     * @return a SystemsIterator to the beginning of the Systems vector
     */
    virtual SystemsIterator getSystems() = 0;
    /**
     * @brief get an iterator to the beginning of the Flows vector (pure virtual)
     * @return a FlowsIterator to the beginning of the Flows vector
     */
    virtual FlowsIterator getFlows() = 0;
    /**
     * @brief get an iterator to the beginning of the Flows vector (pure virtual)
     * @return a FlowsIterator to the beginning of the Flows vector
     */
    virtual FlowsIterator beginFlows() = 0;
    /**
     * @brief get an iterator to the end of the Flows vector (pure virtual)
     * @return a FlowsIterator to the end of the Flows vector
     */
    virtual FlowsIterator endFlows() = 0;
    /**
     * @brief get an iterator to the beginning of the Systems vector (pure virtual)
     * @return a SystemsIterator to the beginning of the Systems vector
     */
    virtual SystemsIterator beginSystems() = 0;
    /**
     * @brief get an iterator to the end of the Systems vector (pure virtual)
     * @return a SystemsIterator to the end of the Systems vector
     */
    virtual SystemsIterator endSystems() = 0;
};