#include "unit_Model.h"
#include <iostream>
#include <iterator>
using namespace std;
typedef vector<System *>::iterator SystemsIterator;
typedef vector<Flow *>::iterator FlowsIterator;
typedef vector<Model *>::iterator ModelsIterator;

void unit_Model_default_constructor()
{
    Model *model = Model::createModel();
    assert(model->beginSystems() == model->endSystems());
    assert(model->beginFlows() == model->endFlows());
    delete model;
}

void unit_Model_parameter_constructor()
{
    Model *model = Model::createModel("TestModel");
    assert(model->getName() == "TestModel");
    assert(model->beginSystems() == model->endSystems());
    assert(model->beginFlows() == model->endFlows());
    delete model;
}

void unit_Model_full_constructor()
{

    Model *model = Model::createModel("TestModel");
    System *system1 = model->createSystem("System1", 0);
    System *system2 = model->createSystem("System2", 0);
    Flow *flow1 = model->createFlow<FlowExponencial>(system1, system2);
    assert(model->getName() == "TestModel");
    assert(distance(model->beginSystems(), model->endSystems()) == 2);
    assert(distance(model->beginFlows(), model->endFlows()) == 1);
    delete model;
}

void unit_Model_destructor()
{

    Model *model = Model::createModel("TestModel");
    System *system1 = model->createSystem("System1", 0);
    System *system2 = model->createSystem("System2", 0);
    Flow *flow1 = model->createFlow<FlowExponencial>(system1, system2);
    delete model;
}

void unit_Model_remove_system()
{
    Model *model = Model::createModel("default");

    System *system1 = model->createSystem("System1", 0);
    System *system2 = model->createSystem("System2", 0);

    assert(model->remove(system1));

    assert(distance(model->beginSystems(), model->endSystems()) == 1);

    System *system3 = model->createSystem("System3", 0);
    assert(model->remove(system3));

    delete model;
}

void unit_Model_remove_flow()
{
    Model *model = Model::createModel("default");

    System *sourceSystem = model->createSystem("SourceSystem", 0);
    System *targetSystem = model->createSystem("TargetSystem", 0);
    Flow *flow1 = model->createFlow<FlowExponencial>(sourceSystem, targetSystem);
    assert(model->remove(flow1));
    assert(distance(model->beginFlows(), model->endFlows()) == 0);
    System *sourceSystem2 = model->createSystem("SourceSystem2", 0);
    System *targetSystem2 = model->createSystem("TargetSystem2", 0);
    Flow *flow2 = model->createFlow<FlowExponencial>(sourceSystem2, targetSystem2);
    assert(model->remove(flow2));
    delete model;
}

void unit_Model_setName()
{
    Model *model = Model::createModel("default");
    assert(model->setName("TestModel"));
    assert(model->getName() == "TestModel");
    delete model;
}

void unit_Model_getName()
{
    Model *model = Model::createModel("InitialName");

    assert(model->getName() == "InitialName");

    delete model;
}

void unit_Model_operator_equal()
{
    ModelImpl *model3 = new ModelImpl();
    ModelImpl *model4 = model3;

    assert(model3 == model4);

    delete model3;
}

void unit_Model_beginFlows()
{
    Model *model = Model::createModel("default");

    Flow *flow1 = model->createFlow<FlowExponencial>(nullptr, nullptr);
    Flow *flow2 = model->createFlow<FlowExponencial>(nullptr, nullptr);

    ModelImpl::FlowsIterator beginIterator = model->beginFlows();

    assert(distance(beginIterator, model->endFlows()) == 2);

    delete model;
}

void unit_Model_endFlows()
{
    Model *model = Model::createModel("default");

    Flow *flow1 = model->createFlow<FlowExponencial>(nullptr, nullptr);
    Flow *flow2 = model->createFlow<FlowExponencial>(nullptr, nullptr);

    ModelImpl::FlowsIterator endIterator = model->endFlows();

    assert(distance(model->beginFlows(), endIterator) == 2);

    delete model;
}

