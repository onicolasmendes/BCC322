#pragma once

#include "../../../src/Flow.h"

class FlowExponencial: public Flow
{
    public: 
        FlowExponencial();
        FlowExponencial(System *, System *);
        virtual ~FlowExponencial();
        virtual double equation() const;
};
    