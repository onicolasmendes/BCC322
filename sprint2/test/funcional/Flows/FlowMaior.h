#pragma once

#include "../../../src/Flow.h"

class FlowMaior: public Flow
{
    public: 
        FlowMaior();
        FlowMaior(System *, System *);
        virtual ~FlowMaior();
        virtual double equation() const;
};
    