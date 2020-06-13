#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>

typedef struct lineStack {
    char data;
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

char pop(Stack *plist) {
    char value;
    if (plist->top) {
        lineStack *p = plist->top;
        //printf("pop element:%d\n", p->data);
        value = p->data;
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

bool isEmpty(Stack *plist) {
    if (plist->top == NULL) {
        return true;
    } else {
        return false;
    }
}

void convert(Stack *plist, Stack *post) {
    char tmp;
    while (1) {
        tmp = getchar();
        if (tmp != '\n') {
            if (isInOP(tmp)) {//如果读入的是运算符
                //弹出所有优先级大于或等于该运算符的栈顶元素，然后将该运算符入栈，遇到左括号时不能再弹出
                while (plist->top != '(' && plist->top != NULL) {
                    if (ComparePriority(plist->top->data, tmp) == '>' ||
                        ComparePriority(plist->top->data, tmp) == '=') {
                        push(post, plist->top->data);
                        pop(plist);
                    } else {
                        break;
                    }
                }
                push(plist, tmp);
            } else if (tmp == '(') {//如果读入的是左括号
                push(plist, tmp);
            } else if (tmp == ')') {//如果读入的是右括号
                //执行出栈操作，并将出栈的元素输出，直到弹出栈的是左括号。左括号也要出栈但不输出；
                while (1) {
                    tmp = pop(plist);
                    if (tmp == '(') {
                        break;
                    }
                    push(post, tmp);
                }
            } else {//如果读入的是数字
                push(post, tmp);
            }
        } else {
            break;
        }
    }
    while (plist->top != NULL) {
        push(post, pop(plist));
    }
}


char Operate(char theta, char a, char b) {
    int x = a - '0';
    int y = b - '0';
    if (theta == '+') {
        return (x + y) + '0';
    } else if (theta == '-') {
        return (x - y) + '0';
    } else if (theta == '*') {
        return (x * y) + '0';
    } else if (theta == '/') {
        return (x / y) + '0';
    }
}

void compute(Stack *post, Stack *result) {
    char tmp;
    char a, b;
    while (!isEmpty(post)) {
        tmp = pop(post);
        if (isInOP(tmp)) {
            a = pop(result);
            b = pop(result);
            push(result, Operate(tmp, a, b));
        } else {
            push(result, tmp);
        }
    }
    printf("%d", result->top - '0');
}

void scan(Stack *pOPTR, Stack *pOPND) {
    char tmp, theta, a, b;
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
                        theta = pop(pOPTR);
                        a = pop(pOPND);
                        b = pop(pOPND);
                        push(pOPND, Operate(theta, a, b));
                        break;
                }

            } else {//如果读入的不是运算符
                push(pOPND, tmp);
            }

        } else {
            return;
        }
    }
}

int main() {
    //printf("Type in the Arithmetic Expression\nFor Example:\n1+3*4-6/2\n");
    Stack OPTR, OPTD, tmp, post, result;
    OPTR.top = NULL;
    OPTD.top = NULL;
    tmp.top = NULL;
    post.top = NULL;
    result.top = NULL;
    //scan(&OPTR, &OPTD);
    //convert(&OPTR, &post);
    push(&tmp, '6');
    push(&tmp, '5');
    push(&tmp, '2');
    push(&tmp, '3');
    push(&tmp, '+');
    push(&tmp, '8');
    push(&tmp, '*');
    push(&tmp, '+');
    push(&tmp, '3');
    push(&tmp, '+');
    push(&tmp, '*');
    while (!isEmpty(&tmp)) {
        push(&post, pop(&tmp));
    }
    compute(&post, &result);
    return 0;
}
