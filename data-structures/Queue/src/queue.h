#ifndef _QUEUE_LIB_H
#define _QUEUE_LIB_H

typedef struct node {
    int val;
    struct node *next;
}Node;

typedef struct {
    int size;
    Node *first;
    Node *queue;
}Queue;


Queue *newQueue();
int enqueue(Queue *queue, int data);
Node *dequeue(Queue *queue);
int first(Queue *queue);
void showQueue(Queue *queue);



#endif
