all: FlowLogistica.o FlowExponencial.o FlowMaior.o Flow.o Model.o System.o  UnitFlow.o UnitSystem.o UnitModel.o UnitTests.o mainUnit.o
	@g++ ../../bin/FlowLogistica.o ../../bin/Model.o ../../bin/System.o ../../bin/Flow.o ../../bin/UnitFlow.o ../../bin/UnitModel.o ../../bin/UnitTests.o ../../bin/mainUnit.o ../../bin/UnitSystem.o ../../bin/FlowExponencial.o ../../bin/FlowMaior.o  -o ../../bin/exeUnit -Wall
System.o: ../../src/SystemImpl.cpp
	@g++ -c ../../src/SystemImpl.cpp  -o ../../bin/System.o -Wall
Model.o: ../../src/ModelImpl.cpp
	@g++ -c ../../src/ModelImpl.cpp -o ../../bin/Model.o -Wall
Flow.o: ../../src/FlowImpl.cpp
	@g++ -c ../../src/FlowImpl.cpp  -o ../../bin/Flow.o -Wall
mainUnit.o: main.cpp
	@g++ -c main.cpp -o ../../bin/mainUnit.o -Wall
FlowExponencial.o: ../funcional/Flows/FlowExponencial.cpp
	@g++ -c ../funcional/Flows/FlowExponencial.cpp  -o ../../bin/FlowExponencial.o -Wall
FlowMaior.o: ../funcional/Flows/FlowMaior.cpp
	@g++ -c ../funcional/Flows/FlowMaior.cpp -o ../../bin/FlowMaior.o -Wall
FlowLogistica.o: ../funcional/Flows/FlowLogistica.cpp
	@g++ -c ../funcional/Flows/FlowLogistica.cpp  -o ../../bin/FlowLogistica.o -Wall
UnitFlow.o: unit_Flow.cpp
	@g++ -c unit_flow.cpp  -o ../../bin/UnitFlow.o -Wall
UnitSystem.o: unit_System.cpp
	@g++ -c unit_System.cpp  -o ../../bin/UnitSystem.o -Wall
UnitModel.o: unit_Model.cpp
	@g++ -c unit_Model.cpp  -o ../../bin/UnitModel.o -Wall
UnitTests.o: unit_tests.cpp
	@g++ -c unit_tests.cpp  -o ../../bin/UnitTests.o -Wall
run:
	@../../bin/exeFun