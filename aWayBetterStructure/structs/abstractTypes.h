#ifndef ABSTRACTTYPES_H
#define ABSTRACTTYPES_H

#include <GL/glut.h>

typedef struct node
{
    GLfloat x, y;
    struct node_coordinates *next;
    /* data */
} node_coordinates;

#endif