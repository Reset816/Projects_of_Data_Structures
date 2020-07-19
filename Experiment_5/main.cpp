#include <iostream>
#include "node.h"
#include "queue.h"

using namespace std;

void init(int n, head row[]) {
    for (int i = 1; i <= n; i++) {
        int NumofEdge;
        cin >> row[i].vexdata;
        scanf(",%d", &NumofEdge);
        for (int j = 1; j <= NumofEdge; j++) {
            node *P;
            P = (node *) malloc(sizeof(node));
            P->nextnode = row[i].firstnode;
            row[i].firstnode = P;

            scanf(",%d", &P->adjvex);
        }
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
    int n, m;
    scanf("%d,%d", &n, &m);
    head row[n + 1];
    init(n, row);

    //DFS(1, row);

    Queue storage;
    push(&storage, 1);
    BFS(storage, row);
    return 0;
}
