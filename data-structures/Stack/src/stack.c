#include "stack.h"
#include <stdlib.h>
#include <stdio.h>

Stack *newStack() {
    Stack *new = calloc(1, sizeof(Stack));
    new->size = 0;
    new->top = NULL;
    return new;
}

int top(Stack *stack) {
    if (stack->top == NULL) {
        return -1;
    }
    return stack->top->val;
}

int push(Stack *stack, int data) {
    if(stack == NULL) {
        return -1;
    }

    Node *new = malloc(sizeof(Node));
    new->val = data;
    new->next = stack->top;
    stack->top = new;
    stack->size++;

    return 1;
}

int pop(Stack *stack) {
    
    if (stack == NULL) {
        return -1;
    } else if (stack->top == NULL) {
        return -1;
    }

    Node *tmp = stack->top;
    stack->top = tmp->next;
    stack->size--;
    return tmp->val;
}

void showStack(Stack *stack) {
    if(stack == NULL) {
        return;
    } else if (stack->top == NULL) {
        return;
    }
    
    Node *cur = stack->top;
    printf("|");
    while(cur != NULL) {
        printf(" %d |", cur->val);
        cur = cur->next;
    }
    printf("\n");
}
