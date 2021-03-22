#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "queue.h"

int main(void) {
        
    Queue *queue = newQueue();
    enqueue(queue, 1);
    enqueue(queue, 2);
    showQueue(queue);
    dequeue(queue);
    showQueue(queue);
    dequeue(queue);
    showQueue(queue);
    dequeue(queue);
    for(int i=1; i<=10; i++) {
        enqueue(queue, i);
    }
    showQueue(queue);
    dequeue(queue);
    showQueue(queue);
    return 0;
}
