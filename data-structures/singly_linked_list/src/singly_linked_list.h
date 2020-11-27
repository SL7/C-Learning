#ifndef SINGLY_L_L_H
#define SINGLY_L_L_H

typedef struct nodes{
    int val;
    struct nodes *next;
}node;

node * LinkedList();

void show(node *list);

void showReversed(node *list);

int insertHead(node **list, int val);

int insertAt(node **list, int index, int val);

int insertEnd(node **list, int val);

int del(node **list, int index);

int getAt(node *list, int index);

int numElements(node *list);

node* reverse(node *list);

#endif
