#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

void sieve_of_eratosthenes(int n);

int main(void) {
    sieve_of_eratosthenes(1000000);
    return EXIT_SUCCESS;
}


void sieve_of_eratosthenes(int n) {
    int *sieve = calloc(n+1, sizeof(int));
    for(int i = 0; i <= n; i++) {
        sieve[i] = 1;
    }
    sieve[0] = sieve[1] = 0;
    int msec = 0;
    time_t start = clock();
    for (int i = 2; i*i <= n; i++) {
        if(sieve[i]) {
            for (int j = i*i; j <= n; j += i) {
                sieve[j] = 0;
            }
        }
    }
    clock_t diff = clock() - start;
    msec = diff * 1000 / CLOCKS_PER_SEC;
    for(int i = 0, count = 0;i <= n; i++) {
        if (sieve[i]) {
            printf("%10d ", i);
            if (count == 8) {
                count = 0;
                printf("\n");
                continue;
            }
            count++;
        }
    }
    printf("\n\n[+] took %d milliseconds\n\n", msec%1000);
    free(sieve);
}
