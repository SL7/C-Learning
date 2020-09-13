#include <stdio.h>
#include <stdlib.h>
#include "singly_linked_list.h"


node * LinkedList() {
    return NULL;
}

int insertHead(node **list, int val) {   
    node * new = (node *) malloc(sizeof(node));
    new->val = val;
    new->next = *list;
    *list = new;
    return 0;
}

int insertAt(node **list, int index, int val) {
    node * cur = malloc(sizeof(node));
    node *temp = malloc(sizeof(node));
    temp->val = val;
    int i;
    i = 0;
    cur = *list;
    if (index == 0) {
        temp->next = *list;
        *list = temp;
    } else {
             
        while (cur != NULL && i < index - 1) {
            cur = cur->next;
            i++;
        }
        if (cur == NULL) {
            return -1;
        } else {
            temp->next = cur->next;
            cur->next = temp;
            return 0;
        }
    } 
    return 0; 
}

int insertEnd(node **list, int val) {
    node *temp = malloc(sizeof(node));
    node *cur = malloc(sizeof(node));

    cur = *list;
    while(cur->next != NULL) {
        cur = cur->next;
    }
    temp->val = val;
    temp->next = cur->next;
    cur->next = temp;
    return 0; 
}

int getAt(node *list, int index) { 
    node *cur = list;
    int i = 0;
    while(cur != NULL && i < index) {
        cur = cur->next;
        i++;
    }
    if (cur == NULL) {
        return -1;
    }
    return cur->val;
}

int del(node **list, int index) {
    node *cur = *list;
    int i = 0;
    if (index == 0) {
        *list = (*list)->next;
        return 0;
    } else {
        while (cur != NULL && i < index-1) {
            cur = cur->next;
            i++;
        }
        if (cur == NULL) {
            return -1;
        }
        cur->next = cur->next->next;
    }
    return 0;
}


void show(node *list) {
    node *cur = (node *) NULL;
    node test;
    cur = list;
    printf("#");
    while (cur != NULL) {
        printf(" %d #", cur->val);
        cur = cur->next;
    }
    printf("\n");
}
