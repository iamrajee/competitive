SHELL=/bin/bash
CC=g++
CCFLAGS=-Wall -Wextra -pedantic -g -std=c++11
# LIBS=-lpthread

p=a

all:
	make clean
	make run
clean:
	rm -f *.out
run:
	$(CC) $(CCFLAGS) $(p).cpp -o $(p).out
	# ./$(p).out
	./$(p).out < a.txt 
	# ./$(p).out < a.txt  > output.txt

