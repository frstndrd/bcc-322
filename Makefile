funcional:
	g++ src/*.cpp test/funcional/*.cpp -o bin/funcional

unit:
	g++ src/*.cpp test/unit/*.cpp test/funcional/flow*.cpp -o bin/unit

clean:
	del /f .\bin\*.o

veryclean:
	del /f .\bin\*.exe

run_funcional:
	./bin/funcional

run_unit:
	./bin/unit