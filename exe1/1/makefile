CC = gcc
CFLAGS= -Wall -g

all: Prog1 Prog2 Prog3

Prog1: Prog1.o
	$(CC) $(CFLAGS) -o Prog1 Prog1.o

Prog2: Prog2.o
	$(CC) $(CFLAGS) -o Prog2 Prog2.o

Prog3: Prog3.o
	$(CC) $(CFLAGS) -o Prog3 Prog3.o

Prog1.o: Prog1.c
	$(CC) $(CFLAGS) -c Prog1.c -o Prog1.o


prog2.o: prog2.c
	$(CC) $(CFLAGS) -c Prog2.c -o Prog2.o


prog3.o: prog3.c
	$(CC) $(CFLAGS) -c Prog3.c -o Prog3.o

clean:
	rm -f *.o core* Prog1 Prog2 Prog3 