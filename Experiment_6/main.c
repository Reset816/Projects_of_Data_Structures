#include <stdio.h>
#include <malloc.h>

typedef struct Node {
    char data;
    struct Node *lchild;
    struct Node *rchild;
} BinaryNode;


void CreateBinaryTree(BinaryNode *T) {
    char tmp;
    scanf("%c",&tmp);
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

void PreOrder(BinaryNode *T) {
    if (T != NULL) {
        Visit(T);
        PreOrder(T->lchild);
        PreOrder(T->rchild);
    }
}

int main() {
    BinaryNode *test;
    CreateBinaryTree(&test);
    PreOrder(&test);
    return 0;
}
