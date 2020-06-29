#ifndef EXPERIMENT_6_STACK_H
#define EXPERIMENT_6_STACK_H

#endif //EXPERIMENT_6_STACK_H

typedef struct ElementofStack {
    BinaryTree DataofElement;
    struct ElementofStack *up;
    struct ElementofStack *down;
} ElementofStack;

typedef struct Stack {
    ElementofStack *top = NULL;
    ElementofStack *buttom = NULL;
} Stack;

void push(Stack *plist, BinaryTree value) {
    ElementofStack *p = (ElementofStack *) malloc(sizeof(ElementofStack));
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

BinaryTree pop(Stack *plist) {
    BinaryTree value;
    if (plist->top) {
        ElementofStack *p = plist->top;
        //printf("pop element:%d\n", p->DataofElement);
        value = p->DataofElement;
        if (p->down) {
            p->down->up = NULL;
            plist->top = p->down;
        } else {
            plist->top = NULL;
            plist->buttom = NULL;
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