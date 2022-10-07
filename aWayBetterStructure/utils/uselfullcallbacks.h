#ifndef __USEFULLCALLBACKS_H
#define __USEFULLCALLBACKS_H
#include <GL/glut.h>
#include "../structs/types_and_consts.h"

void draw_circle(node_coordinates *a, GLfloat radius);
void call_vertex_2d_from_node(node_coordinates *node);
void print_node_values(node_coordinates *node);
void draw_on_two_points(node_coordinates *a, node_coordinates *b);

#endif