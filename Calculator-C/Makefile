# Paths
MODULES = modules
INCLUDE = include
TESTS = tests

# Compiler
CC = gcc

# Compile options
CFLAGS = -Wall -Werror -I $(INCLUDE) -lm

# Αρχεία .o
OBJS = example.o \
	$(MODULES)/Matrix.o $(MODULES)/Matrix_Operations.o \
	$(MODULES)/Vector.o $(MODULES)/Vector_Operations.o \
	$(MODULES)/Polynomial.o $(MODULES)/Polynomial_Operations.o \
	# $(TESTS)/Matrix_test.o $(TESTS)/Matrix_Operations_test.o \
	# $(TESTS)/Vector_test.o $(TESTS)/Vector_Operations_test.o

# Το εκτελέσιμο πρόγραμμα
EXEC = example

# Παράμετροι που δίνονται κατά την εκτέλεση
ARGS =

$(EXEC): $(OBJS)
	$(CC) $(OBJS) -o $(EXEC) $(CFLAGS)

run: $(EXEC)
	./$(EXEC) $(ARGS)


# TESTS

MATRIX_OBJS = $(TESTS)/Matrix_test.o $(MODULES)/Matrix.o
MATRIX_EXEC = Matrix_test

$(MATRIX_EXEC): $(MATRIX_OBJS)
	$(CC) $(MATRIX_OBJS) -o $(MATRIX_EXEC) $(CFLAGS)

###################################################################################################

MATRIX_OPERATIONS_OBJS = $(TESTS)/Matrix_Operations_test.o $(MODULES)/Matrix_Operations.o \
	$(MODULES)/Matrix.o $(MODULES)/Vector.o
MATRIX_OPERATIONS_EXEC = Matrix_Operations_test

$(MATRIX_OPERATIONS_EXEC): $(MATRIX_OPERATIONS_OBJS)
	$(CC) $(MATRIX_OPERATIONS_OBJS) -o $(MATRIX_OPERATIONS_EXEC) $(CFLAGS)

###################################################################################################

VECTOR_OBJS = $(TESTS)/Vector_test.o $(MODULES)/Vector.o
VECTOR_EXEC = Vector_test

$(VECTOR_EXEC): $(VECTOR_OBJS)
	$(CC) $(VECTOR_OBJS) -o $(VECTOR_EXEC) $(CFLAGS)

###################################################################################################

VECTOR_OPERATIONS_OBJS = $(TESTS)/Vector_Operations_test.o $(MODULES)/Vector_Operations.o \
	$(MODULES)/Vector.o $(MODULES)/Matrix.o $(MODULES)/Matrix_Operations.o
VECTOR_OPERATIONS_EXEC = Vector_Operations

$(VECTOR_OPERATIONS_EXEC): $(VECTOR_OPERATIONS_OBJS)
	$(CC) $(VECTOR_OPERATIONS_OBJS) -o $(VECTOR_OPERATIONS_EXEC) $(CFLAGS)

###################################################################################################

TESTS_OBJS = $(MATRIX_OBJS) $(MATRIX_OPERATIONS_OBJS) $(VECTOR_OBJS) $(VECTOR_OPERATIONS_OBJS)

TESTS_EXEC = $(MATRIX_EXEC) $(MATRIX_OPERATIONS_EXEC) $(VECTOR_EXEC) $(VECTOR_OPERATIONS_EXEC)

test: $(TESTS_EXEC)
	./$(MATRIX_EXEC)
	./$(MATRIX_OPERATIONS_EXEC)
	./$(VECTOR_EXEC)
	./$(VECTOR_OPERATIONS_EXEC)

clean:
	rm -f $(OBJS) $(EXEC) $(TESTS_EXEC) $(TESTS_OBJS)

valgrind: $(EXEC) $(TESTS_EXEC)
	valgrind --leak-check=full --show-leak-kinds=all ./$(MATRIX_EXEC)
	valgrind --leak-check=full --show-leak-kinds=all ./$(MATRIX_OPERATIONS_EXEC)
	valgrind --leak-check=full --show-leak-kinds=all ./$(VECTOR_EXEC)
	valgrind --leak-check=full --show-leak-kinds=all ./$(VECTOR_OPERATIONS_EXEC)
	valgrind --leak-check=full --show-leak-kinds=all ./$(EXEC) $(ARGS)
