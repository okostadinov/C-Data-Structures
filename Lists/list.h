#ifndef LIST_H
#define LIST_H

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

typedef struct ListNode* List;

struct ListNode {
  int item;
  List next;
};

List newEmptyList();

int isEmptyList(List li);
void listEmptyError();
List addItemToFront(List li, int n);
List addItemAfterCurrent(List li, int n);
int firstItem(List li);
List removeFirstNode(List li);
void freeList(List li);
void visit(List li);
void visitList(List li);
void visitListRec(List li);
void listTooShort();
int itemAtPos(List li, int p);
List addItemAtPos(List li, int n, int p);
List addItemAtPosIt(List li, int n, int p);
List removeItem(List li, int n);
List removeItemIt(List li, int n);
List removeAll(List li, int n);
List addAfterEven(List li);
List addAfterOdd(List li);

#endif
