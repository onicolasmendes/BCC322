#pragma once
#include "vector"
#include "Model.h"
#include "SystemImpl.h"
#include "handleBodySemDebug.h"

typedef vector<System *>::iterator SystemsIterator;
typedef vector<Flow *>::iterator FlowsIterator;
typedef vector<Model *>::iterator ModelsIterator;


using namespace std;
/**
 * @file ModelImpl.h
 * @brief ModelImpl class header file
 */

/**
 * @class ModelImpl
 * @brief Model concrete class that implements the interface Model and represents a Model in systems theory.
 */

class ModelImpl : public Body
{
protected:
    string name;                   ///< Variable to store a name of the Model
    vector<System *> systems;      ///< Vector to store pointers to System objects
    vector<Flow *> flows;          ///< Vector to store pointers to Flow objects
    static vector<Model *> models; ///< Vector to store pointers to created models
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

protected:
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
     * @brief remove a System from the Model
     * @param s a pointer to the System to be removed
     * @return true if the System was successfully removed, false otherwise
     */
    virtual bool remove(System *s);
    /**
     * @brief remove a Flow from the Model
     * @param f a pointer to the Flow to be removed
     * @return true if the Flow was successfully removed, false otherwise
     */
    virtual bool remove(Flow *f);
    /**
     * @brief run the Model simulation from a specified initial time to a final time
     * @param t_initial double initial time of the simulation
     * @param t_final double final time of the simulation
     * @return true if the simulation was successful, false otherwise
     */
    virtual double run(const double &t_initial, const double &t_final);
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
     * @brief Adds the given Model to the Models container
     * @param m A pointer to the Model to be added
     * @return true if the Model was successfully added, false otherwise
     */
    static bool add(Model *m);
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
    /**
     * @brief Obtains an iterator pointing to the beginning of the Models container
     * @return A ModelsIterator pointing to the first element in the Models container
     */
    virtual ModelsIterator beginModels();
    /**
     * @brief Obtains an iterator pointing to the end of the Models container
     * @return A ModelsIterator pointing one past the last element in the Models container
     */
    virtual ModelsIterator endModels();
    /**
     * @brief Creates a new Model with the given name and adds it to the Models container
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
     * @brief Creates a new System with the given name and initial value, and adds it to the Models container
     * @param n A constant reference to a string representing the name of the new System (default: empty string)
     * @param v A constant reference to a double representing the initial value of the new System (default: 0)
     * @return A pointer to the newly created System
     */
    virtual System *createSystem(const string &n, const double &v);
    /**
     * @brief Sets the source System of the given Flow
     * @param f A pointer to the Flow for which the source System is to be set
     * @param s A pointer to the System that will be set as the source of the Flow
     * @return true if the source System of the Flow was successfully set, false otherwise
     */
    virtual bool setSource(Flow *f, System *s);
    /**
     * @brief Sets the target System of the given Flow
     * @param f A pointer to the Flow for which the target System is to be set
     * @param s A pointer to the System that will be set as the target of the Flow
     * @return true if the target System of the Flow was successfully set, false otherwise
     */
    virtual bool setTarget(Flow *f, System *s);
};

class ModelHandle : public Model, public Handle<ModelImpl>
{
public:
    ModelHandle(string name = "")
    {
        pImpl_->setName(name);
    }

    virtual ~ModelHandle() {}

    virtual bool remove(System *s) { return pImpl_->remove(s); };
    virtual bool remove(Flow *f) { return pImpl_->remove(f); };
    virtual double run(const double &t_initial, const double &t_final) { return pImpl_->run(t_initial, t_final); };
    virtual bool setName(const string &n) { return pImpl_->setName(n); };
    virtual string getName() const { return pImpl_->getName(); };
    virtual SystemsIterator getSystems() { return pImpl_->getSystems(); };
    virtual FlowsIterator getFlows() { return pImpl_->getFlows(); };
    virtual FlowsIterator beginFlows() { return pImpl_->beginFlows(); };
    virtual FlowsIterator endFlows() { return pImpl_->endFlows(); };
    virtual SystemsIterator beginSystems() { return pImpl_->beginSystems(); };
    virtual SystemsIterator endSystems() { return pImpl_->endSystems(); };
    virtual ModelsIterator beginModels() { return pImpl_->beginModels(); };
    virtual ModelsIterator endModels() { return pImpl_->endModels(); };
    virtual System *createSystem(const string &n, const double &v) { return pImpl_->createSystem(n, v); };
    virtual bool setSource(Flow *f, System *s) { return pImpl_->setSource(f, s); };
    virtual bool setTarget(Flow *f, System *s) { return pImpl_->setTarget(f, s); };
    virtual bool add(Flow *f){return pImpl_->add(f);};
    virtual bool add(System *s){return pImpl_->add(s);};
};