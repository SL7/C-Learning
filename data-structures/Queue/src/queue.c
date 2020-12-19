#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "queue.h"

Queue *newQueue() {
    Queue *new = malloc(sizeof(Queue)); 
    if (new == NULL) {
        return NULL;
    }
    new->size = 0;
    new->first = NULL;
    new->queue = NULL;
    return new;
}


int enqueue(Queue *queue, int data) {
    Node *new = malloc(sizeof(Node));
    if (new == NULL) {
        return -1;
    }
    new->val = data;
    if (queue->first == NULL) {
        queue->queue = new;
        queue->first = new;
        return 1;
    }
    
    new->next = NULL;
    queue->queue->next = new;
    queue->queue = new;
    return 1;
}

Node *dequeue(Queue *queue) {
    if (queue == NULL) {
        return NULL;
    } else if (queue->first == NULL) {
        return NULL;
    }
    
    Node *out = queue->first;
    
    queue->first = out->next;
    return out;
}


void showQueue(Queue *queue) {
    Node *cur = queue->first;
    if(queue == NULL) {
        printf("NULL\n");
        return;
    } else if (queue->first == NULL) {
        printf("NULL\n");
        return;
    }
    printf("|");
    while (cur != NULL) {
        printf(" %d |", cur->val);
        cur = cur->next;
    }
    printf("\n");

}
