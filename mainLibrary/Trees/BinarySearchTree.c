#include "./BinarySearchTree.h"
/*private*/
struct Node *create_node(void *data, int size);
void destroy_node(struct Node *node);
void *search(struct BinarySearchTree *binary_search_tree, void *data);
void insert(struct BinarySearchTree *binary_search_tree, void *data, int size);

struct BinarySearchTree binary_search_tree_constructor(int (*compare)(void *data_one, void *data_two))
{
    struct BinarySearchTree new_binary_searchTree;
    new_binary_searchTree.compare = compare;
    new_binary_searchTree.insert = insert;
    new_binary_searchTree.search = search;
    return new_binary_searchTree;
}

struct Node *create_node(void *data, int size)
{
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    *new_node = node_constructor(data, size);
    return new_node;
}

void destroy_node(struct Node *node)
{
    node_destructor(node);
}

// perigoso pra caraio isso aqui eim
struct Node *iterate(struct BinarySearchTree *tree, struct Node *cursor, void *data, int *direction)
{
    if (tree->compare(cursor->data, data) == 1)
    {
        // next
        if (cursor->next)
        {
            return iterate(tree, cursor->next, data, direction);
        }
        else
        {
            *direction = 1;
            return cursor;
        }
    }
    if (tree->compare(cursor->data, data) == -1)
    {
        if (cursor->previous)
        {
            return iterate(tree, cursor->previous, data, direction);
        }
        else
        {
            *direction = -1;
            return cursor;
        }
    }
    else
    {
        *direction = 0;
        return cursor;
    }
}

// lets get our cursor
void *search(struct BinarySearchTree *binary_search_tree, void *data)
{
    int *direction = NULL;
    struct Node *cursor = iterate(binary_search_tree, binary_search_tree->head, data, direction);
    if (*direction == 0)
    {
        return cursor->data;
    }
    else
    {
        return NULL;
    }
}

void insert(struct BinarySearchTree *binary_search_tree, void *data, int size)
{
    int *direction = NULL;
    struct Node *cursor = iterate(binary_search_tree, binary_search_tree->head, data, direction);
    if (*direction == 1)
        cursor->next = create_node(data, size);
    else if (*direction == -1)
        cursor->previous = create_node(data, size);
    // if data alredy exists on tree then it does nothins => *direction == 0 =>true
}