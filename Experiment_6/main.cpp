#include <iostream>
#include <queue>
#include <stack>
#include <memory.h>
#include "node.h"

using namespace std;

void init(int m, head row[]) {
    int weight, start, end;
    for (int i = 1; i <= m; i++) {
        cin >> weight >> start >> end;
        node *P;
        P = (node *) malloc(sizeof(node));
        P->adjvex = end;
        P->weight = weight;
        P->id_of_edge = i;
        P->nextnode = NULL;
        P->nextnode = row[start].firstnode;
        row[start].firstnode = P;
        row[start].outdegree++;
        row[end].indegree++;
    }
}

stack<int> TOPOLOGICAL_SORTING_RESULT;

void get_ve(int n, head row[], int ve[]) {
    queue<int> S;
    for (int i = 1; i <= n; i++) {
        if (row[i].indegree == 0) {
            S.push(i);//零入度顶点为起点
            ve[i] = 0;
            break;
        }
    }

    int now;
    while (!S.empty()) {
        now = S.front();
        S.pop();
        TOPOLOGICAL_SORTING_RESULT.push(now);
        node *P = row[now].firstnode;
        while (P) {
            row[P->adjvex].indegree--;
            if (row[P->adjvex].indegree == 0) {
                S.push(P->adjvex);
                ve[P->adjvex] = max(ve[now] + P->weight, ve[P->adjvex]);
            }
            P = P->nextnode;
        }
    }
//    //test ve
//    for (int i = 1; i <= n; i++) {
//        cout << i << " " << ve[i] << endl;
//    }
}

void get_vl_and_e_and_l(int n, head *row, int *ve, int *vl, int *e, int *l) {
    int now;
    vl[TOPOLOGICAL_SORTING_RESULT.top()] = ve[TOPOLOGICAL_SORTING_RESULT.top()];
    while (!TOPOLOGICAL_SORTING_RESULT.empty()) {
        now = TOPOLOGICAL_SORTING_RESULT.top();
        TOPOLOGICAL_SORTING_RESULT.pop();
        node *P = row[now].firstnode;

        while (P) {
            //vl[now] = min(vl[P->adjvex] - P->weight, vl[now]);
            vl[now] = vl[P->adjvex] - P->weight;
            e[P->id_of_edge] = ve[now];//get e
            l[P->id_of_edge] = vl[P->adjvex] - P->weight;//get l
            P = P->nextnode;
        }
    }
    //test vl
//    for (int i = 1; i <= n; i++) {
//        cout << i << " " << vl[i] << endl;
//    }


}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    head row[n + 1];
    init(m, row);
    int ve[n + 1], vl[n + 1], e[m + 1], l[m + 1];
    memset(ve, 0, sizeof(ve));
    //memset(vl, INT_MAX, sizeof(vl)); 不能这样
    memset(vl, 0x3f, sizeof(vl));

    get_ve(n, row, ve);
    cout << endl;
    get_vl_and_e_and_l(n, row, ve, vl, e, l);
    //test e
//    for (int i = 1; i <= m; i++) {
//        cout << i << " " << e[i] << endl;
//    }
    //test l
//    for (int i = 1; i <= m; i++) {
//        cout << i << " " << l[i] << endl;
//    }

    return 0;
}

/*
9 11
6 1 2
4 1 3
5 1 4
1 2 5
1 3 5
2 4 6
9 5 7
7 5 8
4 6 8
2 7 9
4 8 9
*/