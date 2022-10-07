#ifndef TYPESANDCONST_H
#define TYPESANDCONST_H

#include <GL/glut.h>
const GLfloat DEFAULT_COLORS[10][3];
typedef struct node
{
    GLfloat x, y;
    struct node_coordinates *next;
    int modeToDraw;
    int strokeSize;
    int colorSelector;
    /* data */
} node_coordinates;

#endif