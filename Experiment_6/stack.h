#include "LinkedList.h"

#ifndef EXPERIMENT_6_STACK_H
#define EXPERIMENT_6_STACK_H

#endif //EXPERIMENT_6_STACK_H

void push(Stack *plist, BinaryTree value) {
    pushtolinkedlist(plist, value);
}

BinaryTree pop(Stack *plist) {
    return popstack(plist);
}

bool isEmpty(Stack plist) {
    return isEmptylinkedlist(plist);
}