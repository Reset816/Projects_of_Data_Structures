#ifndef EXPERIMENT_6_STACK_H
#define EXPERIMENT_6_STACK_H

#endif //EXPERIMENT_6_STACK_H

typedef struct element {
    BinaryTree ElementofStack;
    struct element *up;
    struct element *down;
} element;

typedef struct Stack {
    element *top = NULL;
    element *buttom = NULL;
} Stack;

void push(Stack *plist, BinaryTree value) {
    element *p = (element *) malloc(sizeof(element));
    p->ElementofStack = value;
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

BinaryTree pop(Stack *plist) {
    BinaryTree value;
    if (plist->top) {
        element *p = plist->top;
        //printf("pop element:%d\n", p->ElementofStack);
        value = p->ElementofStack;
        if (p->down) {
            p->down->up = NULL;
            plist->top = p->down;
        } else {
            plist->top = NULL;
        }
        free(p);
    } else {
        printf("no element in stack");
    }
    return value;
}

bool isEmpty(Stack plist) {
    if (plist.top == NULL) {
        return true;
    } else {
        return false;
    }
}