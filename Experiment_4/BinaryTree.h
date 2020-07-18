#ifndef EXPERIMENT_6_BINARYTREE_H
#define EXPERIMENT_6_BINARYTREE_H

typedef struct Node {
    char data;
    struct Node *lchild;
    struct Node *rchild;
    bool tag = false;
} BinaryNode, *BinaryTree;

void CreateBinaryTree(BinaryTree &T);

void Visit(BinaryNode *T);

#endif //EXPERIMENT_6_BINARYTREE_H
