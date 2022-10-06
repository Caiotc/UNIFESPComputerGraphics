#include "uselfullcallbacks.h"
#include <stdio.h>

void call_vertex_2d_from_node(node_coordinates *node)
{
    // test

    glVertex2f(node->x, node->y);
}

void print_node_values(node_coordinates *node)
{

    printf("%f %f\n", node->x, node->y);
}