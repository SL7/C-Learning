#include "linked_list.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


LinkedList *newLinkedList() {
    LinkedList *list = malloc(sizeof(LinkedList));
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
    return list;
}

void showLL(LinkedList *list) {
    int i = 0;
    Node *cur = list->head; 
    printf("|");
    if (cur == NULL) {
        printf(" NULL |");
    }
    while(cur) {
        printf(" %d |", cur->val);
        cur = cur->next;
    }
    printf("\n");
}

int insertAt(LinkedList *list, int index, int data) {
    int i = 0;
    Node *cur = list->head;
    if (index == 0) { 
        return insertHead(list, data);
    } else if (index == list->size) {
        return insertTail(list, data);
    } else if (index > list->size) {
        return -1;
    }
    while (cur->next!=NULL && i < index-1) {
        cur = cur->next;
        i++;
    }
    Node *new = malloc(sizeof(Node));
    Node *tmp;
    new->val = data;
    tmp = cur->next;
    new->prev = cur;
    new->next = tmp;
    cur->next = new;
    tmp->prev = new;
    list->size++;
    return 1;
}

int insertHead(LinkedList *list, int data) {
    Node *new = malloc(sizeof(Node));
    
    if (new == NULL) {
        return -1;
    }
    new->next = list->head;
    new->prev = NULL;
    new->val = data;
    if (list->head == NULL) {
        list->tail = new;
        list->tail->next = NULL;
    }
    list->head = new;
    list->head->prev = new;
    list->size++;
    return 1;
}

int insertTail(LinkedList *list, int data) {
    if(list->tail == NULL) {
        return insertHead(list, data);
    }
    Node *new = malloc(sizeof(Node));
    new->val = data;
    new->next = NULL;
    new->prev = list->tail;
    list->tail->next = new;
    list->tail = new;
    list->size++;
    return 1;
}

int getAt(LinkedList *list, int index) {
    if (!list->size) {
        return -1;
    } else if (index >= list->size) {
        return -1;
    } else if (index == list->size-1) {
        return list->tail->val;
    } else if (index == 0) {
        return list->head->val;
    }
    Node *cur = list->head;
    int i = 0;
    while(cur && i < index) {
        cur = cur->next;
        i++;
    }
    return cur->val;
}

int deleteAt(LinkedList *list, int index) {
    if (index == 0) {
        list->head = list->head->next;
        list->size--;
        return 1;
    } else if (index == list->size-1) {
        list->tail = list->tail->prev;
        list->size--;
        return 1;
    } else if (index >= list->size) {
        return -1;
    }
    Node *cur = list->head;
    int i = 0;
    while(cur && i < index) {
        cur = cur->next;
        i++;
    }
    
    Node *tmp = cur->next;
    cur->prev->next = tmp;
    tmp->prev = cur->prev;

    return 1;

}

int getSize(LinkedList *list) {
    return list->size;
}
