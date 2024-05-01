# Compiler
CC = gcc

# Paths
GSL_PATH = /home/kordo/gsl/gsl-install

# Compile options
CFLAGS = -Wall -Werror

# Αρχεία .c
SRC = example.c

# Αρχεία .o
OBJS = example.o

# Το εκτελέσιμο πρόγραμμα
EXEC = example

# Παράμετροι που δίνονται κατά την εκτέλεση
ARGS =

$(EXEC): $(SRC)
	$(CC) -I $(GSL_PATH)/include -c $(SRC) $(CFLAGS)
	$(CC) -L $(GSL_PATH)/lib $(OBJS) -o $(EXEC) -lgsl -lgslcblas -lm

run: $(EXEC)
	./$(EXEC) $(ARGS)

clean:
	rm $(OBJS) $(EXEC)

valgrind: $(EXEC)
	valgrind --leak-check=full --show-leak-kinds=all ./$(EXEC)
