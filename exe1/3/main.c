#include "libpoisson.h"


int main(){

  long double arr[5][2] =
   {
        {2.0, 1.0},
        {2.0, 10.0},
        {2.0, 2.0},
        {3.0, 3.0},
        {100.0, 3.0}
    };

    /**The following loop will go through any two values for which we were asked to calculate a Poisson distribution and print the result.*/

for(int i=0; i<5; i++){
   long double ans = poisson(arr[i][0],arr[i][1]);
    printf("For the %d value the result of the distribution is %Lf\n", i+1, ans);
}


return 0;
}