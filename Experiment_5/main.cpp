#include <iostream>
#include "node.h"

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

int main() {
    int n, m;
    scanf("%d,%d", &n, &m);
    head row[n + 1];
    init(n, row);
//    printf("%32133123");
//    printf("%32133123");
//    printf("%32133123");

    DFS(1, row);
    return 0;
}
