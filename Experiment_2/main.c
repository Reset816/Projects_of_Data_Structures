#include <stdio.h>
#include <stdbool.h>
#include <malloc.h>
#include <string.h>

typedef struct Node {
    int coefficient;//系数
    int exp;
    struct Node *next;
} term;

typedef struct _list {
    term *head;
    term *tail;
} list;

void CreateLinkedList(list *plist, char arry[10000]) {

    plist->head = plist->tail = NULL;
    char coefficient, exp;
    for (int i = 0; arry[i] != '\0'; i = i + 5) {//移到下一项

        coefficient = arry[i] - '0';
        exp = arry[i + 3] - '0';
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
}

void AddtoOutlist(int coefficient, int exp, list *plist) {
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

void Add(list *Alist, list *Blist, list *Outlist) {
    Outlist->head = Outlist->tail = NULL;
    term *pA = Alist->head, *pB = Blist->head;
    bool isAleft = 1;
    bool isBleft = 1;
    while (isAleft || isBleft) {
        if (pA->exp == pB->exp) {
            AddtoOutlist(pA->coefficient + pB->coefficient, pA->exp, Outlist);

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
        if ((pA->exp < pB->exp) || !isBleft) {
            AddtoOutlist(pA->coefficient, pA->exp, Outlist);
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
        if ((pA->exp > pB->exp) || !isAleft) {
            AddtoOutlist(pB->coefficient, pB->exp, Outlist);
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
    char A[10000], B[10000];//m：总人数 n：出列序号
    scanf("%s %s", &A, &B);
//    puts(A);//1x^0+2x^4+7x^7+8x^9
//    puts(B);//2x^0+1x^7+1x^9
//    1x^0+2x^4+7x^7+8x^9 2x^0+1x^7+1x^9
//    1x^0+7x^7+8x^9 2x^0+1x^7+1x^9
//    1x^0+2x^4+7x^7+8x^9 2x^0+2x^5+1x^7+1x^9
//    1x^0+2x^4+7x^7+8x^9 0x^0
    list Alist, Blist, Outlist;

    CreateLinkedList(&Alist, A);
    CreateLinkedList(&Blist, B);
    Add(&Alist, &Blist, &Outlist);
    Output(&Outlist);
    return 0;
}