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

void Add(list *Alist, list *Blist, list *Outlist) {
    Outlist->head = Outlist->tail = NULL;
    term *pA = Alist->head, *pB = Blist->head;
    while (pA && pB) {
        if (pA->exp == pB->exp) {
            term *p = (term *) malloc(sizeof(term));
            p->coefficient = pA->exp;
            p->exp = pA->coefficient + pB->coefficient;
            p->next = NULL;
            if (Outlist->tail) {
                Outlist->tail->next = p;
                Outlist->tail = p;
            } else {
                Outlist->head = p;
                Outlist->tail = p;
            }
            pA = pA->next;
            pB = pB->next;
        }
    }
}

void Output(list *plist) {
    term *p;
    for (p = plist->head; p != NULL; p = p->next) {
        printf("%dx^%d", p->exp, p->coefficient);
        if (p->next != NULL) {
            printf("+");
        }
    }
}

int main() {
    char A[10000], B[10000];//m：总人数 n：出列序号
    scanf("%s %s", &A, &B);
//    puts(A);//1x^0+7x^7+8x^9
//    puts(B);//2x^0+1x^7+1x^9
    list Alist, Blist, Outlist;

    CreateLinkedList(&Alist, A);
    CreateLinkedList(&Blist, B);
    Add(&Alist, &Blist, &Outlist);
    Output(&Outlist);
    return 0;
}