#include "queue.h"
#include <cstdio>

bool isEmpty(StackorQueue plist) {
    if (plist.top == NULL) {
        return true;
    } else {
        return false;
    }
}

void push(StackorQueue *plist, int value) {
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

//int popstack(Stack *plist) {
//    int value;
//    if (plist->top) {
//        Element *p = plist->top;
//        //printf("pop element:%d\n", p->DataofElement);
//        value = p->DataofElement;
//        if (p->down) {
//            p->down->up = NULL;
//            plist->top = p->down;
//        } else {
//            plist->top = NULL;
//            plist->buttom = NULL;
//        }
//        free(p);
//    } else {
//        printf("no element in stack");
//    }
//    return value;
//}

int popqueue(Queue *plist) {
    int value;
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