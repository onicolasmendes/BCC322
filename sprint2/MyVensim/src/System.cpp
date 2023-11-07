#include "System.h"

System::System(){};

System::~System(){};

System::System(const string &n)
{
    name = n;
}

System::System(const string &n, const double &v)
{
    name = n;
    value = v;
}

System::System(System &s)
{

    name = s.getName();
    value = s.getValue();
}


bool System::setName(const string &n)
{
    name = n;
    return true;
}

string System::getName() const
{
    return name;
}

bool System::setValue(const double &v)
{
    value = v;
    return true;
}

double System::getValue() const
{
    return value;
}

System& System::operator=(const System &s)
{
    if(this == &s) return *this;

    name = s.getName();
    value = s.getValue();
    return *this;
}

bool System::operator==(const System &s) const
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

