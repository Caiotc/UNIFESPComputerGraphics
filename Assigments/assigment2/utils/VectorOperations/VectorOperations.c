#include "./VectorOperations.h"

GLfloat distance_between_points(GLfloat *a, GLfloat *b); 
GLfloat distance_x_point(GLfloat *a, GLfloat *b);
GLfloat distance_y_point(GLfloat *a,GLfloat *b);
GLfloat * matrix_multiplier(GLfloat *a,GLfloat *b);

struct VectorOperations vector_operation_constructor(){
    struct VectorOperations new_vector_operations_object;
    new_vector_operations_object.distance_between_points = distance_between_points;
    new_vector_operations_object.distance_x_point = distance_x_point;
    new_vector_operations_object.distance_y_point = distance_y_point;
    new_vector_operations_object.matrix_multiplier = matrix_multiplier; 
}

GLfloat distance_between_points(GLfloat *a,GLfloat *b){
    GLfloat squared_sum = pow(a[0] - b[0],2) + pow(a[1] - b[1],2);
    GLfloat distance_between_points = sqrt(squared_sum);

    return distance_between_points;
}
GLfloat distance_x_point(GLfloat *a, GLfloat *b){
    return sqrt(pow(a[0]-b[0],2));
}
GLfloat distance_y_point(GLfloat *a, GLfloat *b){
    return sqrt(pow(a[1]-b[1],2));
}

GLfloat * matrix_multiplier(GLfloat *a,GLfloat *b){
    //2x1 matrix
    GLfloat *new_vector;
    new_vector = malloc(2*sizeof(GLfloat));

    GLfloat sum;
    for(int i = 0;i<2;i++){
        for(int j = 0; j<2;j++){
            new_vector[i] += a[i]*b[j];
            //for(int k = 0;k <2;k++)             
        }
    };
    return new_vector;
}

