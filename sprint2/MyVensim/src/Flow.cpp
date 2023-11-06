#include "Flow.h"


using namespace std;

Flow::Flow(){};

Flow::~Flow(){};

Flow::Flow(System *s, System *t)
{
    source = s;
    target = t;
}

Flow::Flow(const Flow &f)
{
    if(this == &f) return;

    source = f.getSource();
    target = f.getTarget();
}

bool Flow::setSource(System *s)
{
    source = s;
    return true;
}

System* Flow::getSource() const
{
    return source;
}

bool Flow::setTarget(System *t)
{
    target = t;
    return true;
}

System* Flow::getTarget() const
{
    return target;
}

Flow& Flow::operator=(const Flow &f)
{
    if(this == &f) return *this;

    source = f.getSource();
    target = f.getTarget();
    return *this;
}

bool Flow::operator==(const Flow &f) const
{
    if(this == &f) return true;

    if(source == f.getSource() && target == f.getTarget())
        return true;
    else
        return false;
}

double Flow::equation() const
{
    return 4;
}


