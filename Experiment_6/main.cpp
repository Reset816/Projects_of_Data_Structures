#include <cstdio>
#include <malloc.h>
#include "stack.h"

using namespace std;
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

int main() {
    //样例
    //输入：ABE##F##CG### 结果：
    //输入：(3*(5-2)+7)^2 结果：256
    //
    printf("Type in the BinaryTree\nFor Example:\nABE##F##CG###\n");
    BinaryTree test;
    CreateBinaryTree(test);

    printf("Recursive\n");
    printf("PreOrder:\n");
    Recursive_PreOrder(test);
    printf("\nInOrder:\n");
    Recursive_InOrder(test);
    printf("\nPostOrder:\n");
    Recursive_PostOrder(test);

    return 0;
}