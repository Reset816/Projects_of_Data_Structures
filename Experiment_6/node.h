#ifndef EXPERIMENT_5_NODE_H
#define EXPERIMENT_5_NODE_H

#include <cstdlib>

typedef struct Node {
    int adjvex;
    int weight;
    int id_of_edge;
    struct Node *nextnode = NULL;
} node;

typedef struct Head {
    //int vexdata;
    struct Node *firstnode = NULL;
    int indegree = 0;
    int outdegree = 0;
    //bool isvisit = false;
    //int NumofEdge;
} head;

#endif //EXPERIMENT_5_NODE_H
