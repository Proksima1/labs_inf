CC = gcc
CFLAGS = -std=c99 --pedantic -Wall -g

all: generate print execute	
	rm -f *.o

aaa: io.o
	echo $^
	
generate: io.o generate.o
	$(CC) $^ -o $@

print:    io.o print.o
	$(CC) $^ -o $@

execute:  io.o execute.o
	$(CC) $^ -o $@

clean:
	rm -f *.o

cleanall:
	rm -f generate print execute *.o