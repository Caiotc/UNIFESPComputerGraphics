#ifndef BASICE_SHAPE_DRAWER_H
#define BASIC_SHAPE_DRAWER_H
#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
struct BasicShapeDrawer
{

    void (*draw_quadrilateral_line)(GLfloat *a, GLfloat *c,GLfloat *color);
    void (*draw_quadrilateral_filled)(GLfloat *a, GLfloat *c,GLfloat *color);
    void (*draw_circle_rope)(GLfloat *center, GLfloat radius,GLfloat *color);
    void (*draw_circle_filled)(GLfloat *center, GLfloat radius,GLfloat *color);
};
struct BasicShapeDrawer basic_shape_drawer_constructor(void);
void basic_shape_drawer_destroyer(struct BasicShapeDrawer *basic_shape_drawer);
#endif
