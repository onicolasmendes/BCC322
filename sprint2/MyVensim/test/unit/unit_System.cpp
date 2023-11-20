#include "unit_System.h"

void unit_System_default_constructor() {
    SystemImpl system;
    assert(system.getName().empty());
}

void unit_System_parameter_constructor() {
    SystemImpl system("TestName");
    assert(system.getName() == "TestName");

    SystemImpl system1("TestName", 42.5);
    assert(system1.getName() == "TestName");
    assert(system1.getValue() == 42.5);
}

void unit_System_destructor()
{
    {
        SystemImpl *systemPtr = new SystemImpl("TesteDestructor");
        delete systemPtr;
    }
}

void unit_System_copy_constructor()
{
    SystemImpl original("TesteCopyConstructor", 42.0);
    SystemImpl copy(original);
    assert(copy.getName() == original.getName());
    assert(copy.getValue() == original.getValue());
}

void unit_System_set_name()
{
    SystemImpl system;
    assert(system.setName("NovoNome"));
    assert(system.getName() == "NovoNome");
}

void unit_System_get_name()
{
    SystemImpl system("TestGetName");
    assert(system.getName() == "TestGetName");
}

void unit_System_set_value()
{
    SystemImpl system;
    assert(system.setValue(42));
    assert(system.getValue() == 42);
}

void unit_System_get_value()
{
    SystemImpl system("TestGetValue", 21);
    assert(system.getValue() == 21);
}

void unit_System_operator_copy()
{
    SystemImpl system1("Original", 10);
    SystemImpl system2;
    system2 = system1;
    assert(system1 == system2);
}

void unit_System_operator_equi()
{
    SystemImpl system1("EqualTest", 5);
    SystemImpl system2("EqualTest", 5);
    assert(system1 == system2);

    SystemImpl *system3 = new SystemImpl();
    SystemImpl *system4 = system3;

    assert(system3 == system4);

    delete system3; 
}

void run_unit_test_System()
{
   unit_System_default_constructor();
   unit_System_parameter_constructor();
   unit_System_destructor();
   unit_System_copy_constructor();
   unit_System_set_name();
   unit_System_get_name();
   unit_System_set_value();
   unit_System_get_value();
   unit_System_operator_equi();
   unit_System_operator_copy();
}