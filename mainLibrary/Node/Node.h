#ifndef NODE_H
#define NODE_H

#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

struct Node_int
{
    // data is a void pointer - casting required for any acess
    int data;

    // type of data

    // pointer to next node in chain
    struct Node_int *next;
};

#endif