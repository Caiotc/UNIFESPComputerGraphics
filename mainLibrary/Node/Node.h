#ifndef NODE_H
#define NODE_H

#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

enum DataTypes
{
    Special,
    Int,
    Long,
    Float,
    Double,
    Char,
    Bool
};

struct Node
{
    // data is a void pointer - casting required for any acess
    void *data;
    int data_types;
    int size;
    struct Node *next;
};

struct Node node_constructor(void *data, int data_type, int size);
void node_destructor(struct Node *node);

#endif