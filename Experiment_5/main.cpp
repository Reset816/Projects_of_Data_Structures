#include <iostream>

using namespace std;

typedef struct Node {
    int adjvex;
    struct Node *nextarc = NULL;
} node;

typedef struct Head {
    int vexdata;
    struct Node *firstarc = NULL;
} head;



int main() {
    int n, m;
    scanf("%d,%d", &n, &m);
//    printf("%d|||%d",n,m);
//    int a[n];
//    for(int i=0; i<n;i++)
//    printf("%d ",a[i]);
    head row[n];
    for (int i = 0; i < n; i++) {
        int NumofEdge;
        cin >> row[i].vexdata;
        scanf(",%d", &NumofEdge);
        for (int j = 1; j <= NumofEdge; j++) {
            node *P;
            P = (node *) malloc(sizeof(node));
            P->nextarc = row[i].firstarc;
            row[i].firstarc = P;

            scanf(",%d", &P->adjvex);
        }
    }
    printf("%32133123");
    printf("%32133123");
    printf("%32133123");
    return 0;
}
