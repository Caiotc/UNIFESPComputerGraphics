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

    void (*matrix_multiplier)(GLfloat**ab,GLfloat **a,int m,int n,GLfloat **b,int p,int q);
    void (*print_matrix)(GLfloat **a,int m,int n);
    void (*free_matrix)(GLfloat **matrix, int Rows);

    GLfloat (*internal_product_given_two_vectors)(GLfloat *vector_a,GLfloat *vector_b);
    GLfloat (*angle_between_two_vectors)(GLfloat *vector_a,GLfloat *vector_b); 
};

struct VectorOperations vector_operation_constructor();
void vector_operation_destroyer(struct VectorOperations * vector_operation_object);

#endif