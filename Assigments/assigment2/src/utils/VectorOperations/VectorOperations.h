#ifndef VECTOR_OPERATIONS_H
#define VECTOR_OPERATIONS_H
#include <GL/glut.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
struct VectorOperations{

    // v^2 vectorial space operations
    GLfloat (*distance_between_points)(GLfloat *a,GLfloat *b);
    GLfloat (*distance_x_point)(GLfloat *a,GLfloat *b);
    GLfloat (*distance_y_point)(GLfloat *a,GLfloat *b);

    GLfloat * (*matrix_multiplier)(GLfloat **a,int m,int n,GLfloat **b,int p,int q);
    void (*print_matrix)(GLfloat **a,int m,int n);
};

struct VectorOperations vector_operation_constructor();
void vector_operation_destroyer(struct VectorOperations * vector_operation_object);

#endif