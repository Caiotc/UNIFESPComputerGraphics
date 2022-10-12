#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "../Node/Node.h"

struct LinkedList_int
{
    struct Node_int *head;
    int length;

    void (*insert)(int index, int data, struct LinkedList_int *linked_list);
    void (*remove)(int index, struct LinkedList_int *linked_list);
    int (*retrieve)(int index, struct LinkedList_int *linked_list);
    struct LinkedList_int (*constructor)(void);
};

struct LinkedList_int linked_list_int_constructor();
#endif