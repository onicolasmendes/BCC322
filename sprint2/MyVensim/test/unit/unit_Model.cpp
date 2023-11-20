#include "unit_Model.h"

void unit_Model_default_constructor()
{
    Model *model = new ModelImpl();
    assert(model->getName().empty());
    assert(model->beginSystems() == model->endSystems());
    assert(model->beginFlows() == model->endFlows());
    delete model;
}

void unit_Model_parameter_constructor()
{
    Model *model = new ModelImpl("TestModel");
    assert(model->getName() == "TestModel");
    assert(model->beginSystems() == model->endSystems());
    assert(model->beginFlows() == model->endFlows());
    delete model;
}

void unit_Model_full_constructor()
{

    System *system1 = new SystemImpl("System1");
    System *system2 = new SystemImpl("System2");
    Flow *flow1 = new FlowExponencial(system1, system2);

    vector<System *> systems = {system1, system2};
    vector<Flow *> flows = {flow1};

    Model *model = new ModelImpl("TestModel", systems, flows);

    assert(model->getName() == "TestModel");
    assert(distance(model->beginSystems(), model->endSystems()) == 2);
    assert(distance(model->beginFlows(), model->endFlows()) == 1);

    delete model;
}

void unit_Model_destructor()
{

    System *system1 = new SystemImpl("System1");
    System *system2 = new SystemImpl("System2");
    Flow *flow1 = new FlowExponencial(system1, system2);

    vector<System *> systems = {system1, system2};
    vector<Flow *> flows = {flow1};

    Model *model = new ModelImpl("TestModel", systems, flows);

    delete model;
}

void unit_Model_add_system()
{
    Model *model = new ModelImpl();

    
    System *system1 = new SystemImpl("System1");
    System *system2 = new SystemImpl("System2");

    
    assert(model->add(system1));
    assert(model->add(system2));

    
    assert(distance(model->beginSystems(), model->endSystems()) == 2);

    
    System *system3 = new SystemImpl("System3");
    assert(model->add(system3));

    
    delete model;
    delete system1;
    delete system2;
    delete system3;
}

void unit_Model_add_flow()
{
    Model *model = new ModelImpl();

    System *sourceSystem = new SystemImpl("SourceSystem");
    System *targetSystem = new SystemImpl("TargetSystem");
    Flow *flow1 = new FlowExponencial(sourceSystem, targetSystem);

    assert(model->add(flow1));

    assert(distance(model->beginFlows(), model->endFlows()) == 1);

    System *sourceSystem2 = new SystemImpl("SourceSystem2");
    System *targetSystem2 = new SystemImpl("TargetSystem2");
    Flow *flow2 = new FlowExponencial(sourceSystem2, targetSystem2);
    assert(model->add(flow2));

    delete model;
    delete sourceSystem;
    delete targetSystem;
    delete flow1;
    delete sourceSystem2;
    delete targetSystem2;
    delete flow2;
}

void unit_Model_remove_system()
{
    Model *model = new ModelImpl();

    System *system1 = new SystemImpl("System1");
    System *system2 = new SystemImpl("System2");

    model->add(system1);
    model->add(system2);

    assert(model->remove(system1));

    assert(distance(model->beginSystems(), model->endSystems()) == 1);

    System *system3 = new SystemImpl("System3");
    assert(!model->remove(system3));

    delete model;
    delete system1;
    delete system2;
    delete system3;
}

void unit_Model_remove_flow()
{
    Model *model = new ModelImpl();

    System *sourceSystem = new SystemImpl("SourceSystem");
    System *targetSystem = new SystemImpl("TargetSystem");
    Flow *flow1 = new FlowExponencial(sourceSystem, targetSystem);

    model->add(flow1);

    assert(model->remove(flow1));

    assert(distance(model->beginFlows(), model->endFlows()) == 0);

    System *sourceSystem2 = new SystemImpl("SourceSystem2");
    System *targetSystem2 = new SystemImpl("TargetSystem2");
    Flow *flow2 = new FlowExponencial(sourceSystem2, targetSystem2);
    assert(!model->remove(flow2));

    delete model;
    delete sourceSystem;
    delete targetSystem;
    delete flow1;
    delete sourceSystem2;
    delete targetSystem2;
    delete flow2;
}

