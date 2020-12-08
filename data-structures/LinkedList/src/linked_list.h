#ifndef _LINKED_LIST_H
#define _LINKED_LIST_H

typedef struct node {
    int val;
    struct node *next, *prev;
} Node;

typedef struct linkedList {
    Node *head;
    Node *tail;
    int size;
} LinkedList;

LinkedList *newLinkedList();
int insertAt(LinkedList *list, int index, int data);
int insertHead(LinkedList *list, int data);
int insertTail(LinkedList *list, int data);
int getAt(LinkedList *list, int index);
void showLL(LinkedList *list);
int deleteAt(LinkedList *list, int index);
int getSize(LinkedList *list);

#endif
