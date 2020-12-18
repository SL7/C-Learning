#include "linked_list.h"
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    LinkedList *list = newLinkedList();
    insertHead(list, 5);
    // | 5 |
    insertHead(list, 10);
    // | 10 | 5 |
    insertAt(list, 1, 7);
    // | 10 | 7 | 5 |
    insertAt(list, 2, 8);
    // | 10 | 7 | 8 | 5 |
    showLL(list);
    printf("%d\n ", getAt(list, 4));
    insertTail(list, 1);
    // | 10 | 7 | 8 | 5 | 1 |
    printf("%d\n", insertAt(list, 4, 20));
    // | 10 | 7 | 8 | 5 | 20 | 1 |
    printf("LL Size: %d\n", getSize(list));
    printf("%d\n", getAt(list, 0));
    showLL(list);
    //showReversedLL(list);
    deleteAt(list, 0);
    // | 7 | 8 | 5 | 20 | 1 |
    showLL(list);
    deleteAt(list, 2);
    // | 7 | 8 | 20 | 1 |
    showLL(list);
    //reverse(list);
    showLL(list);
}
