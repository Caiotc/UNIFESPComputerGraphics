#ifndef NODE_H
#define NODE_H
#include <stdlib.h>
#include <stdio.h>


struct Node
{
    int counter;
    // data is a void pointer - casting required for any acess
    void *data;
    struct Node *next;
    struct Node *previous;
};

struct Node node_constructor(void *data, int size);
void node_destructor(struct Node *node);
struct Node *create_node(void *data, int size);

void destroy_node(struct Node *node);
#endif