#ifndef BINARY_SEARCH_TREE
#define BINARY_SEARCH_TREE
#include "../Common/Node.h"

struct BinarySearchTree
{
    /*Fields*/
    struct Node *head;

    // -1 if first is greater
    // 1 if the second one is greater
    int (*compare)(void *data_one, void *data_two);
    void *(*search)(struct BinarySearchTree *binary_search_tree, void *data);
    void (*insert)(struct BinarySearchTree *binary_search_tree, void *data, int size);
};

struct BinarySearchTree binary_search_tree_constructor(int (*compare)(void *data_one, void *data_two));
struct BinarySearchTree binary_search_tree_destructor(struct BinarySearchTree *BinarySearchTree);
#endif