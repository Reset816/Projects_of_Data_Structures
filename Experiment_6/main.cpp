#include <cstdio>
#include "recursive.h"
#include "non_recursive.h"

using namespace std;

void RecursiveMethod(BinaryTree test) {
    printf("recursive\n");
    printf("PreOrder:\n");
    Recursive_PreOrder(test);
    printf("\nInOrder:\n");
    Recursive_InOrder(test);
    printf("\nPostOrder:\n");
    Recursive_PostOrder(test);
}

void NonRecursiveMethod(BinaryTree test) {
    printf("non-recursive\n");
    printf("PreOrder:\n");
    non_Recursive_PreOrder(test);
    printf("\nInOrder:\n");
    non_Recursive_InOrder(test);
//    printf("\nPostOrder:\n");
//    Recursive_PostOrder(test);
}

int main() {
    //样例
    //输入：ABE##F##CG### 结果：

    printf("Type in the BinaryTree\nFor Example:\nABE##F##CG###\n");
    BinaryTree test;
    CreateBinaryTree(test);

    RecursiveMethod(test);
    printf("\n\n");
    NonRecursiveMethod(test);
    return 0;
}