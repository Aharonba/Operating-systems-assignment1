CC=gcc
CFLAG= -Wall -g

all: main

main: main.o libpoisson.so
	$(CC) $(CFLAG) -o main main.o -L. -lpoisson

main.o: main.c libpoisson.h
	$(CC) $(FLAGS) -c  main.c -o main.o

libpoisson.so: libpoisson.c libpoisson.o
	$(CC) $(FLAGS) -shared -o libpoisson.so libpoisson.c -lm

clean:
	rm -f *.o *.so main 
