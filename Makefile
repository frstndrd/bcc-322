execute:
	g++ src/*.cpp test/funcional/*.cpp -o bin/funcional

unit:
	g++ src/*.cpp test/unit/*.cpp -o bin/unit

clean:
	del /f .\bin\*.o

veryclean:
	del /f .\bin\*.exe

run:
	./bin/funcional

runtest:
	./bin/unit