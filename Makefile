all_unit: ./test/unit/main.cpp unit_model.dll unit_flow.dll unit_system.dll modelConcrete.dll flowConcrete.dll systemConcrete.dll flowLogistical.dll flowExponential.dll model.dll flow.dll system.dll
	g++ ./test/unit/main.cpp -o ./bin/unit_tests ./bin/modelConcrete.dll ./bin/flowConcrete.dll ./bin/systemConcrete.dll ./bin/flowLogistical.dll ./bin/flowExponential.dll ./bin/unit_model.dll ./bin/unit_flow.dll ./bin/unit_system.dll

all_funcional: ./test/funcional/main.cpp funcional_tests.dll model.dll flow.dll system.dll modelConcrete.dll flowConcrete.dll systemConcrete.dll flowLogistical.dll flowExponential.dll
	g++ ./test/funcional/main.cpp -o ./bin/funcional_tests ./bin/modelConcrete.dll ./bin/flowConcrete.dll ./bin/systemConcrete.dll ./bin/flowLogistical.dll ./bin/flowExponential.dll ./bin/funcional_tests.dll

system.dll: ./src/system.h 
	g++ -Wall -g -c ./src/system.h -o ./bin/system.dll

systemConcrete.dll: ./src/systemConcrete.cpp ./src/systemConcrete.h system.dll
	g++ -Wall -g -c ./src/systemConcrete.cpp -o ./bin/systemConcrete.dll

flow.dll: ./src/flow.h system.dll
	g++ -Wall -g -c ./src/flow.h -o ./bin/flow.dll

flowConcrete.dll: ./src/flowConcrete.cpp ./src/flowConcrete.h flow.dll
	g++ -Wall -g -c ./src/flowConcrete.cpp -o ./bin/flowConcrete.dll

model.dll: ./src/model.h flow.dll
	g++ -Wall -g -c ./src/model.h -o ./bin/model.dll

modelConcrete.dll: ./src/modelConcrete.cpp ./src/modelConcrete.h model.dll
	g++ -Wall -g -c ./src/modelConcrete.cpp -o ./bin/modelConcrete.dll

flowLogistical.dll: ./test/funcional/flowLogistical.cpp ./test/funcional/flowLogistical.h flow.dll
	g++ -Wall -g -c ./test/funcional/flowLogistical.cpp -o ./bin/flowLogistical.dll

flowExponential.dll: ./test/funcional/flowExponential.cpp ./test/funcional/flowExponential.h flow.dll
	g++ -Wall -g -c ./test/funcional/flowExponential.cpp -o ./bin/flowExponential.dll

funcional_tests.dll: ./test/funcional/funcional_tests.cpp ./test/funcional/funcional_tests.h model.dll flow.dll system.dll
	g++ -Wall -g -c ./test/funcional/funcional_tests.cpp -o ./bin/funcional_tests.dll

unit_system.dll: ./test/unit/unit_system.cpp ./test/unit/unit_system.h system.dll
	g++ -Wall -g -c ./test/unit/unit_system.cpp -o ./bin/unit_system.dll

unit_flow.dll: ./test/unit/unit_flow.cpp ./test/unit/unit_flow.h flow.dll system.dll
	g++ -Wall -g -c ./test/unit/unit_flow.cpp -o ./bin/unit_flow.dll

unit_model.dll: ./test/unit/unit_model.cpp ./test/unit/unit_model.h unit_flow.dll model.dll flow.dll system.dll
	g++ -Wall -g -c ./test/unit/unit_model.cpp -o ./bin/unit_model.dll

run_unit:
	./bin/unit_tests

run_funcional:
	./bin/funcional_tests

clean:
	del /f .\bin\*.o

veryclean:
	del .\bin\*