#pragma once
#include "Flow.h"
#include "vector"

typedef vector<System*>::iterator SystemsIterator;
typedef vector<Flow*>::iterator FlowsIterator;


using namespace std;

class Model
{
    protected:
        string name;
        vector<System*> systems;
        vector<Flow*> flows;
    public:
        Model();
        Model(const string &);
        Model(const string &, const vector<System*> &, const vector<Flow*> &);
    private:
        Model(const Model &);
        Model& operator=(const Model &);
        
    public:
        virtual ~Model();

        bool add(System *);
        bool add(Flow *);
        bool update(System *, const string &, const double &);
        bool update(const Flow *, System *, System *);
        bool remove(const System *);
        bool remove(const Flow *);
        bool run(const double &, const double &);

        typedef vector<System*>::iterator SystemsIterator;
        typedef vector<Flow*>::iterator FlowsIterator;

        bool setName(const string &);
        string getName() const;
        SystemsIterator getSystems();
        FlowsIterator getFlows();

        
        bool operator==(const Model &) const;

       
        FlowsIterator beginFlows();
        FlowsIterator endFlows();
        SystemsIterator beginSystems();
        SystemsIterator endSystems();
};