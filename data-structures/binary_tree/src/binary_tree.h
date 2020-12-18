#ifndef _BIN_TREE_H
#define _BIN_TREE_H

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int val;
    struct node *parent;
    struct node *right_node, *left_node;
} Node;

typedef struct {
    int size;
    Node *root;
}BinaryTree_t;

BinaryTree_t *BinaryTree();

#endif
