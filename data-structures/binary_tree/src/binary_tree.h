#ifndef _BIN_TREE_H
#define _BIN_TREE_H

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int val;
    struct node *right_node, *left_node;
} binaryTree;

binaryTree *BinaryTree();

#endif
