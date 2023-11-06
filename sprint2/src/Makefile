all: Flow.o System.o Model.o mainSrc.o
	@g++ ../bin/Flow.o ../bin/System.o ../bin/Model.o ../bin/mainSrc.o -o ../bin/exeSrc -Wall
mainSrc.o: mainSrc.cpp
	@g++ -c mainSrc.cpp -o ../bin/mainSrc.o -Wall
System.o: System.cpp
	@g++ -c System.cpp  -o ../bin/System.o -Wall
Model.o: Model.cpp
	@g++ -c Model.cpp -o ../bin/Model.o -Wall
Flow.o: Flow.cpp
	@g++ -c Flow.cpp  -o ../bin/Flow.o -Wall
run:
	@./exe