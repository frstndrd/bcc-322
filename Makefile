execute: 
	g++ src/*.cpp test/funcional/*.cpp -o bin/funcional

clean: 
	del /f .\bin\*.o

veryclean:
	del /f .\bin\*.exe

run:
	./bin/funcional