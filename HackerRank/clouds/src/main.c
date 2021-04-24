#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int clouds(int n, int *arr);

int main(void) {
    int arr[7] = {0,0,1,0,0,1,0};
    printf("%d\n", clouds(7, arr));
    int arr2[7] = {0,1,0,0,0,1,0};
    printf("%d\n", clouds(7, arr2));

    return 0;
}

int clouds(int n, int *arr) {
    for(int i = 0; i < n; i++) {
        printf("%d\n", arr[i]);
    }
    int jumps = 0;
    for(int i = 0; i < n;) {
        if (i == n-2 && arr[i+1] != 1) {
            jumps += 1;
            return jumps;
        } else if (arr[i+2] == 0 && arr[i+1] == 1) {
            jumps += 1;
            i += 2;
        } else if (arr[i+2] == 1 && arr[i+1] == 0) {
            jumps += 1;
            i += 1;
        } else if (arr[i+1] == 0 && arr[i+2] == 0) {
            jumps += 1;
            i+=2;
        } else if (arr[i+1] == 1 && arr[i+2] == 1) {
            return 0;
        }
    }
    return jumps;
}
