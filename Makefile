PROGRAM = Matrix

IncludePath = include

ModulePath = module

COMPILER = g++

run:
	$(COMPILER) $(ModulePath)/$(PROGRAM).cpp -o $(PROGRAM) -I $(IncludePath)
	./$(ModulePath/)$(PROGRAM)

valgrind:
	$(COMPILER) $(ModulePath)/$(PROGRAM).cpp -o $(PROGRAM) -I $(IncludePath)
	valgrind ./$(ModulePath/)$(PROGRAM)

clean:
	rm $(PROGRAM)
