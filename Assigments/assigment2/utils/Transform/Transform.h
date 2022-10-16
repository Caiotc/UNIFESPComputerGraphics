#ifndef TRANSFORM_H
#define TRANSFORM_H
#include <GL/glut.h>

struct Transform{
        void(*translate)(GLfloat * point_a,GLfloat * point_b);
        void(*scale)(GLfloat * point_a, float scale_factor);
        void(*rotate)(GLfloat * point_a,GLfloat * point_b );
}; 
    struct Transform transform_constructor(void);
    struct Transform transform_destructor(void);
#endif