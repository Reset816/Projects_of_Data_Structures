#include <stdio.h>
#include <stdlib.h>

void arry(int m, int n) {
    int a[1000];
    int i;
    for (i = 0; i < m; i++)
        a[i] = 1;
    int out[1000];
    int total = 0;
    i = 0;
    int tmp = 0;
    while (total < m) {
        if (i == m) {
            i = 0;
        }
        if (a[i] == 1) {
            tmp++;
            if (tmp == n) {
                a[i] = 0;
                out[total] = i + 1;
                total++;
                tmp = 0;
            }
        }
        i++;
    }
    for (i = 0; i < m; i++)
        printf("%d", out[i]);
}

typedef struct person {
    int num;
    struct person *next;
} LinkList;

void del(LinkList *p) {
    LinkList *tmp = p;
    if (p->next != p) {
        p->next = p->next->next;
    } else {
        free(p);
        p = NULL;
        return;
    }
    free(tmp->next);
}

void creat(int m, int n) {
    int out[1000];
    int i;
    LinkList *head, *node, *end;//定义头节点，普通节点，尾部节点；
    head = (LinkList *) malloc(sizeof(LinkList));//分配地址
    end = head;         //若是空链表则头尾节点一样
    head->num = 0;
    for (int i = 1; i < m; i++) {
        node = (LinkList *) malloc(sizeof(LinkList));
        node->num = i;
        end->next = node;
        end = node;
    }
    end->next = head;//创建环

    LinkList *p = head;
    int tmp = 0;
    int count = 0;
    while (1) {
        tmp++;
        if (tmp == n - 1) {
            out[count] = (p->next)->num + 1;
            count++;
            del(p);//删除p的下一个结点
            if (p == NULL) {
                for (i = 0; i < m; i++)
                    printf("%d", out[i]);
                return;
            }
            tmp = 0;
        }
        p = p->next;
    }
}

int main() {
    int m, n;//m：总人数 n：出列序号

    scanf("%d %d", &m, &n);

    //arry(m,n);
    creat(m, n);
    return 0;
}