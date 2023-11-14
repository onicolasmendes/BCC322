#pragma once
#include "Flow.h"

using namespace std;


/**
 * @file FlowImpl.h
 * @brief FlowImpl class header file
 */

/**
 * @class FlowImpl
 * @brief Flow concrete class that implements the interface Flow and represents a Flow in systems theory.
 */

class FlowImpl : public Flow
{
protected:
    System *source; ///< a pointer to the source system of the represented flow
    System *target; ///< a pointer to the target system of the represented flow
public:
    /**
     * @brief default constructor
     */
    FlowImpl();
    /**
     * @brief Parameterized constructor that receives pointers of the source and target systems and defines them as attributes
     * @param s a pointer to the source system
     * @param t a pointer to the target system
     */
    FlowImpl(System *s, System *t);
    /**
     * @brief constructor that copies the references of source and target systems of an existing flow to a newly created one
     * @param f a reference to the flow that will be copied
     */
    FlowImpl(const FlowImpl &f);

    /**
     * @brief virtual class destructor
     */
    virtual ~FlowImpl();

    /**
     * @brief a setter that receives a pointer to the source system and defines it as an attribute
     * @param s a pointer to the source system
     * @return if the passed system pointer is set successfully, the method returns true. otherwise, false
     */
    virtual bool setSource(System *s);
    /**
     * @brief a getter that returns a pointer to the system defined as source
     * @return a pointer to the source system
     */
    virtual System *getSource() const;
    /**
     * @brief a setter that receives a pointer to the target system and defines it as an attribute
     * @param s a pointer to the target system
     * @return if the passed system pointer is set successfully, the method returns true. otherwise, false
     */
    virtual bool setTarget(System *s);
    /**
     * @brief a getter that returns a pointer to the system defined as target
     * @return a pointer to the target system
     */
    virtual System *getTarget() const;

    /**
     * @brief overloading the "=" operator that copies the attributes of one flow to another
     * @param f a reference to the flow will be copied
     * @return a reference to the flow that received the copy data
     */
    FlowImpl &operator=(const FlowImpl &f);
    /**
     * @brief overloading the "==" operator which compares the equality between two flows
     * @param f a reference to the flow to be compared
     * @return if the flows are the same (same source and target) returns true, otherwise false
     */
    bool operator==(const FlowImpl &f) const;

    /**
     * @brief abstract method that must be implemented by classes that inherit from flow, defining the equation of the function that governs the associated flow
     */
    virtual double equation() const = 0;
};