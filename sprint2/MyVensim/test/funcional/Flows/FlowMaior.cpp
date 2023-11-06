#include "FlowMaior.h"

FlowMaior::FlowMaior(){};

FlowMaior::~FlowMaior(){};

FlowMaior::FlowMaior(System *s, System *t) : Flow(s,t){};


double FlowMaior::equation() const
{
    return 0.01 * getSource()->getValue();
}
