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
    printf("\n%d\n\n", getAt(list, 0));
    show(list);
    showReversed(list);
    printf("\n");
    printf("Elements count: %d\n\n", numElements(list));
    list = reverse(list);
    show(list);
    showReversed(list);
    printf("\n");
    printf("%d\n\n", getAt(list, 1));
    return 0;
}
