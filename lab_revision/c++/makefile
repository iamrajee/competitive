SHELL=/bin/bash
CC=g++
CCFLAGS=-Wall -Wextra -pedantic -g -std=c++11
# LIBS=-lpthread


p=3

all:
	make clean
	make run
clean:
	rm -f *.out
run:
	$(CC) $(p).cpp -o $(p).out
	./$(p).out


