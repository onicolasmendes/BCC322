all: System.o Flow.o Model.o vensimLib.so FlowLogistica.o FlowExponencial.o FlowMaior.o testFlowsLib.so unitSystem.o unitFlow.o unitModel.o unit_tests.o mainFunc.o    
	@cd ../../bin && g++ -o exeUnit mainFunc.o unitSystem.o unitFlow.o unitModel.o unit_tests.o vensimLib.so testFlowsLib.so   -Wall && rm *.o
System.o: ../../src/SystemImpl.cpp 
	@g++ -c -fPIC ../../src/SystemImpl.cpp  -o ../../bin/System.o -Wall
vensimLib.so: ../../bin/Flow.o ../../bin/System.o ../../bin/Model.o
	@g++ -shared -fPIC -o ../../bin/vensimLib.so ../../bin/Model.o ../../bin/Flow.o ../../bin/System.o -Wall
testFlowsLib.so: ../../bin/FlowExponencial.o ../../bin/FlowMaior.o ../../bin/FlowLogistica.o
	@g++ -shared -fPIC -o ../../bin/testFlowsLib.so ../../bin/FlowExponencial.o ../../bin/FlowMaior.o ../../bin/FlowLogistica.o -Wall
Model.o: ../../src/ModelImpl.cpp 
	@g++ -c -fPIC ../../src/ModelImpl.cpp -o ../../bin/Model.o -Wall
Flow.o: ../../src/FlowImpl.cpp
	@g++ -c -fPIC ../../src/FlowImpl.cpp  -o ../../bin/Flow.o -Wall
mainFunc.o: main.cpp
	@g++ -c main.cpp -o ../../bin/mainFunc.o -Wall
unitModel.o: unit_Model.cpp
	@g++ -c unit_Model.cpp -o ../../bin/unitModel.o 
unitFlow.o: unit_Flow.cpp
	@g++ -c unit_Flow.cpp -o ../../bin/unitFlow.o -Wall
unitSystem.o: unit_System.cpp
	@g++ -c unit_System.cpp -o ../../bin/unitSystem.o -Wall
FlowExponencial.o: ../funcional/Flows/FlowExponencial.cpp
	@g++ -c -fPIC ../funcional/Flows/FlowExponencial.cpp  -o ../../bin/FlowExponencial.o -Wall
FlowMaior.o: ../funcional/Flows/FlowMaior.cpp
	@g++ -c -fPIC ../funcional/Flows/FlowMaior.cpp -o ../../bin/FlowMaior.o -Wall
FlowLogistica.o: ../funcional/Flows/FlowLogistica.cpp
	@g++ -c -fPIC ../funcional/Flows/FlowLogistica.cpp  -o ../../bin/FlowLogistica.o -Wall
unit_tests.o: unit_tests.cpp
	@g++ -c unit_tests.cpp  -o ../../bin/unit_tests.o -Wall
run:
	@../../bin/exeFun