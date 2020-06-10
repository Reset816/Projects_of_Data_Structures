#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>

typedef struct lineStack {
    int data;
    struct lineStack *up;
    struct lineStack *down;
} lineStack;

typedef struct Stack {
    lineStack *top;
    lineStack *buttom;
} Stack;

void push(Stack *plist, char value) {
    lineStack *p = (lineStack *) malloc(sizeof(lineStack));
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

bool isInOP(char tmp) {
    if (tmp == '+' || tmp == '-' || tmp == '*' || tmp == '/') {
        return true;
    } else {
        return false;
    }

}

char ComparePriority(char a, char b) {
    if (b == '(') {
        return '<';
    } else if (b == ')') {
        if (a == '(') {
            return '=';
        } else {
            return '>';
        }
    } else if (b == '+' || b == '-') {
        if (a == '(') {
            return '<';
        } else {
            return '>';
        }
    } else if (b == '*' || b == '/') {
        if (a == '+' || a == '-' || a == '(') {
            return '<';
        } else {
            return '>';
        }
    }
}

void scan(Stack *pOPTR, Stack *pOPTD) {
    char tmp;
    while (1) {
        //8x^9+7x^7+1x^0 count=1是系数，count=4是指数,count=6是系数，count=9是指数
        tmp = getchar();
        if (tmp != '\n') {
            if (isInOP(tmp)) {//如果读入的是运算符
                switch (ComparePriority(pOPTR->top, tmp)) {
                    case '<' :
                        push(pOPTR, tmp);
                        break;
                    case '=' :
                        break;
                    case '>' :
                        break;
                }

            } else {//如果读入的不是运算符
                push(pOPTD, tmp);
            }

        } else {
            return;
        }
    }
}

int main() {
    printf("Type in the Arithmetic Expression\nFor Example:\n1+3*4-6/2\n");
    Stack OPTR, OPTD;
    OPTR.top = NULL;
    OPTD.top = NULL;
    scan(&OPTR, &OPTD);
    return 0;
}
