#ifndef _STACK_LIB_H
#define _STACK_LIB_H

typedef struct node{
    int val;
    struct node *next;
}Node;

typedef struct {
    int size;
    Node *top;
}Stack;


Stack *newStack();

int top(Stack *stack);
int pop(Stack *stack);
int push(Stack *stack, int data);
void showStack(Stack *stack);


#endif 
