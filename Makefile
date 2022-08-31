PROGRAM = example

IncludePath = includes
ModulePath = modules
TestPath = tests

Matrix = $(ModulePath)/Matrix.cpp $(ModulePath)/Matrix_Operations.cpp
Vector = $(ModulePath)/Vector.cpp $(ModulePath)/Vector_Operations.cpp
Polynomial = $(ModulePath)/Polynomial.cpp $(ModulePath)/Polynomial_Operations.cpp

Calculator = $(Matrix) $(Vector) $(Polynomial)

COMPILER = g++


run:
	$(COMPILER) $(PROGRAM).cpp $(Calculator) -o $(PROGRAM) -I $(IncludePath)
	./$(PROGRAM)

test:
	$(COMPILER) $(TestPath)/$(PROGRAM)_test.cpp -o $(PROGRAM)_test -I $(IncludePath)
	./$(PROGRAM)_test

valgrind:
	$(COMPILER) $(ModulePath)/$(PROGRAM).cpp -o $(PROGRAM) -I $(IncludePath)
	valgrind ./$(PROGRAM)

clean:
	rm $(PROGRAM)

clean_test:
	rm $(PROGRAM)_test