#include "libpoisson.h"

/**This library contains:
1. Function to calculate the Poisson distribution
2. Function to calculate an factorial
*/

long double poisson (long double lamda, long double k){

    long double ans = 0;
    ans = (pow(lamda,k)/factorial(k))*expf(-lamda);
    return ans;
    


}

long double factorial(long double k){
    if (k==0){
        return 1;
    }
    else{
        return k*factorial(k-1);
    }
}