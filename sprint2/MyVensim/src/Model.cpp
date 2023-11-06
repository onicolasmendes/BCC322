#include "Model.h"

using namespace std;

Model::Model()
{
    systems.reserve(10); 
    flows.reserve(20);
};

Model::Model(const string &n){
    name = n;
    systems.reserve(10);
    flows.reserve(20);
}

Model::~Model(){};

Model::Model(const string &n, const vector<System*> &s, const vector<Flow*> &f)
{
    name = n;
    systems = s;
    flows = f;
}

Model::Model(const Model &m)
{
    if(this == &m) return;
    
    systems = m.systems;
    flows = m.flows;
}

bool Model::add(System *s)
{
    if(systems.size() == systems.max_size()) return false;
    systems.push_back(s);
    return true;
}

bool Model::add(Flow *f)
{
    if(flows.size() == flows.max_size()) return false;
    flows.push_back(f);
    return true;
}

bool Model::update(System *s, const string &n, const double &v)
{
    for(SystemsIterator it = beginSystems(); it < endSystems(); it++)
    {
        if( *it == s )
        {
            (*it)->setName(n);
            (*it)->setValue(v);
            return true;
        }
    }
    return false;
}

bool Model::update(const Flow *f, System *s, System *t)
{
    for(FlowsIterator it = beginFlows(); it < endFlows(); it++)
    {
        if(*it == f)
        {
            (*it)->setSource(s);
            (*it)->setTarget(t);
            return true;
        }
    }
    return false;
}

bool Model::remove(const System *s)
{
    for(SystemsIterator it = beginSystems(); it < endSystems(); it++)
    {
        if(*it == s)
        {
            systems.erase(it);
            return true;
        }
    }
    return false;
}

bool Model::remove(const Flow *f)
{
    for(FlowsIterator it = beginFlows(); it < endFlows(); it++)
    {
        if(*it == f)
        {
            flows.erase(it);
            return true;
        }
    }
    return false;
}

bool Model::setName(const string &n)
{
    name = n;
    return true;
}

string Model::getName() const
{
    return name;
}

bool Model::setSystems(const vector<System*> &s)
{
    systems = s;
    return true;
}

vector<System *> Model::getSystems() const
{
    return systems;
}

bool Model::setFlows(const vector<Flow *> &f)
{
    flows = f;
    return true;
}

vector<Flow *> Model::getFlows() const
{
    return flows;
}

Model& Model::operator=(const Model &m)
{
    if(this == &m) return *this;
    
    systems = m.systems;
    flows = m.flows;
    
    return *this;
}

bool Model::operator==(const Model &m) const
{
    if(this == &m) return true;

    if(systems == m.systems && flows == m.flows) return true;
    return false;
}

Model :: FlowsIterator Model::beginFlows()
{
    return flows.begin();
}

Model :: FlowsIterator Model::endFlows()
{
    return flows.end();
}

Model :: SystemsIterator Model::beginSystems()
{
    return systems.begin();
}

Model :: SystemsIterator Model::endSystems()
{
    return systems.end();
}

bool Model::run(const double &t_inicial, const double &t_final)
{
    for (double i = t_inicial; i <= t_final ; i++)
    {
        vector<double> values;

        for(FlowsIterator it = beginFlows(); it < endFlows(); it++)
        {
            values.push_back((*it)->equation());
        }

        for(FlowsIterator it = beginFlows(); it < endFlows(); it++)
        {
            System* source = (*it)->getSource();
            System* target = (*it)->getTarget();

            source->setValue(source->getValue() - values[distance(beginFlows(), it)]);
            target->setValue(target->getValue() + values[distance(beginFlows(), it)]);
        }

    }
    return true;
    
}

