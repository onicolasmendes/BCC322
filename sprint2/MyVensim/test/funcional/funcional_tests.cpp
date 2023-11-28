#include "funcional_tests.h"
#include <cassert>
#include <cmath>

bool exponentialFuncionalTest()
{
    Model *m = Model::createModel("expo");
    System *pop1 = m->createSystem("pop1", 100);
    System *pop2 = m->createSystem("pop2", 0);
    Flow *f = m->createFlow<FlowExponencial>(pop1);
    m->setTarget(f, pop2);
    
    m->run(0, 100);

    assert(round(fabs(pop1->getValue() - 36.6032) * 10000) < 0.0001);
    assert(round(fabs(pop2->getValue() - 63.3968) * 10000) < 0.0001);

    delete m;

    return true;
}

bool logisticalFuncionalTest()
{
    Model *m = Model::createModel("log");
    System *p1 = m->createSystem("p1", 100);
    System *p2 = m->createSystem("p2", 10);
    Flow *log = m->createFlow<FlowLogistica>();

    m->setSource(log, p1);
    m->setTarget(log, p2);

    m->run(0, 100);

    assert(round(fabs(p1->getValue() - 88.2167) * 10000) < 0.0001);
    assert(round(fabs(p2->getValue() - 21.7833) * 10000) < 0.0001);

    delete m;
    return true;
}

bool complexFuncionalTest()
{
   
    Model *m = Model::createModel("complex");
    System *q1 = m->createSystem("q1", 100);
    System *q2 = m->createSystem("q2", 0);
    System *q3 = m->createSystem("q3", 100);
    System *q4 = m->createSystem("q4", 0);
    System *q5 = m->createSystem("q5", 0);
    Flow *f = m->createFlow<FlowMaior>(q1);
    m->setTarget(f, q2);
    Flow *g = m->createFlow<FlowMaior>(q1);
    m->setTarget(g, q3);
    Flow *u = m->createFlow<FlowMaior>(q3);
    m->setTarget(u, q4);
    Flow *v = m->createFlow<FlowMaior>(q4);
    m->setTarget(v, q1);
    Flow *t = m->createFlow<FlowMaior>(q2);
    m->setTarget(t, q3);
    Flow *r = m->createFlow<FlowMaior>(q2);
    m->setTarget(r, q5);

    m->run(0, 100);

    assert(round(fabs(q1->getValue() - 31.8513) * 10000) < 0.0001);
    assert(round(fabs(q2->getValue() - 18.4003) * 10000) < 0.0001);
    assert(round(fabs(q3->getValue() - 77.1143) * 10000) < 0.0001);
    assert(round(fabs(q4->getValue() - 56.1728) * 10000) < 0.0001);
    assert(round(fabs(q5->getValue() - 16.4612) * 10000) < 0.0001);

    delete m;
    
   return true;
}

