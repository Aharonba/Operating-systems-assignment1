CC=gcc
CFLAGS= -Wall -g -fPIC -fprofile-arcs -ftest-coverage

all: main

main: main.o 
	$(CC) $(CFLAGS) -o main main.o

main.o: main.c 
	$(CC) $(CFLAGS) -c main.c -o main.o

clean:
	rm -f *.o *.so main *.info *.gcno *.gcda *.gcov
	
