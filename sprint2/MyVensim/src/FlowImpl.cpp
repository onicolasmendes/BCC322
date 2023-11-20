#include "FlowImpl.h"

using namespace std;

FlowImpl::FlowImpl(){
    source = nullptr;
    target = nullptr;
}

FlowImpl::~FlowImpl(){};

FlowImpl::FlowImpl(System *s, System *t)
{
    source = s;
    target = t;
}

FlowImpl::FlowImpl(const FlowImpl &f)
{
    source = f.getSource();
    target = f.getTarget();
}

bool FlowImpl::setSource(System *s)
{
    source = s;
    return true;
}

System* FlowImpl::getSource() const
{
    return source;
}

bool FlowImpl::setTarget(System *t)
{
    target = t;
    return true;
}

System* FlowImpl::getTarget() const
{
    return target;
}

FlowImpl& FlowImpl::operator=(const FlowImpl &f)
{
    if(this == &f) return *this;

    source = f.getSource();
    target = f.getTarget();
    return *this;
}

bool FlowImpl::operator==(const FlowImpl &f) const
{
    if(this == &f) return true;

    if(source == f.getSource() && target == f.getTarget())
        return true;
    else
        return false;
}
