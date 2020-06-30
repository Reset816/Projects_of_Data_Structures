#include <cstdio>
#include "recursive.h"
#include "non_recursive.h"
#include "LevelOrder.h"

void RecursiveMethod(BinaryTree T) {
    printf("recursive\n");

    printf("PreOrder:\n");
    Recursive_PreOrder(T);

    printf("\nInOrder:\n");
    Recursive_InOrder(T);

    printf("\nPostOrder:\n");
    Recursive_PostOrder(T);
}

void NonRecursiveMethod(BinaryTree T) {
    printf("non-recursive\n");

    printf("PreOrder:\n");
    non_Recursive_PreOrder(T);

    printf("\nInOrder:\n");
    non_Recursive_InOrder(T);

    printf("\nPostOrder:\n");
    non_Recursive_PostOrder(T);
}

void LevelOrderMethod(BinaryTree test) {
    printf("LevelOrder:\n");
    LevelOrder(test);
}

int main() {
    //样例
    //输入：ABE##F##CG### 结果：

    printf("Type in the BinaryTree\nFor Example:\nABE##F##CG###\n");
    BinaryTree T;
    CreateBinaryTree(T);

    RecursiveMethod(T);
    printf("\n\n");
    NonRecursiveMethod(T);
    printf("\n\n");
    LevelOrderMethod(T);
    return 0;
}