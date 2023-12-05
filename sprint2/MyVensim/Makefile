funcional:
	@cd ./bin && g++ -c -fPIC ../test/funcional/Flows/FlowLogistica.cpp  -Wall
	@cd ./bin && g++ -c -fPIC ../test/funcional/Flows/FlowExponencial.cpp  -Wall
	@cd ./bin && g++ -c -fPIC ../test/funcional/Flows/FlowMaior.cpp  -Wall
	@cd ./bin && g++ -c -fPIC ../test/funcional/funcional_tests.cpp  -Wall
	@cd ./bin && g++ -c -fPIC ../test/funcional/main.cpp -Wall
	@cd ./bin && g++ -o exeFun ./main.o ./funcional_tests.o ./vensimLib.so ./FlowExponencial.o ./FlowLogistica.o ./FlowMaior.o  -Wall
	@cd ./bin && rm ./*.o && ./exeFun
so:
	@cd ./bin && g++ -c -fPIC ../src/SystemImpl.cpp -Wall 
	@cd ./bin && g++ -c -fPIC ../src/FlowImpl.cpp -Wall 
	@cd ./bin && g++ -c -fPIC ../src/ModelImpl.cpp -Wall 
	@cd ./bin && g++ -shared -fPIC -o ./vensimLib.so ./ModelImpl.o ./FlowImpl.o ./SystemImpl.o  && rm ./*.o
unit:
	@cd ./bin && g++ -c -fPIC ../test/unit/*.cpp -Wall
	@cd ./bin && g++ -c -fPIC ../test/funcional/Flows/FlowLogistica.cpp  -Wall
	@cd ./bin && g++ -c -fPIC ../test/funcional/Flows/FlowExponencial.cpp  -Wall
	@cd ./bin && g++ -c -fPIC ../test/funcional/Flows/FlowMaior.cpp  -Wall
	@cd ./bin && g++ -o exeUnit ./main.o ./unit_System.o ./unit_Flow.o ./unit_Model.o ./unit_handleBody.o ./unit_tests.o ./vensimLib.so ./FlowExponencial.o ./FlowLogistica.o ./FlowMaior.o -Wall
	@cd ./bin && rm ./*.o && ./exeUnit