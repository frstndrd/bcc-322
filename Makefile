execute:
	g++ src/*.cpp test/funcional/*.cpp -o bin/testesfuncionais -Wall

run: 
	.\bin\testesfuncionais.exe

clean:
	del .\bin\*.exe