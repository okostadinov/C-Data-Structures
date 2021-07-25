#include "tree.h"

Tree emptyTree() {
  return NULL;
}

Tree newTree(int n, Tree tL, Tree tR) {
  Tree new = malloc(sizeof(struct TreeNode));
  assert(new != NULL);
  new->item = n;
  new->leftChild = tL;
  new->rightChild = tR;
  return new;
}

Tree makeTreeRec(int *arr, int p, int size) {

  if (p > size || arr[p - 1] == -1) {
    return NULL;
  }

  Tree tL = makeTreeRec(arr, p * 2, size);
  Tree tR = makeTreeRec(arr, p * 2 + 1, size);

  return newTree(arr[p - 1], tL, tR);
}

Tree makeTree(int size) {
  int *arr = malloc(size * sizeof(int));
  for (int idx = 0; idx < size; ++idx) {
    if (!scanf("%d", &arr[idx])) {
      printf("input not scanned correctly\n");
    }
  }
  Tree tr = makeTreeRec(arr, 1, size);
  free(arr);
  return tr;
}

void freeTree(Tree t) {
    if (t == NULL) {
        return;
    }
    freeTree(t->leftChild);
    freeTree(t->rightChild);
    free(t);
}

int numberOfNodes(Tree t) {
    if (t == NULL) {
        return 0;
    } else {
        return 1 + numberOfNodes(t->leftChild) + numberOfNodes(t->rightChild);
    }
}

Tree copy(Tree t) {
    Tree t1 = emptyTree();
    if (t == NULL) {
        return t1;
    }
    t1 = newTree(t->item, t->leftChild, t->rightChild);
    t1->leftChild = copy(t->leftChild);
    t1->rightChild = copy(t->rightChild);
    return t1;
}

int height(Tree t) {
    if (t == NULL) {
        return -1;
    } else {
        int heightLeft = height(t->leftChild);
        int heightRight = height(t->rightChild);
        if (heightLeft > heightRight) {
            return heightLeft + 1;
        } else {
            return heightRight + 1;
        }
    }
}

void printPreOrder(Tree t) {
    if (t != NULL) {
        printf("%d ", t->item);
        printPreOrder(t->leftChild);
        printPreOrder(t->rightChild);
    }
    return;
}

void printInOrder(Tree t) {
    if (t != NULL) {
        printInOrder(t->leftChild);
        printf("%d ", t->item);
        printInOrder(t->rightChild);
    }
    return;
}

void printPostOrder(Tree t) {
    if (t != NULL) {
        printPostOrder(t->leftChild);
        printPostOrder(t->rightChild);
        printf("%d ", t->item);
    }
    return;
}

/* Function takes input pointer to an array and position n of current node in tree */
void treeToArrayRec(Tree t, int **arr, int n) {
    if (t == NULL) {
        return;
    }

    (*arr)[n] = t->item;                                // current node's indexed position in array is set to respective value
    treeToArrayRec(t->leftChild, arr, n*2);             // call recursively for left child, which is at 2 times current position
    treeToArrayRec(t->rightChild, arr, 2*n+1);          // and for right child, which is at 2 time current position plus 1
}

/* Here n is length of array, while p is current position in tree */
Tree arrayToTreeRec(int *array, int n, int p) {
    if (n <= p || array[p] == -1) {                     // if n is less than or equal to p, we have reached the end of the array
        return NULL;                                    // likewise, if the value at the current position is -1, that node is empty by implication
    }

    Tree t = malloc(sizeof(struct TreeNode));            // Create the new node
    assert (t != NULL);
    t->item = array[p];                                 // Set its value to value at current position in the array
    t->leftChild = arrayToTreeRec(array, n, 2*p);
    t->rightChild = arrayToTreeRec(array, n, 2*p+1);    // Call self for left and right child of current node
    return t;
}
