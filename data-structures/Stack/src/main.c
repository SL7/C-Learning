#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"


int main(void) {
    
    Stack *stack1 = newStack();

    push(stack1, 5);
    push(stack1, 10);
    showStack(stack1);
    printf("popped: %d\n", pop(stack1));
    showStack(stack1);
    push(stack1, 20);
    push(stack1, 2000);
    showStack(stack1);

    return 0;
}
