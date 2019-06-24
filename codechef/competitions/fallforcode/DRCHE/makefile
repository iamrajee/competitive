SHELL=/bin/bash
CC=g++
CCFLAGS=-Wall -Wextra -pedantic -g -std=c++11

p=c

all:
	make clean
	make run
clean:
	rm -f *.out
run:
	$(CC) $(CCFLAGS) $(p).cpp -o o.out
	# ./o.out
	./o.out < t.txt 
	# ./o.out < t.txt  > output.txt