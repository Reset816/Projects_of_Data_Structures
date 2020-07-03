#ifndef EXPERIMENT_6_LINKEDLIST_H
#define EXPERIMENT_6_LINKEDLIST_H

#endif //EXPERIMENT_6_LINKEDLIST_H

typedef struct Element {
    BinaryTree DataofElement;
    struct Element *up;
    struct Element *down;
} Element;

typedef struct Stack {
    Element *top = NULL;
    Element *buttom = NULL;
} Stack;

typedef struct Queue {
    Element *top = NULL;
    Element *buttom = NULL;
} Queue;

bool isEmptylinkedlist(Stack plist) {
    if (plist.top == NULL) {
        return true;
    } else {
        return false;
    }
}

void pushtolinkedlist(Stack *plist, BinaryTree value) {
    Element *p = (Element *) malloc(sizeof(Element));
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

BinaryTree popstack(Stack *plist) {
    BinaryTree value;
    if (plist->top) {
        Element *p = plist->top;
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

BinaryTree popqueue(Stack *plist, char type) {
    BinaryTree value;
    if (plist->buttom) {
        Element *p = plist->buttom;
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