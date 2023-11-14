#include "SystemImpl.h"

SystemImpl::SystemImpl(){}

SystemImpl::~SystemImpl(){};

SystemImpl::SystemImpl(const string &n)
{
    name = n;
}

SystemImpl::SystemImpl(const string &n, const double &v)
{
    name = n;
    value = v;
}

SystemImpl::SystemImpl(SystemImpl &s)
{

    name = s.getName();
    value = s.getValue();
}


bool SystemImpl::setName(const string &n)
{
    name = n;
    return true;
}

string SystemImpl::getName() const
{
    return name;
}

bool SystemImpl::setValue(const double &v)
{
    value = v;
    return true;
}

double SystemImpl::getValue() const
{
    return value;
}

SystemImpl& SystemImpl::operator=(const SystemImpl &s)
{
    if(this == &s) return *this;

    name = s.getName();
    value = s.getValue();
    return *this;
}

bool SystemImpl::operator==(const SystemImpl &s) const
{
    if(this == &s) return true;

    if(name == s.getName() && value == s.getValue())
    {
        return true;
    }
    else
    {
        return false;
    }
}

