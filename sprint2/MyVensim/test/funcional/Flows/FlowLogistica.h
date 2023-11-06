#pragma once

#include "../../../src/Flow.h"

class FlowLogistica: public Flow
{
    public:
        FlowLogistica();
        FlowLogistica(System *, System *);
        virtual ~FlowLogistica();
        virtual double equation() const;
};