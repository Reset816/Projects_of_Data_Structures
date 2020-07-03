#include "LinkedList.h"

#ifndef EXPERIMENT_6_QUEUE_H
#define EXPERIMENT_6_QUEUE_H

#endif //EXPERIMENT_6_QUEUE_H

void push(Stack *plist, BinaryTree value) {
    pushtolinkedlist(plist, value);
}

BinaryTree pop(Stack *plist) {
    return popqueue(plist);
}

bool isEmpty(Stack plist) {
    return isEmptylinkedlist(plist);
}