void unit_Model_beginSystems()
{
    Model *model = Model::createModel("default");

    System *system1 = model->createSystem("System1", 0);
    System *system2 = model->createSystem("System2", 0);

    ModelImpl::SystemsIterator beginIterator = model->beginSystems();

    assert(distance(beginIterator, model->endSystems()) == 2);

    delete model;
}

void unit_Model_endSystems()
{
    Model *model = Model::createModel("default");

    System *system1 = model->createSystem("System1", 0);
    System *system2 = model->createSystem("System2", 0);

    ModelImpl::SystemsIterator endIterator = model->endSystems();

    assert(distance(model->beginSystems(), endIterator) == 2);

    delete model;
}

void unit_Model_run()
{
    Model *model = Model::createModel("default");

    double t_inicial = 0.0;
    double t_final = 100.0;

    assert(t_final - t_inicial == model->run(t_inicial, t_final));

    delete model;
}

void unit_Model_getFlows()
{
    Model *model = Model::createModel("default");

    Flow *flow1 = model->createFlow<FlowExponencial>(nullptr, nullptr);
    Flow *flow2 = model->createFlow<FlowExponencial>(nullptr, nullptr);

    ModelImpl::FlowsIterator flowsIterator = model->getFlows();

    assert(flowsIterator == model->beginFlows());

    delete model;
}

void unit_Model_getSystems()
{
    Model *model = Model::createModel("default");

    System *system1 = model->createSystem("System1", 0);
    System *system2 = model->createSystem("System2", 0);

    ModelImpl::SystemsIterator systemsIterator = model->getSystems();

    assert(systemsIterator == model->beginSystems());

    delete model;
}
void unit_Model_beginModels()
{
    Model *model = Model::createModel("default");
    Model *model2 = Model::createModel("default");
    ModelImpl::ModelsIterator beginIterator = model->beginModels();

    assert(distance(beginIterator, model->endModels()) == 2);

    delete model;
    delete model2;
}

void unit_Model_endModels()
{
    Model *model = Model::createModel("default");
    Model *model2 = Model::createModel("default");
    ModelImpl::ModelsIterator endIterator = model->endModels();
    assert((distance(model->beginModels(), endIterator)) == 2);

    delete model;
    delete model2;
}

void unit_Model_createModel()
{
    Model *model = Model::createModel("default");
    assert(model != nullptr);
    delete model;
}

void unit_Model_createModel_Impl()
{
    Model *model = Model::createModel("default");
    Model *subModel = model->createModel("SubModel");
    assert(subModel != nullptr);
    delete model;
    delete subModel;
}

void unit_Model_createSystem()
{
    Model *model = Model::createModel("default");
    System *subSystem = model->createSystem("SubSystem", 42.0);
    assert(subSystem != nullptr);
    delete model;
}

void unit_Model_setSource()
{
    Model *model = Model::createModel("default");
    Flow *flow = model->createFlow<FlowExponencial>(nullptr, nullptr);
    System *system = model->createSystem("SubSystem", 42.0);
    assert(model->setSource(flow, system));
    delete model;
}

void unit_Model_setTarget()
{
    Model *model = Model::createModel("default");
    Flow *flow = model->createFlow<FlowExponencial>(nullptr, nullptr);
    System *system = model->createSystem("SubSystem", 42.0);
    assert(model->setTarget(flow, system));
    delete model;
}

void run_unit_test_Model()
{
    unit_Model_default_constructor();
    unit_Model_parameter_constructor();
    unit_Model_full_constructor();
    unit_Model_destructor();
    unit_Model_remove_system();
    unit_Model_remove_flow();
    unit_Model_setName();
    unit_Model_getName();
    unit_Model_operator_equal();
    unit_Model_beginFlows();
    unit_Model_endFlows();
    unit_Model_beginSystems();
    unit_Model_endSystems();
    unit_Model_run();
    unit_Model_getFlows();
    unit_Model_getSystems();
    unit_Model_beginModels();
    unit_Model_endModels();
    unit_Model_createModel();
    unit_Model_createModel_Impl();
    unit_Model_createSystem();
    unit_Model_setSource();
    unit_Model_setTarget();
}
