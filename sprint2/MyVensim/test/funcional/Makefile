all: System.o Flow.o Model.o vensimLib.so FlowLogistica.o FlowExponencial.o FlowMaior.o testFlowsLib.so funcional_tests.o mainFunc.o    
	@cd ../../bin && g++ -o exeFun ./mainFunc.o ./funcional_tests.o  ./vensimLib.so ./testFlowsLib.so   -Wall && rm *.o && ./exeFun ./testFlowsLib.so
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
FlowExponencial.o: Flows/FlowExponencial.cpp
	@g++ -c -fPIC Flows/FlowExponencial.cpp  -o ../../bin/FlowExponencial.o -Wall
FlowMaior.o: Flows/FlowMaior.cpp
	@g++ -c -fPIC Flows/FlowMaior.cpp -o ../../bin/FlowMaior.o -Wall
FlowLogistica.o: Flows/FlowLogistica.cpp
	@g++ -c -fPIC Flows/FlowLogistica.cpp  -o ../../bin/FlowLogistica.o -Wall
funcional_tests.o: funcional_tests.cpp
	@g++ -c funcional_tests.cpp  -o ../../bin/funcional_tests.o -Wall
run:
	@../../bin/exeFun