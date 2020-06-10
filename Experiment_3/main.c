#include <stdio.h>
#include <malloc.h>

typedef struct lineStack {
    int data;
    struct lineStack *up;
    struct lineStack *down;
} lineStack;

typedef struct Stack {
    lineStack *top;
    lineStack *buttom;
} Stack;

void push(Stack *plist, int a) {
    lineStack *p = (lineStack *) malloc(sizeof(lineStack));
    p->data = a;
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

void pop(Stack *plist) {
    if (plist->top) {
        lineStack *p = plist->top;
        printf("pop element:%d\n", p->data);
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
}

int main() {
    printf("Type in the Arithmetic Expression\nFor Example:\n1+3*4-6/2\n");
    Stack TEST;
    TEST.top = NULL;
    push(&TEST, 1);
    push(&TEST, 2);
    push(&TEST, 3);
    pop(&TEST);
    pop(&TEST);
    pop(&TEST);
    pop(&TEST);
    return 0;
}
