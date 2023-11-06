#pragma once
#include "System.h"

using namespace std;

class Flow
{
    protected:
        System* source;
        System* target;
    public:
        Flow();
        Flow(System *, System *);
        Flow(const Flow &);

        virtual ~Flow();

        bool setSource(System *);
        System* getSource() const;
        bool setTarget(System *);
        System* getTarget() const;

        Flow& operator=(const Flow &);
        bool operator==(const Flow &) const;

        virtual double equation() const = 0;
};