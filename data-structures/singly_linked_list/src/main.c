#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "singly_linked_list.h"

int main(void) {
    node *list = LinkedList();

    insertHead(&list, 2);
    insertHead(&list, 5);
    insertHead(&list, 10);
    del(&list, 0);
    insertAt(&list, 0, 20);
    insertEnd(&list, 22);
    printf("%d\n", getAt(list, 0));
    show(list);
    showReversed(list);
    printf("Elements count: %d\n", numElements(list));
    return 0;
}
