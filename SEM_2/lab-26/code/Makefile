CC = gcc
CFLAGS = -std=c99 --pedantic -Wall

compile: main.o stack.o
	$(CC) $^ -o main
	rm -rf *.o

clean:
	rm -rf main *.o
