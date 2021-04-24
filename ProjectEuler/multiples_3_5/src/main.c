#include <stdio.h>
#include <stdlib.h>


int main(void) {
    int sum = 0;
    int sum2 = 0;
    for(int i = 1; i < 1000; i++) {
        if (i % 3 == 0) {
            sum += i;
        } else if (i % 5 == 0) {
            sum += i;
        }
    }

    for (int i = 1; i < 10; i++) {
        if (i % 3 == 0) {
            sum2 += i;
        } else if (i % 5 == 0) {
            sum2 += i;
        }
    }
    

    printf("Sum: %d\n", sum);
    printf("%d\n", 9 % 3);
}