void unit_Model_setName()
{
    Model *model = new ModelImpl();

    assert(model->setName("TestModel"));

    assert(model->getName() == "TestModel");

    delete model;
}

void unit_Model_getName()
{
    Model *model = new ModelImpl("InitialName");

    assert(model->getName() == "InitialName");

    delete model;
}


void unit_Model_operator_equal()
{

    Model *model1 = new ModelImpl();
    System *system1 = new SystemImpl("System1");
    Flow *flow1 = new FlowExponencial(system1, nullptr);
    model1->add(system1);
    model1->add(flow1);

    Model *model2 = new ModelImpl();
    model2->add(system1);
    model2->add(flow1);

    assert(*static_cast<ModelImpl *>(model1) == *static_cast<ModelImpl *>(model2));

    ModelImpl *model3 = new ModelImpl();
    ModelImpl *model4 = model3;

    assert(model3 == model4);

    delete model1;
    delete model2;
    delete model3;
}

void unit_Model_beginFlows()
{
    Model *model = new ModelImpl();

    Flow *flow1 = new FlowExponencial(nullptr, nullptr);
    Flow *flow2 = new FlowExponencial(nullptr, nullptr);
    model->add(flow1);
    model->add(flow2);

    ModelImpl::FlowsIterator beginIterator = model->beginFlows();

    assert(distance(beginIterator, model->endFlows()) == 2);

    delete model;
}

void unit_Model_endFlows()
{
    Model *model = new ModelImpl();

    Flow *flow1 = new FlowExponencial(nullptr, nullptr);
    Flow *flow2 = new FlowExponencial(nullptr, nullptr);
    model->add(flow1);
    model->add(flow2);

    ModelImpl::FlowsIterator endIterator = model->endFlows();

    assert(distance(model->beginFlows(), endIterator) == 2);

    delete model;
}

void unit_Model_beginSystems()
{
    Model *model = new ModelImpl();

    System *system1 = new SystemImpl("System1");
    System *system2 = new SystemImpl("System2");
    model->add(system1);
    model->add(system2);

    ModelImpl::SystemsIterator beginIterator = model->beginSystems();

    assert(distance(beginIterator, model->endSystems()) == 2);

    delete model;
}

void unit_Model_endSystems()
{
    Model *model = new ModelImpl();

    System *system1 = new SystemImpl("System1");
    System *system2 = new SystemImpl("System2");
    model->add(system1);
    model->add(system2);

    ModelImpl::SystemsIterator endIterator = model->endSystems();

    assert(distance(model->beginSystems(), endIterator) == 2);

    delete model;
}

void unit_Model_run()
{
    Model *model = new ModelImpl();

    System *sourceSystem = new SystemImpl("SourceSystem", 100.0);
    System *targetSystem = new SystemImpl("TargetSystem", 50.0);
    Flow *exponentialFlow = new FlowExponencial(sourceSystem, targetSystem);

    model->add(sourceSystem);
    model->add(targetSystem);
    model->add(exponentialFlow);

    double t_inicial = 0.0;
    double t_final = 100.0;

    assert(t_final - t_inicial == model->run(t_inicial, t_final) );

    delete model;
}

void unit_Model_getFlows()
{
    Model *model = new ModelImpl();

    Flow *flow1 = new FlowExponencial(nullptr, nullptr);
    Flow *flow2 = new FlowExponencial(nullptr, nullptr);
    model->add(flow1);
    model->add(flow2);

    ModelImpl::FlowsIterator flowsIterator = model->getFlows();

    assert(flowsIterator == model->beginFlows());

    delete model;
}

void unit_Model_getSystems()
{
    Model *model = new ModelImpl();

    System *system1 = new SystemImpl("System1");
    System *system2 = new SystemImpl("System2");
    model->add(system1);
    model->add(system2);

    ModelImpl::SystemsIterator systemsIterator = model->getSystems();

    assert(systemsIterator == model->beginSystems());

    delete model;
}

void run_unit_test_Model()
{
    unit_Model_default_constructor();
    unit_Model_parameter_constructor();
    unit_Model_full_constructor();
    unit_Model_destructor();
    unit_Model_add_system();
    unit_Model_add_flow();
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
}
