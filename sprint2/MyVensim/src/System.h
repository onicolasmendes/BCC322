#pragma once
#include <iostream>
#include <string>

using namespace std;

class System
{
protected:
    string name;
    double value;
public:
    System();
    System(const string &);
    System(const string &, const double &);
    System(System &);

    virtual ~System();

    bool setName(const string &);
    string getName() const;
    bool setValue(const double &);
    double getValue() const;

    System& operator=(const System &);
    bool operator==(const System &) const;
};