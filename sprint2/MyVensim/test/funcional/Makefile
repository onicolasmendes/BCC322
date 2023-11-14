all: FlowLogistica.o FlowExponencial.o FlowMaior.o mainFunc.o Flow.o Model.o System.o funcional_tests.o 
	@g++ ../../bin/FlowLogistica.o ../../bin/Model.o ../../bin/System.o ../../bin/Flow.o ../../bin/FlowExponencial.o ../../bin/FlowMaior.o ../../bin/mainFunc.o ../../bin/funcional_tests.o -o ../../bin/exeFun -Wall
System.o: ../../src/System.cpp
	@g++ -c ../../src/System.cpp  -o ../../bin/System.o -Wall
Model.o: ../../src/Model.cpp
	@g++ -c ../../src/Model.cpp -o ../../bin/Model.o -Wall
Flow.o: ../../src/Flow.cpp
	@g++ -c ../../src/Flow.cpp  -o ../../bin/Flow.o -Wall
mainFunc.o: main.cpp
	@g++ -c main.cpp -o ../../bin/mainFunc.o -Wall
FlowExponencial.o: Flows/FlowExponencial.cpp
	@g++ -c Flows/FlowExponencial.cpp  -o ../../bin/FlowExponencial.o -Wall
FlowMaior.o: Flows/FlowMaior.cpp
	@g++ -c Flows/FlowMaior.cpp -o ../../bin/FlowMaior.o -Wall
FlowLogistica.o: Flows/FlowLogistica.cpp
	@g++ -c Flows/FlowLogistica.cpp  -o ../../bin/FlowLogistica.o -Wall
funcional_tests.o: funcional_tests.cpp
	@g++ -c funcional_tests.cpp  -o ../../bin/funcional_tests.o -Wall
run:
	@../../bin/exeFun