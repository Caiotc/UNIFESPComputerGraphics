#ifndef NODE_H
#define NODE_H

#include <stdlib.h>
#include <stdio.h>

struct Node
{
    // data is a void pointer - casting required for any acess
    void *data;
    struct Node *next;
    struct Node *previous;
};

struct Node node_constructor(void *data, int size);
void node_destructor(struct Node *node);

#endif