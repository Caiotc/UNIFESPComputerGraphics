#include "./LinkedList.h"
#include "../utils/MyPrimitives/Ball.h"


struct Node *iterate(int index, struct LinkedList *linked_list);

void insert_node(int index, void *data, int size, struct LinkedList *linked_list);
void remove_node(int index, struct LinkedList *linked_list);
void *retrieve_data(int index, struct LinkedList *linked_list);

struct LinkedList linked_list_constructor()
{

    struct LinkedList new_list;
    new_list.head = NULL;
    new_list.length = 0;
    new_list.insert = insert_node;
    new_list.remove = remove_node;
    new_list.retrieve = retrieve_data;

    return new_list;
}

void linked_list_destructor(struct LinkedList *linked_list)
{
    int i;
    for (i = 0; i < linked_list->length; i++)
        linked_list->remove(i, linked_list);
}

// iterate untill reaches the given index
struct Node *iterate(int index, struct LinkedList *linked_list)
{
    int i;
    if (index < 0 || index >= linked_list->length)
    {
        printf("\nIndex out of bounds");
        exit(9);
    }
    struct Node *cursor = linked_list->head;
    for (i = 0; i < index; i++)
    {
        cursor = cursor->next;
    }
    return cursor;
}

void insert_node(int index, void *data, int size, struct LinkedList *linked_list)
{
    struct Node *node_to_insert = create_node(data, size);
    if (index == 0)
    {
        node_to_insert->next = linked_list->head;
        linked_list->head = node_to_insert;

    }
    else
    {
        // retrieves the correct node -> the predecessor of the index
        struct Node *cursor = iterate(index - 1, linked_list);

        node_to_insert->next = cursor->next;
        cursor->next = node_to_insert;
    }
    linked_list->length++;
}

void remove_node(int index, struct LinkedList *linked_list)
{
    struct Node *node_to_remove;
    struct Node *cursor;
    if (index == 0)
    {
        node_to_remove = linked_list->head;
        linked_list->head = node_to_remove->next;
    }
    else
    { // retrieves the correct node -> the predecessor of the index
        cursor = iterate(index - 1, linked_list);
        node_to_remove = cursor->next;
        cursor->next = node_to_remove->next;
        destroy_node(node_to_remove);
    }
    destroy_node(node_to_remove);
    linked_list->length--;
}

void *retrieve_data(int index, struct LinkedList *linked_list)
{

    struct Node *cursor = iterate(index, linked_list);
    return cursor->data;
}