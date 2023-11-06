#include "FlowExponencial.h"

FlowExponencial::FlowExponencial(){};

FlowExponencial::~FlowExponencial(){};

FlowExponencial::FlowExponencial(System *s, System *t) : Flow(s,t){};


double FlowExponencial::equation() const
{
    return 0.01 * getSource()->getValue();
}
