#include <stdio.h>
#include <stdlib.h>

void swap(int *x, int *y);


int main(void) {
    
    void (*swap_int)(int *x, int *y);
    swap_int = swap;
    
    int a = 5;
    int b = 10;

    swap_int(&a, &b);

    printf("a: %d\nb: %d\n", a, b);

    return 0;
}


void swap(int *x, int *y) {
    int tmp = *x;
    *x = *y;
    *y = tmp;
}
