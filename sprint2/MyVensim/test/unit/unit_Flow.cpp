#include "unit_Flow.h"

void unit_Flow_default_constructor()
{
    FlowExponencial flow;
    assert(flow.getSource() == nullptr);
    assert(flow.getTarget() == nullptr);
}

void unit_Flow_parameter_constructor()
{
    System *sourceSystem = new SystemImpl("SourceSystem");
    System *targetSystem = new SystemImpl("TargetSystem");

    FlowExponencial flow(sourceSystem, targetSystem);

    assert(flow.getSource() == sourceSystem);
    assert(flow.getTarget() == targetSystem);

    delete sourceSystem;
    delete targetSystem;
}

void unit_Flow_destructor()
{
    System *sourceSystem = new SystemImpl("SourceSystem");
    System *targetSystem = new SystemImpl("TargetSystem");
    Flow *flow = new FlowExponencial(sourceSystem, targetSystem);

    delete flow;
}

void unit_Flow_copy_constructor()
{
    System *sourceSystem = new SystemImpl("SourceSystem");
    System *targetSystem = new SystemImpl("TargetSystem");
    FlowExponencial originalFlow(sourceSystem, targetSystem);

    FlowExponencial copiedFlow(originalFlow);

    assert(copiedFlow.getSource() == sourceSystem);
    assert(copiedFlow.getTarget() == targetSystem);

    delete sourceSystem;
    delete targetSystem;
}

void unit_Flow_setSource()
{

    FlowExponencial flow;

    System *sourceSystem = new SystemImpl("SourceSystem");

    assert(flow.setSource(sourceSystem));

    assert(flow.getSource() == sourceSystem);

    delete sourceSystem;
}

void unit_Flow_getSource()
{

    FlowExponencial flow;

    System *sourceSystem = new SystemImpl("SourceSystem");

    flow.setSource(sourceSystem);

    assert(flow.getSource() == sourceSystem);

    delete sourceSystem;
}

void unit_Flow_setTarget()
{

    FlowExponencial flow;

    System *targetSystem = new SystemImpl("TargetSystem");

    assert(flow.setTarget(targetSystem));

    assert(flow.getTarget() == targetSystem);

    delete targetSystem;
}

void unit_Flow_getTarget()
{

    FlowExponencial flow;

    System *targetSystem = new SystemImpl("TargetSystem");

    flow.setTarget(targetSystem);

    assert(flow.getTarget() == targetSystem);

    delete targetSystem;
}

void unit_Flow_operator_equ()
{

    System *sourceSystem1 = new SystemImpl("SourceSystem1");
    System *targetSystem1 = new SystemImpl("TargetSystem1");
    FlowExponencial originalFlow(sourceSystem1, targetSystem1);

    FlowExponencial emptyFlow;

    emptyFlow = originalFlow;

    assert(emptyFlow == originalFlow);

    FlowExponencial *flow1 = new FlowExponencial();
    FlowExponencial *flow2 = flow1;

    assert(flow1 == flow2);

    delete sourceSystem1;
    delete targetSystem1;
    delete flow1;
}

void unit_Flow_operator_copy()
{

    System *sourceSystem1 = new SystemImpl("SourceSystem1");
    System *targetSystem1 = new SystemImpl("TargetSystem1");
    FlowExponencial flow1(sourceSystem1, targetSystem1);

    FlowExponencial flow2(sourceSystem1, targetSystem1);

    assert(flow1 == flow2);

    delete sourceSystem1;
    delete targetSystem1;
}

void run_unit_test_Flow()
{
    unit_Flow_default_constructor();
    unit_Flow_parameter_constructor();
    unit_Flow_destructor();
    unit_Flow_copy_constructor();
    unit_Flow_setSource();
    unit_Flow_getSource();
    unit_Flow_setTarget();
    unit_Flow_getTarget();
    unit_Flow_operator_equ();
    unit_Flow_operator_copy();

}