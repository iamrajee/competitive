SHELL=/bin/bash
CC=g++
CCFLAGS=-Wall -Wextra -pedantic -g -std=c++17
# LIBS=-lpthread


p=1

all:
	make clean
	make run
clean:
	rm -f *.out
run:
	$(CC) $(p).cpp -o $(p).out
	./$(p).out < 1.txt


