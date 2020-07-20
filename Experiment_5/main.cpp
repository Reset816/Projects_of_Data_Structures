#include <iostream>
#include "node.h"
#include "queue.h"

using namespace std;

void init(int n, head row[]) {
    for (int i = 1; i <= n; i++) {
        cin >> row[i].vexdata;
        scanf(",%d", &row[i].NumofEdge);
        for (int j = 1; j <= row[i].NumofEdge; j++) {
            node *P;
            P = (node *) malloc(sizeof(node));
            P->nextnode = row[i].firstnode;
            row[i].firstnode = P;

            scanf(",%d", &P->adjvex);
        }
    }
}

void ResetVisit(int n, head row[]) {
    for (int i = 1; i <= n; i++) {
        row[i].isvisit = false;
    }
}

void visit(int NodetoVisit, head row[]) {
    printf("%d ", NodetoVisit);
    row[NodetoVisit].isvisit = true;
}

void DFS(int StartSearch, head row[]) {
    if (!row[StartSearch].isvisit) {
        visit(StartSearch, row);
        node *P = row[StartSearch].firstnode;
        while (P) {
            DFS(P->adjvex, row);
            P = P->nextnode;
        }
    }
}

void BFS(Queue &storage, head row[]) {
    if (!isEmpty(storage)) {
        int nodetoVisit = popqueue(&storage);
        visit(nodetoVisit, row);
        node *P = row[nodetoVisit].firstnode;
        while (P) {
            if (!row[P->adjvex].isvisit) {
                push(&storage, P->adjvex);
                row[P->adjvex].isvisit = true;
            }

            P = P->nextnode;
        }
        BFS(storage, row);
    }
}

int main() {
    //example
/*
5,14
1,3,2,5,4
2,3,1,5,3
3,2,2,4
4,3,1,5,3
5,3,4,1,2
*/
    //expected output
/*
DFS:
1 4 3 2 5
BFS:
1 4 5 2 3
 */

    int n, m;
    scanf("%d,%d", &n, &m);
    head row[n + 1];
    init(n, row);

    printf("DFS:\n");
    DFS(1, row);

    ResetVisit(n, row);

    Queue storage;
    push(&storage, 1);
    printf("\nBFS:\n");
    BFS(storage, row);
    return 0;
}
