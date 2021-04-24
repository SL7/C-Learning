#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void plusMinus(int arr_count, int* arr);

int main() {
    int arr[] = {-4, 2, -9, 0, 4, 1};
    plusMinus(6, arr);

    return 0;
}

void plusMinus(int arr_count, int* arr) {
    int neg = 0, pos = 0, zero = 0;
    
    int i = 0;
    while (i < arr_count) {
        if (arr[i] < 0) {
            neg++;
        } else if (arr[i] > 0) {
            pos++;
        } else {
            zero++;
        }
        i++;
    }
    
    printf("%.6f\n%.6f\n%.6f\n",pos/(float)arr_count, neg/(float)arr_count, zero/(float)arr_count);
}

