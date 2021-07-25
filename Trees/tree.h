#ifndef TREE_H
#define TREE_H

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

typedef struct TreeNode *Tree;

struct TreeNode {
  int item;
  Tree leftChild, rightChild;
};

Tree emptyTree();
Tree newTree(int n, Tree tL, Tree tR);
Tree makeTree(int size);
void freeTree(Tree t);
int numberOfNodes(Tree t);
Tree copy(Tree t);
int height(Tree t);
void printPreOrder(Tree t);
void printInOrder(Tree t);
void printPostOrder(Tree t);
void treeToArrayRec(Tree t, int **arr, int n);
Tree arrayToTreeRec(int *array, int n, int p);

#endif
