#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hashmap.h"


table *HashMap(int size) {
    table *temp = (table*) malloc(sizeof(table));
    temp->list = (node**) malloc(size * sizeof(node*));
    temp->size = size;
    temp->element_count = 0;
    for (int i = 0; i < size; i++) {
        temp->list[i] = malloc(sizeof(node));
        temp->list[i] = NULL;
    }
    return temp;
}


int containsKey(table *t, char *key) {
    for(int i = 0; i < t->size && t->list[i] != NULL; i++) {
        if (strcmp(t->list[i]->key, key) == 0) {
            return i;
        }
    }
    return -1;
}


int put(table *t, char *key, int val) {
    node *temp = (node*)malloc(sizeof(node));
    int pos;
    if ((pos = containsKey(t, key)) != -1) {
        t->list[pos]->val = val;
        return 1;
    } else {
        if (t->element_count < t->size) {
            int i;
            for(i = 0; i < t->size && t->list[i] != NULL; i++);
            temp->key = key;
            temp->val = val;
            t->list[i] = temp;
            t->element_count++;
            return 1;
        } else {
            return 0;
        }
    }
}


int getValue(table *t, char *key) {
    int pos;
    if ((pos = containsKey(t, key)) != -1) {
        return t->list[pos]->val;
    }
    return -1;
}


int del(table *t, char *key) {
    int pos;
    if ((pos = containsKey(t, key)) != -1) {
        t->list[pos] = (node*) malloc(sizeof(node));
        t->list[pos] = NULL;
        return 1;
    }
    return -1;
}


int resize(table *t, int new_size) {
    int size = t->size;
    if(size >= new_size) {
        return -1;
    } else {
        t->list = (node**)realloc(t->list, new_size*sizeof(node*));
        t->size = new_size;
        return 1;
    }
}


int containsValue(table *t, int value) {
    if (t->element_count > 0) {
        int i;
        for(i = 0; i < t->size; i++) {
            if (t->list[i] != NULL && t->list[i]->val == value) {
                return i;
            }
        }
    }
    return -1;
}


int isEmpty(table *t) {
    if (t->element_count == 0) {
        return 1;
    } else {
        return 0;
    }
}


void clear(table *t) {
    int i;
    for (i = 0; i < t->size; i++) {
        t->list[i] = NULL;
    }
    t->element_count = 0;
}
