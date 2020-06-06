#include <stdio.h>
#include <stdbool.h>
#include <malloc.h>
#include <string.h>

typedef struct Node {
    int coefficient;//系数
    int exp;//指数
    struct Node *next;
} term;

typedef struct _list {
    term *head;
    term *tail;
} list;

void AddTerm(int coefficient, int exp, list *plist) {
    term *p = (term *) malloc(sizeof(term));
    p->coefficient = coefficient;
    p->exp = exp;
    p->next = NULL;
    if (plist->tail) {
        plist->tail->next = p;
        plist->tail = p;
    } else {
        plist->head = p;
        plist->tail = p;
    }
}

void CreateLinkedList(list *plist) {
    plist->head = plist->tail = NULL;
    int coefficient, exp;
    char tmp = 0;
    char tmpforSign = 0;//需要多一个变量来存数字前一个（即正负号）
    int count = 1;

    while (1) {
        //8x^9+7x^7+1x^0 count=1是系数，count=4是指数,count=6是系数，count=9是指数
        if (tmp != ' ' && tmp != '\n') {
            tmpforSign = tmp;//需要多一个变量来存数字前一个（即正负号）
            tmp = getchar();
            //特殊情况，如果第一个字符为负号
            if (count == 1 && tmp == '-')
                continue;
            //特殊情况，如果第一个字符为负号
            if (count % 5 == 1)
                if (tmpforSign == '-')
                    coefficient = (tmp - '0') * (-1);
                else
                    coefficient = (tmp - '0') * 1;
            if (count % 5 == 4) {
                exp = tmp - '0';
                AddTerm(coefficient, exp, plist);
            }
            count++;

        } else {
            return;
        }
    }
}

void Addition(list *Alist, list *Blist, list *Outlist) {//多项式加法 A+B
    Outlist->head = Outlist->tail = NULL;
    term *pA = Alist->head, *pB = Blist->head;
    bool isAleft = 1;
    bool isBleft = 1;
    while (isAleft || isBleft) {
        if ((pA->exp < pB->exp) || !isAleft) {//!isAleft即A空了，就输出B
            //if (pA->exp < pB->exp) {
            AddTerm(pB->coefficient, pB->exp, Outlist);
            if (pB->next != NULL) {
                pB = pB->next;
                free(Blist->head);
                Blist->head = pB;
            } else {
                isBleft = 0;
                free(Blist->head);
            }
            continue;
        }
        if ((pA->exp > pB->exp) || !isBleft) {//!isBleft即B空了，就输出A
            //if (pA->exp > pB->exp) {
            AddTerm(pA->coefficient, pA->exp, Outlist);
            if (pA->next != NULL) {
                pA = pA->next;
                free(Alist->head);
                Alist->head = pA;
            } else {
                isAleft = 0;
                free(Alist->head);
            }
            continue;
        }
        if (pA->exp == pB->exp) {
            AddTerm(pA->coefficient + pB->coefficient, pA->exp, Outlist);

            if (pA->next != NULL) {
                pA = pA->next;
                free(Alist->head);
                Alist->head = pA;
            } else {
                isAleft = 0;
                free(Alist->head);
            }

            if (pB->next != NULL) {
                pB = pB->next;
                free(Blist->head);
                Blist->head = pB;
            } else {
                isBleft = 0;
                free(Blist->head);
            }
            continue;
        }
    }
}

