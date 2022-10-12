#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "../Node/Node.h"

struct LinkedList
{
    struct Node *head;
    int length;

    void (*insert)(int index, void *data, int size, struct LinkedList *linked_list);
    void (*remove)(int index, struct LinkedList *linked_list);
    void *(*retrieve)(int index, struct LinkedList *linked_list);
    struct LinkedList (*constructor)(void);
};

struct LinkedList linked_list_constructor(void);
void linked_list_destructor(struct LinkedList *linked_list);
#endif