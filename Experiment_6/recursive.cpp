#include <cstdlib>
#include "recursive.h"


void Recursive_PreOrder(BinaryTree &T) {
    if (T != NULL) {
        Visit(T);
        Recursive_PreOrder(T->lchild);
        Recursive_PreOrder(T->rchild);
    }
}

void Recursive_InOrder(BinaryTree &T) {
    if (T != NULL) {
        Recursive_InOrder(T->lchild);
        Visit(T);
        Recursive_InOrder(T->rchild);
    }
}

void Recursive_PostOrder(BinaryTree &T) {
    if (T != NULL) {
        Recursive_PostOrder(T->lchild);
        Recursive_PostOrder(T->rchild);
        Visit(T);
    }
}