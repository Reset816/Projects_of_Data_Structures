#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>
#include <math.h>

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

int pop(Stack *plist) {
    int value;
    if (plist->top) {
        element *p = plist->top;
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

bool isEmpty(Stack *plist) {
    if (plist->top == NULL) {
        return true;
    } else {
        return false;
    }
}

bool isInOP(char tmp) {
    if (tmp == '+' || tmp == '-' || tmp == '*' || tmp == '/' || tmp == '^') {
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
    } else if (b == '^') {
        if (a == ')') {
            return '>';
        } else {
            return '<';
        }
    }
}

void convert(Stack *plist, Stack *post) {
    char tmp;
    while (1) {
        tmp = getchar();
        if (tmp != '\n') {
            if (isInOP(tmp)) {//如果读入的是运算符
                //弹出所有优先级大于或等于该运算符的栈顶元素，然后将该运算符入栈，遇到左括号时不能再弹出
                while (!isEmpty(plist) && plist->top->data != '(') {
                    if (ComparePriority(plist->top->data, tmp) == '>' ||
                        ComparePriority(plist->top->data, tmp) == '=') {
                        push(post, plist->top->data);
                        post->top->isOP = true;
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
                    post->top->isOP = true;
                }
            } else {//如果读入的是数字
                push(post, tmp - '0');
                post->top->isOP = false;
            }
        } else {
            break;
        }
    }
    while (plist->top != NULL) {
        push(post, pop(plist));
        post->top->isOP = true;
    }
}

int Operate(char theta, int a, int b) {
    if (theta == '+') {
        return a + b;
    } else if (theta == '-') {
        return a - b;
    } else if (theta == '*') {
        return a * b;
    } else if (theta == '/') {
        return a / b;
    } else if (theta == '^') {
        return pow(a, b);
    }
}

void compute(Stack *post, Stack *result) {
    int tmp;
    int a, b;
    bool isOP;
    while (!isEmpty(post)) {
        isOP = post->top->isOP;
        tmp = pop(post);
        //printf("%d", isOP);
        if (isOP) {
            a = pop(result);
            b = pop(result);
            push(result, Operate(tmp, b, a));
        } else {
            push(result, tmp);
        }
    }
    printf("%d", result->top->data);
}

void scan(Stack *pOPTR, Stack *pOPND) {
    char tmp, theta, a, b;
    while (1) {
        tmp = getchar();
        if (tmp != '\n') {
            if (isInOP(tmp)) {//如果读入的是运算符
                while (!isEmpty(pOPTR) && pOPTR->top->data != '(') {
                    if (ComparePriority(tmp, pOPTR->top->data) == '>') {
                        break;
                    } else {
                        theta = pop(pOPTR);
                        a = pop(pOPND);
                        b = pop(pOPND);
                        push(pOPND, Operate(theta, b, a));
                    }
                }
                push(pOPTR, tmp);
            } else if (tmp == '(') {//如果读入的是左括号
                push(pOPTR, tmp);
            } else if (tmp == ')') {//如果读入的是右括号
                //执行出栈操作，并将出栈的元素输出，直到弹出栈的是左括号。左括号也要出栈但不输出；
                while (1) {
                    theta = pop(pOPTR);
                    if (theta == '(') {
                        break;
                    }
                    a = pop(pOPND);
                    b = pop(pOPND);
                    push(pOPND, Operate(theta, b, a));
                }
            } else {//如果读入的是数字
                push(pOPND, tmp - '0');
            }
        } else {
            break;
        }
    }
    while (!isEmpty(pOPTR)) {
        tmp = pop(pOPTR);
        //printf("%d", isOP);

        a = pop(pOPND);
        b = pop(pOPND);
        push(pOPND, Operate(tmp, b, a));
    }
    printf("%d", pOPND->top->data);
}

int main() {
    //样例
    //输入：3*(5-2)+7 结果：16
    //输入：(3*(5-2)+7)^2 结果：256

    printf("Type in the Arithmetic Expression\nFor Example:\n3*(5-2)+7\n");
    Stack OPTR, OPTD, tmp, post, result;
    OPTR.top = NULL;
    OPTD.top = NULL;
    tmp.top = NULL;
    post.top = NULL;
    result.top = NULL;

    //method 1 start
    convert(&OPTR, &tmp);
    while (!isEmpty(&tmp)) {
        bool tmpOP = tmp.top->isOP;
        push(&post, pop(&tmp));
        post.top->isOP = tmpOP;
    }
    compute(&post, &result);
    //method 1 end

    //method 2 start
//    scan(&OPTR, &OPTD);
    //method 2 end
    return 0;
}
