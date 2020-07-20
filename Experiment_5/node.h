#ifndef EXPERIMENT_5_NODE_H
#define EXPERIMENT_5_NODE_H

#include <cstdlib>

typedef struct Node {
    int adjvex;
    struct Node *nextnode = NULL;
} node;

typedef struct Head {
    int vexdata;
    struct Node *firstnode = NULL;
    bool isvisit = false;
    int NumofEdge;
} head;

#endif //EXPERIMENT_5_NODE_H