void Subtraction(list *Alist, list *Blist, list *Outlist) {//多项式减法 A-B
    Outlist->head = Outlist->tail = NULL;
    term *pA = Alist->head, *pB = Blist->head;
    bool isAleft = 1;
    bool isBleft = 1;
    while (isAleft || isBleft) {
        if ((pA->exp < pB->exp) || !isAleft) {//!isAleft即A空了，就输出B
            //if (pA->exp < pB->exp) {
            AddTerm(pB->coefficient * -1, pB->exp, Outlist);
            if (pB->next != NULL) {
                pB = pB->next;
                free(Blist->head);
                Blist->head = pB;
            } else {
                isBleft = 0;
                free(Blist->head);
            }
            continue;
        }
        if ((pA->exp > pB->exp) || !isBleft) {//!isBleft即B空了，就输出A
            //if (pA->exp > pB->exp) {
            AddTerm(pA->coefficient, pA->exp, Outlist);
            if (pA->next != NULL) {
                pA = pA->next;
                free(Alist->head);
                Alist->head = pA;
            } else {
                isAleft = 0;
                free(Alist->head);
            }
            continue;
        }
        if (pA->exp == pB->exp) {
            AddTerm(pA->coefficient - pB->coefficient, pA->exp, Outlist);

            if (pA->next != NULL) {
                pA = pA->next;
                free(Alist->head);
                Alist->head = pA;
            } else {
                isAleft = 0;
                free(Alist->head);
            }

            if (pB->next != NULL) {
                pB = pB->next;
                free(Blist->head);
                Blist->head = pB;
            } else {
                isBleft = 0;
                free(Blist->head);
            }
            continue;
        }
    }
}

void MergeTerm(list *plist) {//合并指数项相同的项
    term *p, *q, *tmp;//tmp是q的前一项，便于删除q
    for (p = plist->head; p != NULL; p = p->next) {
        for (q = p->next, tmp = p; q != NULL; tmp = q, q = q->next) {
            if (p->exp == q->exp) {
                p->coefficient += q->coefficient;
                tmp->next = q->next;
                free(q);
                q = tmp;
            }
        }
    }
}

void Multiplication(list *Alist, list *Blist, list *Outlist) {//多项式乘法 A*B
    Outlist->head = Outlist->tail = NULL;
    term *pA, *pB;
    for (pA = Alist->head; pA != NULL; pA = pA->next) {
        for (pB = Blist->head; pB != NULL; pB = pB->next) {
            AddTerm(pA->coefficient * pB->coefficient, pA->exp + pB->exp, Outlist);
        }
    }
    MergeTerm(Outlist);
}

void Output(list *plist) {
    term *p;
    for (p = plist->head; p != NULL; p = p->next) {
        if (p->coefficient)
            printf("%dx^%d", p->coefficient, p->exp);

        if (p->next != NULL) {
            if (p->next->coefficient > 0)
                printf("+");
//                遇到系数为0的项不输出
//            else if (p->next->coefficient < 0);
//                printf("-");数字自带负号，不需要单独输出负号了
        }
    }
}

int main() {
//    char A[10000], B[10000];
//    scanf("%s %s", &A, &B);
//    puts(A);//1x^0+2x^4+7x^7+8x^9
//    puts(B);//2x^0+1x^7+1x^9
//    1x^0+2x^4+7x^7+8x^9 2x^0+1x^7+1x^9
//    1x^0+7x^7+8x^9 2x^0+1x^7+1x^9
//    1x^0+2x^4+7x^7+8x^9 2x^0+2x^5+1x^7+1x^9
//    2x^4+1x^0 1x^1
//    3x^5+7x^3+1x^0 1x^5+1x^3+2x^0+8x^0
//    8x^9+7x^7+2x^4+1x^0 1x^0
//    8x^9+7x^7+2x^4+1x^0 8x^9+7x^7+2x^4+1x^0

//    3x^5+7x^3+1x^0 1x^5-1x^3+2x^1+8x^0
//    减法样例
//    3x^5+7x^3+1x^0 5x^5+7x^3+2x^0 -2x^5-1x^0
//    3x^5+7x^3+1x^0 2x^0 3x^5+7x^3-1x^0
//    乘法样例
//    1x^1+1x^0 1x^1+1x^0 1x^2+2x^1+1x^0
//    1x^1+1x^0 1x^2+2x^1+1x^0 1x^3+3x^2+3x^1+1x^0
//    3x^5+7x^3+1x^0 2x^0 6x^5+14x^3+2x^0
//    3x^5+7x^3+1x^0 2x^1 6x^6+14x^4+2x^1
    list Alist, Blist, Outlist;

    CreateLinkedList(&Alist);
    CreateLinkedList(&Blist);
    //Subtraction(&Alist, &Blist, &Outlist);
    Multiplication(&Alist, &Blist, &Outlist);
    Output(&Outlist);
    return 0;
}