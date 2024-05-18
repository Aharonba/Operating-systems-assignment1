CC=gcc
CFLAGS= -Wall -pg 

all: main

main: main.o 
	$(CC) $(CFLAGS) -o main main.o

main.o: main.c main.h
	$(CC) $(CFLAGS) -c main.c -o main.o

clean:
	rm -f *.o gmon.out main
	
