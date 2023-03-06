API:
	@cd src && g++ -shared  flowConcrete.cpp modelConcrete.cpp systemConcrete.cpp -o ../bin/myVensim.dll
	
product:
	@cd src && g++ ../test/funcional/flowExponential.cpp main.cpp -L ../bin -l myVensim -o ../bin/product.exe

functional:
	@cd bin && g++ ../test/funcional/*.cpp -L ../bin -l myVensim -o ../bin/functional.exe -lstdc++

unit:
	@cd bin && g++ ../test/unit/*.cpp ../test/funcional/flow*.cpp -L ../bin -l myVensim -o ../bin/unit.exe

runProduct:
	@cls
	@make product
	@cd bin && product.exe
	@make clean

runFunctional:
	@cls
	@make API
	@make functional
	@cd bin && functional.exe
	@make clean

runUnit:
	@cls
	@make API
	@make unit
	@cd bin && unit.exe
	@make clean

go:
	@make runProduct

clean:
	@cd bin && del *.exe /q
	@cd bin && del *.dll /q 