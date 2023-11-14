#include "funcional_tests.h"
#include <cassert>
#include <cmath>

bool exponentialFuncionalTest()
{

    System *pop1 = new SystemImpl("pop1", 100);
    System *pop2 = new SystemImpl("pop2", 0);
    Model *m1 = new ModelImpl("m1");
    Flow *expo = new FlowExponencial(pop1, pop2);
    m1->add(expo);
    m1->add(pop1);
    m1->add(pop2);
    m1->run(0, 100);

    assert(round(fabs(pop1->getValue() - 36.6032) * 10000) < 0.0001);
    assert(round(fabs(pop2->getValue() - 63.3968) * 10000) < 0.0001);

    delete (pop1);
    delete (pop2);
    delete (m1);
    delete (expo);

    return true;
}

bool logisticalFuncionalTest()
{
    System *p1 = new SystemImpl("p1", 100);
    System *p2 = new SystemImpl("p2", 10);
    Model *m2 = new ModelImpl("m2");
    Flow *log = new FlowLogistica(p1, p2);
    m2->add(log);
    m2->add(p1);
    m2->add(p2);
    m2->run(0, 100);

    assert(round(fabs(p1->getValue() - 88.2167) * 10000) < 0.0001);
    assert(round(fabs(p2->getValue() - 21.7833) * 10000) < 0.0001);

    delete (p1);
    delete (p2);
    delete (m2);
    delete (log);

    return true;
}

bool complexFuncionalTest()
{
    System *q1 = new SystemImpl("q1", 100);
    System *q2 = new SystemImpl("q2", 0);
    System *q3 = new SystemImpl("q3", 100);
    System *q4 = new SystemImpl("q4", 0);
    System *q5 = new SystemImpl("q5", 0);
    Model *m3 = new ModelImpl("m3");
    Flow *f = new FlowMaior(q1, q2);
    Flow *g = new FlowMaior(q1, q3);
    Flow *u = new FlowMaior(q3, q4);
    Flow *v = new FlowMaior(q4, q1);
    Flow *t = new FlowMaior(q2, q3);
    Flow *r = new FlowMaior(q2, q5);
    m3->add(q1);
    m3->add(q2);
    m3->add(q2);
    m3->add(q4);
    m3->add(q5);
    m3->add(f);
    m3->add(g);
    m3->add(u);
    m3->add(v);
    m3->add(t);
    m3->add(r);
    m3->run(0, 100);

    assert(round(fabs(q1->getValue() - 31.8513) * 10000) < 0.0001);
    assert(round(fabs(q2->getValue() - 18.4003) * 10000) < 0.0001);
    assert(round(fabs(q3->getValue() - 77.1143) * 10000) < 0.0001);
    assert(round(fabs(q4->getValue() - 56.1728) * 10000) < 0.0001);
    assert(round(fabs(q5->getValue() - 16.4612) * 10000) < 0.0001);

    delete(q1);
    delete(q2);
    delete(q3);
    delete(q4);
    delete(q5);
    delete(f);
    delete(g);
    delete(u);
    delete(v);
    delete(t);
    delete(r);
    delete(m3);

    return true;
}