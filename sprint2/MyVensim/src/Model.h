#pragma once
#include "Flow.h"
#include "vector"

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
        Model(const Model &);

        virtual ~Model();

        bool add(System *);
        bool add(Flow *);
        bool update(System *, const string &, const double &);
        bool update(const Flow *, System *, System *);
        bool remove(const System *);
        bool remove(const Flow *);
        bool run(const double &, const double &);

        bool setName(const string &);
        string getName() const;
        bool setSystems(const vector<System*> &);
        vector<System*> getSystems() const;
        bool setFlows(const vector<Flow*> &);
        vector<Flow*> getFlows() const;

        Model& operator=(const Model &);
        bool operator==(const Model &) const;

        typedef vector<System*>::iterator SystemsIterator;
        typedef vector<Flow*>::iterator FlowsIterator;

        FlowsIterator beginFlows();
        FlowsIterator endFlows();
        SystemsIterator beginSystems();
        SystemsIterator endSystems();
};