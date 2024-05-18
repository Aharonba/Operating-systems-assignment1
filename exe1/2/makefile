all: Poisson

Poisson: Poisson.o
	gcc -Wall -g Poisson.o -o Poisson -lm

Poisson.o: Poisson.c
	gcc -Wall -g -c Poisson.c -o Poisson.o 


clean:
	rm -f Poisson Poisson.o