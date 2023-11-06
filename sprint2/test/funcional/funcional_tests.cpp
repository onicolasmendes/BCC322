#include "funcional_tests.h"
#include <cassert>
#include <cmath>

bool exponentialFuncionalTest()
{
    System pop1("pop1", 100);
    System pop2("pop2", 0);
    Model m1("m1");
    FlowExponencial expo(&pop1, &pop2);
    m1.add(&expo);
    m1.add(&pop1);
    m1.add(&pop2);
    m1.run(1, 100);

    assert(abs(pop1.getValue() - 36.6032) < 0.0001);
    assert(abs(pop2.getValue() - 63.3968) < 0.0001);

    return true;
}

bool logisticalFuncionalTest()
{
    System p1("p1", 100);
    System p2("p2", 10);
    Model m2("m2");
    FlowLogistica log(&p1, &p2);
    m2.add(&log);
    m2.add(&p1);
    m2.add(&p2);
    m2.run(1, 100);

    assert(abs(p1.getValue() - 88.2167) < 0.0001);
    assert(abs(p2.getValue() - 21.7833) < 0.0001);

    return true;
}

bool complexFuncionalTest()
{
    System q1("q1", 100);
    System q2("q2", 0);
    System q3("q3", 100);
    System q4("q4", 0);
    System q5("q5", 0);
    Model m3("m3");
    FlowMaior f(&q1, &q2);
    FlowMaior g(&q1, &q3);
    FlowMaior u(&q3, &q4);
    FlowMaior v(&q4, &q1);
    FlowMaior t(&q2, &q3);
    FlowMaior r(&q2, &q5);
    m3.add(&q1);
    m3.add(&q2);
    m3.add(&q2);
    m3.add(&q4);
    m3.add(&q5);
    m3.add(&f);
    m3.add(&g);
    m3.add(&u);
    m3.add(&v);
    m3.add(&t);
    m3.add(&r);
    m3.run(1, 100);
    
    assert(abs(q1.getValue() - 31.8513) < 0.0001);
    assert(abs(q2.getValue() - 18.4003) < 0.0001);
    assert(abs(q3.getValue() - 77.1143) < 0.0001);
    assert(abs(q4.getValue() - 56.1728) < 0.0001);
    assert(abs(q5.getValue() - 16.4612) < 0.0001);

    return true;
}