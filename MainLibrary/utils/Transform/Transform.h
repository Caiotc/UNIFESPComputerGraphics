#ifndef TRANSFORM_H
#define TRANSFORM_H
#include <GL/glut.h>
#include <stdlib.h>
#include "../VectorOperations/VectorOperations.h"

struct Transform{
    struct VectorOperations vector_operations_helper;

    void (*translate)(GLfloat ** coordinate_matrix,GLfloat * point_a,GLfloat * point_b,struct Transform * __self);
    void(*scale)(GLfloat * point_a, float scale_factor);
    void(*rotate)(GLfloat ** coordinate_matrix,GLfloat * center_coordinates,GLfloat * point_to_rotate,GLfloat angle,struct Transform * __self);

}; 
    struct Transform transform_constructor(void);
    void transform_destructor(struct Transform * transform_object_reference);

#endif