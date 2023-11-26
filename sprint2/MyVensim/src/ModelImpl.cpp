#include "ModelImpl.h"
#include "Model.h"

typedef vector<System *>::iterator SystemsIterator;
typedef vector<Flow *>::iterator FlowsIterator;
typedef vector<Model *>::iterator ModelsIterator;

vector<Model *> ModelImpl::models;

using namespace std;



ModelImpl::ModelImpl()
{
    systems.reserve(10);
    flows.reserve(20);
};

ModelImpl::ModelImpl(const string &n)
{
    name = n;
    systems.reserve(10);
    flows.reserve(20);
}

ModelImpl::~ModelImpl() 
{
    for(System *s : systems)
    {
        delete ((SystemImpl*) s);
    }

    for(Flow *f : flows)
    {
        delete ((FlowImpl*) f);
    }

    for(Model *m : models)
    {
        delete ((ModelImpl*) m);
    }

}

ModelImpl::ModelImpl(const string &n, const vector<System *> &s, const vector<Flow *> &f)
{
    name = n;
    systems = s;
    flows = f;
}

ModelImpl::ModelImpl(const ModelImpl &m)
{
    this->flows.clear();
    this->systems.clear();

    for (Flow *flow : m.flows)
    {
        add(flow);
    }

    for (System *system : m.systems)
    {
        add(system);
    }
}

bool ModelImpl::add(System *s)
{
    if (systems.size() == systems.max_size())
        return false;
    systems.push_back(s);
    return true;
}

bool ModelImpl::add(Flow *f)
{
    if (flows.size() == flows.max_size())
        return false;
    flows.push_back(f);
    return true;
}

bool ModelImpl::remove(const System *s)
{
    for (SystemsIterator it = beginSystems(); it < endSystems(); it++)
    {
        if (*it == s)
        {
            systems.erase(it);
            return true;
        }
    }
    return false;
}

bool ModelImpl::remove(const Flow *f)
{
    for (FlowsIterator it = beginFlows(); it < endFlows(); it++)
    {
        if (*it == f)
        {
            flows.erase(it);
            return true;
        }
    }
    return false;
}

bool ModelImpl::setName(const string &n)
{
    name = n;
    return true;
}

string ModelImpl::getName() const
{
    return name;
}

ModelImpl &ModelImpl::operator=(const ModelImpl &m)
{

    if (this == &m)
        return *this;

    this->flows.clear();
    this->systems.clear();

    for (Flow *flow : m.flows)
    {
        add(flow);
    }

    for (System *system : m.systems)
    {
        add(system);
    }

    return *this;
}

bool ModelImpl::operator==(const ModelImpl &m) const
{
    if (this == &m)
        return true;

    if (systems == m.systems && flows == m.flows)
        return true;
    return false;
}

ModelImpl ::FlowsIterator ModelImpl::beginFlows()
{
    return flows.begin();
}

ModelImpl ::FlowsIterator ModelImpl::endFlows()
{
    return flows.end();
}

ModelImpl ::SystemsIterator ModelImpl::beginSystems()
{
    return systems.begin();
}

ModelImpl ::SystemsIterator ModelImpl::endSystems()
{
    return systems.end();
}

double ModelImpl::run(const double &t_inicial, const double &t_final)
{
    double return_value = 0;

    for (double i = t_inicial; i < t_final; i++)
    {
        vector<double> values;

        for (FlowsIterator it = beginFlows(); it < endFlows(); it++)
        {
            values.push_back((*it)->equation());
        }

        for (FlowsIterator it = beginFlows(); it < endFlows(); it++)
        {
            System *source = (*it)->getSource();
            System *target = (*it)->getTarget();

            source->setValue(source->getValue() - values[distance(beginFlows(), it)]);
            target->setValue(target->getValue() + values[distance(beginFlows(), it)]);
        }
        return_value++;
    }
    return return_value;
}

FlowsIterator ModelImpl::getFlows()
{
    return beginFlows();
}

SystemsIterator ModelImpl::getSystems()
{
    return beginSystems();
}

ModelsIterator ModelImpl::beginModels()
{
    return models.begin();
}

ModelsIterator ModelImpl::endModels()
{
    return  models.end();
}

Model* Model::createModel(const string &n)
{
    return ModelImpl::createModel(n);
}

bool ModelImpl::add(Model *m)
{
    ModelImpl::models.push_back(m);
    return true;
}

Model *ModelImpl::createModel(const string &n)
{
    Model *m = new ModelImpl(n);
    ModelImpl::add(m);
    return m;
}

System *ModelImpl::createSystem(const string &n="", const double &v=0)
{
    System *s = new SystemImpl(n, v);
    ModelImpl::add(s);
    return s;
}

bool ModelImpl::deleteFlow(Flow *f)
{
    remove(f);
    delete f;
    return true;
}

bool ModelImpl::deleteSystem(System *s)
{
    remove(s);
    delete s;
    return true;
}

bool ModelImpl::setSource(Flow *f, System *s)
{
    f->setSource(s);
    return true;
}

bool ModelImpl::setTarget(Flow *f, System *s)
{
    f->setTarget(s);
    return true;
}
