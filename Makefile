PROGRAM = Matrix

IncludePath = includes

ModulePath = modules

TestPath = tests

COMPILER = g++

run:
	$(COMPILER) $(ModulePath)/$(PROGRAM).cpp -o $(PROGRAM) -I $(IncludePath)
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