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
    char tmpforSign = 0;
    int count = 1;
    while (1) {
        //8x^9+7x^7+1x^0 count=1是系数，count=4是指数
        if (tmp != ' ' && tmp != '\n') {
            tmpforSign = tmp;//需要多一个变量来存数字前一个（即正负号）
            tmp = getchar();
            if (count == 1)
                if (tmpforSign == '-')
                    coefficient = (tmp - '0') * (-1);
                else
                    coefficient = (tmp - '0') * 1;
            if (count == 4) {
                count = 0;
                exp = tmp - '0';
                tmp = getchar();//读取后面的符号已便于下一项
                AddTerm(coefficient, exp, plist);
            }
            count++;

        } else {
            return;
        }
    }
}

void Add(list *Alist, list *Blist, list *Outlist) {
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

void Output(list *plist) {
    term *p;
    for (p = plist->head; p != NULL; p = p->next) {
        printf("%dx^%d", p->coefficient, p->exp);
        if (p->next != NULL) {
            printf("+");
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
    list Alist, Blist, Outlist;

    CreateLinkedList(&Alist);
    CreateLinkedList(&Blist);
    Add(&Alist, &Blist, &Outlist);
    Output(&Outlist);
    return 0;
}