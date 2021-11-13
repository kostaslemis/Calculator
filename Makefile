COMPILER = g++

PROGRAM = Matrix

run:
	$(COMPILER) $(PROGRAM).cpp -o $(PROGRAM)
	./$(PROGRAM)

valgrind:
	$(COMPILER) $(PROGRAM).cpp -o $(PROGRAM)
	valgrind $(PROGRAM)

clean:
	rm $(PROGRAM)
