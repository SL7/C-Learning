#include "linked_list.h"
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    LinkedList *list = newLinkedList();
    insertHead(list, 5);
    insertHead(list, 10);
    insertAt(list, 1, 7);
    insertAt(list, 2, 8);
    showLL(list);
    printf("%d\n ", getAt(list, 4));
    insertTail(list, 1);
    printf("%d\n", insertAt(list, 4, 20));
    printf("LL Size: %d\n", getSize(list));
    printf("%d\n", getAt(list, 0));
    showLL(list);
    deleteAt(list, 0);
    showLL(list);
    deleteAt(list, 2);
    showLL(list);
}
