#ifndef EXPERIMENT_5_QUEUE_H
#define EXPERIMENT_5_QUEUE_H

#include <cstdlib>

typedef struct Element {
    int DataofElement;
    struct Element *up;
    struct Element *down;
} Element;

typedef struct StackorQueue {
    Element *top = NULL;
    Element *buttom = NULL;
} Stack, Queue;

bool isEmpty(StackorQueue plist);

void push(StackorQueue *plist, int value);

//int popstack(Stack *plist);

int popqueue(Queue *plist);

#endif //EXPERIMENT_5_QUEUE_H
