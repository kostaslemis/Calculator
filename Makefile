# compiler
CC = g++

# paths
IncludePath = include
ModulePath = modules
TestPath = tests

# compile options
CFLAGS = -Wall -Werror -I $(IncludePath)

Fraction = $(ModulePath)/Fraction.cpp $(ModulePath)/Fraction_Operations.cpp
Matrix = $(ModulePath)/Matrix.cpp $(ModulePath)/Matrix_Operations.cpp
Polynomial = $(ModulePath)/Polynomial.cpp $(ModulePath)/Polynomial_Operations.cpp
Vector = $(ModulePath)/Vector.cpp $(ModulePath)/Vector_Operations.cpp
CSR_Format_Matrix = $(ModulePath)/CSR_Format_Matrix.cpp $(ModulePath)/CSR_Format_Matrix_Operations.cpp

Calculator = $(Fraction) $(Matrix) $(Polynomial) $(Vector) $(CSR_Format_Matrix)

PROGRAM = example

run:
	$(CC) $(PROGRAM).cpp $(Calculator) -o $(PROGRAM) $(CFLAGS)
	./$(PROGRAM)

test:
	$(CC) $(TestPath)/$(PROGRAM)_test.cpp -o $(PROGRAM)_test $(CFLAGS)
	./$(PROGRAM)_test

valgrind:
	$(CC) $(PROGRAM).cpp $(Calculator) -o $(PROGRAM) $(CFLAGS)
	valgrind ./$(PROGRAM)

clean:
	rm $(PROGRAM)

clean_test:
	rm $(PROGRAM)_test
