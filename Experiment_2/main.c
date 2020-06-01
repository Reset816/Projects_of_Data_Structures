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
    int i;
    i = 0;

    plist->head = plist->tail = NULL;
    char coefficient, exp;
    while (1) {
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

        if (arry[i + 4] == '\0') {//如果下一位不是字符串最后一项
            //printf("%d", i);
            break;
        }
        i = i + 5;//移到下一项
    }
    scanf("%s", &i);
};

int main() {
    char A[10000], B[10000];//m：总人数 n：出列序号
    scanf("%s %s", &A, &B);
//    puts(A);//1x^0+7x^7+8x^9
//    puts(B);
    list Alist, Blist;

    CreateLinkedList(&Alist, A);

    return 0;
}