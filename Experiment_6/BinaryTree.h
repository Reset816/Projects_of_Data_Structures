#ifndef EXPERIMENT_6_BINARYTREE_H
#define EXPERIMENT_6_BINARYTREE_H

#endif //EXPERIMENT_6_BINARYTREE_H

#include <malloc.h>

typedef struct Node {
    char data;
    struct Node *lchild;
    struct Node *rchild;
} BinaryNode, *BinaryTree;

void CreateBinaryTree(BinaryTree &T) {
    char tmp;
    scanf("%c", &tmp);
    if (tmp == '#') {
        T = NULL;
    } else {
        T = (BinaryNode *) malloc(sizeof(BinaryNode));
        T->data = tmp;
        CreateBinaryTree(T->lchild);
        CreateBinaryTree(T->rchild);
    }
}

void Visit(BinaryNode *T) {
    if (T->data != '#') {
        printf("%c ", T->data);
    }
}