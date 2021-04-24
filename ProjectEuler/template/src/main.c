#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "hashmap/hashmap.h"

int main() {
    for(int i = 0; i < 100000000; i++) {
        printf("\r%d %%", i);
    }
    return 0; 
}




