.PHONY: all clean
CC=gcc
FLAGS= -Wall -Werror -g
OBJ = Ex3.o Utils.o
PROGS = Ex3.o Utils.o stringProg

all: $(PROGS)

stringProg: Ex3.o Utils.o
	$(CC) $(FLAGS) -o stringProg $(OBJ)

Ex3.o: Ex3.c Utils.h
	$(CC) $(FLAGS) -c Ex3.c

Utils.o: Utils.c
	$(CC) $(FLAGS) -c Utils.c

clean: 
	rm -f *.a *.o *.so stringProg