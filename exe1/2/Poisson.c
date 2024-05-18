#include <stdio.h>
#include <math.h>
#include <stdlib.h>

//This program calculates the Poisson distribution

long double factorial(long double k);

int main (int argc, char *argv[]){
    if (argc !=3){
        printf("Error\n");
        return 0;
    }
    else{
        long double ans=0;
        long double lamda = strtold(argv[1],NULL);
        long double k = strtold(argv[2],NULL);

        ans= (pow(lamda,k)/factorial(k))*expf(-lamda);
        printf("%Lf\n",ans);
        return 0;
    }


}

long double factorial(long double k){
    if (k==0){
        return 1;
    }
    else{
        return k*factorial(k-1);
    }
}