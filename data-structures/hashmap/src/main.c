#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "hashmap/hashmap.h"

int main() {
    table *t = HashMap(5);
    put(t, "a", 1);
    put(t, "b", 2);
    put(t, "c", 3);
    put(t, "d", 4);
    put(t, "e", 5);    
    resize(t, 8);
    printf("%d\n", put(t, "f", 6));
    //del(t, "h");
    put(t, "fff", 255);
    //printf("%d\n", t->size);
    printf("%d\n", containsKey(t, "a"));
    printf("%d\n", containsValue(t, 1));
    printf("%d\n", getValue(t, "b"));
    printf("%d\n", getValue(t, "d"));
    printf("%d\n", getValue(t, "fff"));
    
    clear(t);
    printf("is empty = %d\n", isEmpty(t));
    
    printf("%d\n", getValue(t, "fff"));
    while(NULL) {
        printf("test");
    }
    free(t);
    return 0; 
}




