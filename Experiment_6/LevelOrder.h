#ifndef EXPERIMENT_6_LEVELORDER_H
#define EXPERIMENT_6_LEVELORDER_H

#endif //EXPERIMENT_6_LEVELORDER_H

#include "queue.h"

void LevelOrder(BinaryTree &T) {
    Queue storage_node;

    BinaryTree Search_Pointer = T;//搜索指针
    push(&storage_node, Search_Pointer);
    while (!isEmpty(storage_node)) {
        Search_Pointer = pop(&storage_node);
        Visit(Search_Pointer);
        if (Search_Pointer->lchild != NULL)
            push(&storage_node, Search_Pointer->lchild);
        if (Search_Pointer->rchild != NULL)
            push(&storage_node, Search_Pointer->rchild);
    }
}