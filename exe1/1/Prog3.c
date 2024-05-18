#include <stdio.h>


int main(){

int x;
int* p;

p=(int*)0xdeadbeef;
x= *p;


 printf("Value at undefined address: %d\n", x);


    return 0;
}