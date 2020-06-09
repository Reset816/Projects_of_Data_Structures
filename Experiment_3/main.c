#include <stdio.h>
#include <malloc.h>

typedef struct lineStack {
    int data;
    struct lineStack *next;
    struct lineStack *previous;
} lineStack;

typedef struct Stack {
    lineStack *top;
    lineStack *buttom;
} Stack;

void push(Stack *plist, int a) {
    lineStack *p = (lineStack *) malloc(sizeof(lineStack));
    p->data = a;
    p->next = NULL;
    if (plist->buttom) {
        plist->buttom->next = p;
        plist->buttom = p;
    } else {
        plist->top = p;
        plist->buttom = p;
    }
}

void pop(Stack *plist) {
    if (plist) {
        lineStack *p = plist->top;
        printf("pop element:%d ", p->data);
        p->previous->next = NULL;
        plist->top = p->previous;
        free(p);
    } else {
        printf("no element in stack");
    }
}

int main() {
    printf("Type in the Arithmetic Expression\nFor Example:\n1+3*4-6/2\n");
    Stack TEST;
    TEST.buttom = NULL;
    push(&TEST, 1);
    push(&TEST, 2);
    push(&TEST, 3);
//    pop(&TEST);
//    pop(&TEST);
//    pop(&TEST);
//    pop(&TEST);
    return 0;
}
