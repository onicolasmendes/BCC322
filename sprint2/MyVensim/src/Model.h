#pragma once
#include "FlowImpl.h"
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

protected:
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
    static bool add(Model *m);
public:
    virtual bool remove(System *s) = 0;
    /**
     * @brief Remove a Flow from the Model (pure virtual).
     * @param f Pointer to the Flow to be removed from the Model.
     * @return True if the operation is successful, indicating the Flow is removed, false otherwise.
     */
    virtual bool remove(Flow *f) = 0;
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
    typedef vector<Model *>::iterator ModelsIterator;

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
    /**
     * @brief Gets an iterator pointing to the beginning of the Models vector (pure virtual)
     * @return A ModelsIterator pointing to the beginning of the Models vector
     */
    virtual ModelsIterator beginModels() = 0;
    /**
     * @brief Gets an iterator pointing to the end of the Models vector (pure virtual)
     * @return A ModelsIterator pointing to the end of the Models vector
     */
    virtual ModelsIterator endModels() = 0;
    /**
     * @brief Delegates the creation of a new Model with the given name to the ModelImpl class
     * @param n A constant reference to a string representing the name of the new Model
     * @return A pointer to the newly created Model
     */
    static Model *createModel(const string &n);
    /**
     * @brief Creates a new Model using the ModelImpl class.
     * This function delegates the creation of a new Model to the ModelImpl class.
     * @return A pointer to the newly created Model.
     */
    static Model *createModel();
    /**
     * @brief Creates a new System with the given name and initial value (pure virtual)
     * @param n A constant reference to a string representing the name of the new System
     * @param v A constant reference to a double representing the initial value of the new System
     * @return A pointer to the newly created System
     */
    virtual System *createSystem(const string &n, const double &v) = 0;
    /**
     * @brief Sets the source System of the given Flow (pure virtual)
     * @param f A pointer to the Flow for which the source System is to be set
     * @param s A pointer to the System that will be set as the source of the Flow
     * @return true if the source System of the Flow was successfully set, false otherwise
     */
    virtual bool setSource(Flow *f, System *s) = 0;
    /**
     * @brief Sets the target System of the given Flow (pure virtual)
     * @param f A pointer to the Flow for which the target System is to be set
     * @param s A pointer to the System that will be set as the target of the Flow
     * @return true if the target System of the Flow was successfully set, false otherwise
     */
    virtual bool setTarget(Flow *f, System *s) = 0;

    template <typename T_FLOW_IMPL>
    /**
     * @brief Creates a new Flow with the given source and target Systems (default: nullptr)
     * @param s A pointer to the source System of the new Flow (default: nullptr)
     * @param t A pointer to the target System of the new Flow (default: nullptr)
     * @return A pointer to the newly created Flow
     */

    Flow *createFlow(System *s = nullptr, System *t = nullptr)
    {
        Flow *f = new FlowHandle<T_FLOW_IMPL>(s, t);
        add(f);
        return f;
    }
};