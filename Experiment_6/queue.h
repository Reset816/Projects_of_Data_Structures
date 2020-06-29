#ifndef EXPERIMENT_6_QUEUE_H
#define EXPERIMENT_6_QUEUE_H

#endif //EXPERIMENT_6_QUEUE_H

typedef struct ElementofQueue {
    BinaryTree DataofElement;
    struct ElementofQueue *up;
    struct ElementofQueue *down;
} ElementofQueue;

typedef struct Queue {
    ElementofQueue *top = NULL;
    ElementofQueue *buttom = NULL;
} Queue;

void push(Queue *plist, BinaryTree value) {
    ElementofQueue *p = (ElementofQueue *) malloc(sizeof(ElementofQueue));
    p->DataofElement = value;
    p->up = NULL;
    p->down = plist->top;
    if (plist->top) {
        plist->top->up = p;
        plist->top = p;
    } else {
        plist->top = p;
        plist->buttom = p;
    }
}

BinaryTree pop(Queue *plist) {
    BinaryTree value;
    if (plist->buttom) {
        ElementofQueue *p = plist->buttom;
        //printf("pop element:%d\n", p->DataofStack);
        value = p->DataofElement;
        if (p->up) {
            p->up->down = NULL;
            plist->buttom = p->up;
        } else {
            plist->top = NULL;
            plist->buttom = NULL;
        }
        free(p);
    } else {
        printf("no element in Queue");
    }
    return value;
}

bool isEmpty(Queue plist) {
    if (plist.buttom == NULL) {
        return true;
    } else {
        return false;
    }
}