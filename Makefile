execute:
	g++ src/*.cpp test/funcional/*.cpp -o bin/testesfuncionais -Wall

run: 
	.\bin\testesfuncionais.exe

clear:
	del .\bin\*.exe