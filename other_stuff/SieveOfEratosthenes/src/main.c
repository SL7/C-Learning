#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

void sieve_of_eratosthenes(int n);

int main(void) {
    int msec = 0;
    time_t start = clock();
    sieve_of_eratosthenes(1000000);
    clock_t diff = clock() - start;
    msec = diff * 1000 / CLOCKS_PER_SEC;
    printf("\n\n[+] took %d seconds\n\n", msec/1000);

    return EXIT_SUCCESS;
}


void sieve_of_eratosthenes(int n) {
    int *sieve = calloc(n, sizeof(int));
    sieve[0] = 2;
    int count = 0;
    for (int i = 2, k = 0; i <= n; i++) {
        for (int j = 0; j < n; j++) {
            if ((i/2) < sieve[j]) {
                sieve[k++] = i;
                
                printf("%10d ", i);
                count++;
                if (count == 8) {
                    printf("\n");
                    count = 0;
                }
                break;
            }
            if (i % sieve[j] == 0) {
                break;
            }
        }
    }
    printf("\n");
    free(sieve);
}