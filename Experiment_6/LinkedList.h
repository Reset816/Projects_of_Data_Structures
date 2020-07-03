#ifndef EXPERIMENT_6_LINKEDLIST_H
#define EXPERIMENT_6_LINKEDLIST_H

#include <cstdlib>
#include "BinaryTree.h"

typedef struct Element {
    BinaryTree DataofElement;
    struct Element *up;
    struct Element *down;
} Element;

typedef struct StackorQueue {
    Element *top = NULL;
    Element *buttom = NULL;
} Stack, Queue;

bool isEmpty(StackorQueue plist);

void push(StackorQueue *plist, BinaryTree value);

BinaryTree popstack(Stack *plist);

BinaryTree popqueue(Queue *plist);

#endif //EXPERIMENT_6_LINKEDLIST_H