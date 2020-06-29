#ifndef EXPERIMENT_6_NON_RECURSIVE_H
#define EXPERIMENT_6_NON_RECURSIVE_H

#endif //EXPERIMENT_6_NON_RECURSIVE_H

#include "stack.h"

void non_Recursive_InOrder(BinaryTree &T) {
    Stack storage_node;

    BinaryTree Search_Pointer = T;//搜索指针
    do {
        while (Search_Pointer != NULL) {//遍历左子树 不把#入栈
            push(&storage_node, Search_Pointer);
            Search_Pointer = Search_Pointer->lchild;
        }
        if (!isEmpty(storage_node)) {
            //此时Search_Pointer指向NULL
            Search_Pointer = storage_node.top->DataofElement;
            //此时Search_Pointer指向最底层左结点
            pop(&storage_node);//退栈
            Visit(Search_Pointer);//访问根
            Search_Pointer = Search_Pointer->rchild;
        }
    } while (!isEmpty(storage_node) || Search_Pointer != NULL);
}

void non_Recursive_PreOrder(BinaryTree &T) {
    Stack storage_node;

    BinaryTree Search_Pointer = T;
    do {//把访问的结点压栈，然后访问他的左节点。取出栈顶，访问它的右节点
        while (Search_Pointer != NULL) {//不把#入栈
            push(&storage_node, Search_Pointer);
            Visit(Search_Pointer);
            Search_Pointer = Search_Pointer->lchild;
        }
        if (!isEmpty(storage_node)) {
            //此时Search_Pointer指向NULL
            Search_Pointer = storage_node.top->DataofElement;
            //此时Search_Pointer指向最底层左结点
            pop(&storage_node);
            Search_Pointer = Search_Pointer->rchild;
        }
    } while (!isEmpty(storage_node) || Search_Pointer != NULL);
}

void non_Recursive_PostOrder(BinaryTree &T) {
    Stack storage_node;

    BinaryTree Search_Pointer = T;//搜索指针
    do {
        while (Search_Pointer != NULL) {//遍历左子树 不把#入栈
            push(&storage_node, Search_Pointer);
            Search_Pointer = Search_Pointer->lchild;
        }
        if (!isEmpty(storage_node)) {
            //此时Search_Pointer指向NULL
            Search_Pointer = storage_node.top->DataofElement;
            //此时Search_Pointer指向最底层左结点
            pop(&storage_node);//退栈
            if (!Search_Pointer->tag) {
                Search_Pointer->tag = true;
                push(&storage_node, Search_Pointer);
                Search_Pointer = Search_Pointer->rchild;
            } else {
                Visit(Search_Pointer);
                Search_Pointer = NULL;
            }
        }
    } while (!isEmpty(storage_node) || Search_Pointer != NULL);
}