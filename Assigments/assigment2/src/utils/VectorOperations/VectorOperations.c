#include "./VectorOperations.h"

GLfloat distance_between_points(GLfloat *a, GLfloat *b); 
GLfloat distance_x_point(GLfloat *a, GLfloat *b);
GLfloat distance_y_point(GLfloat *a,GLfloat *b);
GLfloat * matrix_multiplier(GLfloat **a,int m,int n,GLfloat **b,int p,int q);
void print_matrix(GLfloat **a,int m, int n);
struct VectorOperations vector_operation_constructor(){
    struct VectorOperations new_vector_operations_object;
    new_vector_operations_object.distance_between_points = distance_between_points;
    new_vector_operations_object.distance_x_point = distance_x_point;
    new_vector_operations_object.distance_y_point = distance_y_point;
    new_vector_operations_object.matrix_multiplier = matrix_multiplier;

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
GLfloat * matrix_multiplier(GLfloat **a,int m,int n,GLfloat **b,int p,int q){
    GLfloat  new_vector[m][q];
    GLfloat *return_ptr = &new_vector[0][0];
    //init matrix with 0.0f
    for(int i =0;i <m;i++){
        for(int j = 0;j<q;j++){
            new_vector[i][j] = 0.0f;
        }
    }
        
    
    print_matrix(&return_ptr,m,q); 
    

    for(int i = 0;i<m;i++){
        for(int j = 0; j<q;j++){
            for(int k = 0; k<q;k++)                         
                new_vector[i][j] += a[i][k] * b[i][j]; 
        }
    };
    return return_ptr;
}
void print_matrix(GLfloat **a,int m, int n){
    for(int i =0;i<m;i++){
        for(int j =0;j<n;j++){
              printf(" %f ",a[i][j] );  
        }
        printf("\n ");
    }
}

