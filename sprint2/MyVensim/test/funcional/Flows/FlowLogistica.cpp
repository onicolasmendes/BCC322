#include "FlowLogistica.h"

FlowLogistica::FlowLogistica(){};

FlowLogistica::~FlowLogistica(){};

FlowLogistica::FlowLogistica(System *s, System *t) : Flow(s,t){};

double FlowLogistica::equation() const
{
    double value = getTarget()->getValue();
    return 0.01 * value * (1 - value / 70);
}