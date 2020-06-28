#include <cstdio>
#include <malloc.h>

typedef struct element {
    int data;
    bool isOP;
    struct element *up;
    struct element *down;
} element;

typedef struct Stack {
    element *top;
    element *buttom;
} Stack;

void push(Stack *plist, int value) {
    element *p = (element *) malloc(sizeof(element));
    p->data = value;
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

//int pop(Stack *plist) {
//    int value;
//    if (plist->top) {
//        element *p = plist->top;
//        //printf("pop element:%d\n", p->data);
//        value = p->data;
//        if (p->down) {
//            p->down->up = NULL;
//            plist->top = p->down;
//        } else {
//            plist->top = NULL;
//        }
//        free(p);
//    } else {
//        printf("no element in stack");
//    }
//    return value;
//}
//
//bool isEmpty(Stack *plist) {
//    if (plist->top == NULL) {
//        return true;
//    } else {
//        return false;
//    }
//}