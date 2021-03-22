#include <stdio.h>
#include <stdlib.h>


int fac(int n);


int main(void) {

    printf("Fac 0 = %d\n", fac(0)); 
    printf("Fac 1 = %d\n", fac(1)); 
    printf("Fac 4 = %d\n", fac(4)); 
    printf("Fac -1 = %d\n", fac(-1)); 

    return 0;
}


int fac(int n) {
    return ((n <= 1) ? (n<0 ? 0 : 1) : n * fac(n-1));
}


