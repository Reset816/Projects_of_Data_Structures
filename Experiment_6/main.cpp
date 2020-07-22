#include <iostream>
#include <queue>
#include <stack>
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
        P->nextnode = NULL;
        P->nextnode = row[start].firstnode;
        row[start].firstnode = P;
        row[start].outdegree++;
        row[end].indegree++;
    }
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

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    head row[n + 1];
    init(m, row);
    int ve[n + 1], vl[n + 1], e[m + 1], l[m + 1];

    queue<int> S;
    for (int i = 1; i <= n; i++) {
        if (row[i].indegree == 0) {
            S.push(i);//零入度顶点为起点
            ve[i] = 0;
            break;
        }
    }

    stack<int> TOPOLOGICAL_SORTING_RESULT;
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
                ve[P->adjvex] = ve[now] + P->weight;
            }
            P = P->nextnode;
        }
    }
    //test
//    while (!TOPOLOGICAL_SORTING_RESULT.empty()) {
//        cout << TOPOLOGICAL_SORTING_RESULT.front();
//        TOPOLOGICAL_SORTING_RESULT.pop();
//    }
    //test
    for (int i = 1; i <= n; i++) {
        cout << i << " " << ve[i] << endl;
    }

    cout << endl;
    //get vl

    vl[TOPOLOGICAL_SORTING_RESULT.top()] = ve[TOPOLOGICAL_SORTING_RESULT.top()];
    while (!TOPOLOGICAL_SORTING_RESULT.empty()) {
        now = TOPOLOGICAL_SORTING_RESULT.top();
        TOPOLOGICAL_SORTING_RESULT.pop();
        node *P = row[now].firstnode;
        while (P) {
            vl[now] = vl[P->adjvex] - P->weight;
            P = P->nextnode;
        }
    }
    //test
    for (int i = 1; i <= n; i++) {
        cout << i << " " << vl[i] << endl;
    }

    return 0;
}
