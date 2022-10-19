#include "./VectorOperations.h"
#include <math.h>

GLfloat distance_between_points(GLfloat *a, GLfloat *b); 
GLfloat distance_x_point(GLfloat *a, GLfloat *b);
GLfloat distance_y_point(GLfloat *a,GLfloat *b);
void matrix_multiplier(GLfloat**ab,GLfloat **a,int m,int n,GLfloat **b,int p,int q);
void print_matrix(GLfloat **a,int m, int n);
void free_matrix(GLfloat **matrix, int Rows);
GLfloat internal_product_given_two_vectors(GLfloat *vector_a,GLfloat *vector_b);
GLfloat angle_between_two_vectors(GLfloat *vector_a,GLfloat *vector_b); 
GLfloat angle_between_two_vectors_given_a_referential(GLfloat *vector_referential,GLfloat * vector_a,GLfloat *vector_b);
GLfloat calculate_vector_norm(GLfloat *vector_a);

struct VectorOperations vector_operation_constructor(){
    struct VectorOperations new_vector_operations_object;


    
    new_vector_operations_object.print_matrix = print_matrix;
    new_vector_operations_object.distance_between_points = distance_between_points;
    new_vector_operations_object.distance_x_point = distance_x_point;
    new_vector_operations_object.distance_y_point = distance_y_point;
    new_vector_operations_object.matrix_multiplier = matrix_multiplier;
    new_vector_operations_object.free_matrix = free_matrix;
    new_vector_operations_object.internal_product_given_two_vectors = internal_product_given_two_vectors;
    new_vector_operations_object.angle_between_two_vectors = angle_between_two_vectors;
    new_vector_operations_object.angle_between_two_vectors_given_a_referential =angle_between_two_vectors_given_a_referential;


    return new_vector_operations_object; 
}

void vector_operation_destroyer(struct VectorOperations * vector_operation_object){
    free(vector_operation_object);
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

/**
 * @brief This multiplies matrices
 * 
 * @param a pointer to first matrix 
 * @param m num of lines of first matrix
 * @param n num of columns of first matrix
 * @param b pointer to second matrix
 * @param p num of lines of second matrix
 * @param q num of columns of second matrix
 * @return GLfloat* 
 */
void matrix_multiplier(GLfloat**ab, GLfloat **a,int m,int n,GLfloat **b,int p,int q){    
    
    for(int i = 0;i<m;i++){
        for(int j = 0; j<q;j++){
            for(int k = 0; k<p;k++){                                         
                ab[i][j] += a[i][k] * b[k][j];
            } 
        }
    };

}


GLfloat internal_product_given_two_vectors(GLfloat *vector_a,GLfloat* vector_b){
    return vector_a[0]*vector_b[0] + vector_a[1]*vector_b[1];
}

GLfloat angle_between_two_vectors(GLfloat * vector_a,GLfloat *vector_b){
    GLfloat cosin_of_the_angle =  internal_product_given_two_vectors(vector_a,vector_b);
    cosin_of_the_angle /= calculate_vector_norm(vector_a) * calculate_vector_norm(vector_b);

    return (GLfloat)acos(cosin_of_the_angle); 
}
GLfloat angle_between_two_vectors_given_a_referential(GLfloat *vector_referential,GLfloat * vector_a,GLfloat *vector_b){
    GLfloat new_a[2];
    GLfloat new_b[2];

    new_a[0] =vector_a[0]- vector_referential[0] ;
    new_a[1] =vector_a[1]- vector_referential[1];
    new_b[0] =vector_b[0]- vector_referential[0];
    new_b[1] =vector_b[1]- vector_referential[1];   
    GLfloat cosin_of_the_angle =  internal_product_given_two_vectors(new_a,new_b);
    cosin_of_the_angle /= calculate_vector_norm(new_a) * calculate_vector_norm(new_b);

    return (GLfloat)acosf(cosin_of_the_angle); 
}

GLfloat calculate_vector_norm(GLfloat *vector_a){

    return sqrt(pow(vector_a[0],2) + pow(vector_a[1],2));
}








void print_matrix(GLfloat **a,int m, int n){
    for(int i =0;i<m;i++){
        for(int j =0;j<n;j++){
              printf("%f ",a[i][j] );  
        }
        printf("\n");
    }
}


void free_matrix(GLfloat **matrix, int Rows) 
{
    int row;

    // first free each row
    for (row = 0; row < Rows; row++) {
         free(matrix[row]);
    }

    // Eventually free the memory of the pointers to the rows
    free(matrix);
 }

