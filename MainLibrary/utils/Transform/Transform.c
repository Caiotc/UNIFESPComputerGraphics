#include "./Transform.h"


void  translate(GLfloat ** coordinate_matrix,GLfloat *point_a,GLfloat*point_b,struct Transform * __self);
void scale(GLfloat *point_a,float scale_factor);
void rotate(GLfloat ** coordinate_matrix,GLfloat * center_coordinates,GLfloat * point_to_rotate,GLfloat angle,struct Transform * __self);

struct Transform transform_constructor(){
    struct Transform new_transform;
    new_transform.vector_operations_helper = vector_operation_constructor();
    new_transform.translate = translate;
    //new_transform.scale = scale;
    new_transform.rotate = rotate;

    return new_transform;
}

void transform_destructor(struct Transform * transform_object_reference){
    vector_operation_destroyer(&transform_object_reference->vector_operations_helper);
    free( transform_object_reference);     
}


void translate(GLfloat ** coordinate_matrix,GLfloat *point_a,GLfloat*point_b,struct Transform * __self){
    GLfloat ** translate_matrix =(GLfloat **)malloc(3 * sizeof(GLfloat *));
    GLfloat ** point_homogenization =(GLfloat**) malloc(3*sizeof(GLfloat*));
    
    for (int i = 0; i < 3; i++) {
        translate_matrix[i]= (GLfloat *)malloc( 3*sizeof(GLfloat));
        point_homogenization[i] = (GLfloat *)malloc( sizeof(GLfloat));
    }
    
    for(int i = 0; i < 3; i++)
        for(int j =0;j<1;j++) 
            coordinate_matrix[i][j] = 0;
    

    
    GLfloat x_distance = __self->vector_operations_helper.distance_x_point(point_a,point_b);
    GLfloat y_distance = __self->vector_operations_helper.distance_y_point(point_a,point_b);
    if(point_a[0]>point_b[0])
        x_distance = x_distance *-1;
    if(point_a[1]>point_b[1])
        y_distance = y_distance * -1;
    
    //determine the translate matrix
    translate_matrix[0][0] = 1.0f;
    translate_matrix[0][1] = 0.0f;
    translate_matrix[0][2] = x_distance;
    translate_matrix[1][0] = 0.0f;
    translate_matrix[1][1] = 1.0f;
    translate_matrix[1][2] = y_distance;
    translate_matrix[2][0] = 0.0f;
    translate_matrix[2][1] = 0.0f;
    translate_matrix[2][2] = 1.0f;
    //////////////////////////////////////
    //point
    /////////////////////////////
     point_homogenization[0][0] = point_a[0];
     point_homogenization[1][0] = point_a[1];
     point_homogenization[2][0] = 1.0f;
    ////////////////////////////////////



    __self->vector_operations_helper.matrix_multiplier(coordinate_matrix,translate_matrix,3,3,point_homogenization,3,1);
    

    __self->vector_operations_helper.free_matrix(translate_matrix,3);
    __self->vector_operations_helper.free_matrix(point_homogenization,3);

}


void rotate(GLfloat ** coordinate_matrix,GLfloat * center_coordinates,GLfloat * point_to_rotate,GLfloat angle,struct Transform * __self){
    GLfloat ** rotate_matrix =(GLfloat **)malloc(3 * sizeof(GLfloat *));
    GLfloat ** point_homogenization =(GLfloat**) malloc(3*sizeof(GLfloat*));    
    
    for (int i = 0; i < 3; i++) {
        rotate_matrix[i]= (GLfloat *)malloc( 3*sizeof(GLfloat));
        point_homogenization[i] = (GLfloat *)malloc( sizeof(GLfloat));
    }

    for(int i = 0; i < 3; i++)
        for(int j =0;j<1;j++) 
            coordinate_matrix[i][j] = 0;
    
    rotate_matrix[0][0]=cosf(angle);//*(1 - center_coordinates[0]/point_to_rotate[0]) + center_coordinates[0]/(2*point_to_rotate[0]) ;
    rotate_matrix[0][1]=-sinf(angle);//*( 1 - center_coordinates[1]/point_to_rotate[1]) + center_coordinates[0]/(2*point_to_rotate[1]);
    rotate_matrix[0][2]=0;
    rotate_matrix[1][0]=sinf(angle);//*(1 - center_coordinates[0]/point_to_rotate[0]) + center_coordinates[1]/(2*point_to_rotate[0]);
    rotate_matrix[1][1]=cos(angle);//*(1 - center_coordinates[1]/point_to_rotate[1]) + center_coordinates[1]/(2*point_to_rotate[1]);
    rotate_matrix[1][2]=0;
    rotate_matrix[2][0]=0;
    rotate_matrix[2][1]=0;
    rotate_matrix[2][2]=1;



    point_homogenization[0][0] = center_coordinates[0] ;
    point_homogenization[1][0] = center_coordinates[1];
    point_homogenization[2][0] =  1;




    __self->vector_operations_helper.matrix_multiplier(coordinate_matrix,rotate_matrix,3,3,point_homogenization,3,1);

    __self->vector_operations_helper.free_matrix(rotate_matrix,3);
    __self->vector_operations_helper.free_matrix(point_homogenization,3);



}
