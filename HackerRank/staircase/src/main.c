#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void staircase(int n);

int main() {
    staircase(6);
    return 0;
}


void staircase(int n) {
    for (int i = 1; i <= n; i++) {
        for(int j = 1; j <= n-i; j++) {
            printf(" ");
        }
        for( int j = 1; j <= i; j++) {
            printf("#");
        }
        printf("\n");
    }
}
