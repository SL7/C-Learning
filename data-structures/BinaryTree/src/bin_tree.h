#ifndef _BIN_TREE_LIB_H
#define _BIN_TREE_LIB_H

typedef struct node {
    struct node *left, *right;
    int data;
} Node;

typedef struct {
    Node *tree;
    int size;
} BinaryTree;


BinaryTree *newBinaryTree();



#endif
