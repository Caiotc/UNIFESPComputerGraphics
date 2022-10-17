#include "./Transform.h"


GLfloat **  translate(GLfloat *point_a,GLfloat*point_b,struct Transform * __self);
void scale(GLfloat *point_a,float scale_factor);
void rotate(GLfloat * point_a, GLfloat * point_b);

struct Transform transform_constructor(){
    struct Transform new_transform;
    new_transform.vector_operations_helper = vector_operation_constructor();
    new_transform.translate = translate;
    //new_transform.scale = scale;
    //new_transform.rotate = rotate;

    return new_transform;
}

void transform_destructor(struct Transform * transform_object_reference){
    vector_operation_destroyer(&transform_object_reference->vector_operations_helper);
    free( transform_object_reference);     
}


GLfloat **  translate(GLfloat *point_a,GLfloat*point_b,struct Transform * __self){
    printf("\n!@# caiu no calculador de transformacao");
    GLfloat *new_pos_ptr;
    GLfloat ** return_matrix;
    printf("\n!@# chegou aqui");
    GLfloat x_distance = __self->vector_operations_helper.distance_x_point(point_a,point_b);
    GLfloat y_distance = __self->vector_operations_helper.distance_y_point(point_a,point_b);

    GLfloat translate_matrix[3][3] = {
        {1.0f,0.0f,x_distance},
        {0.0,1.0f,y_distance},
        {0.0,0.0f,1.0f}        
    };
    GLfloat point_homogenization[3][1] = {
        point_a[0],
        point_a[1],
        1,        
    }; 

    GLfloat *translate_matrix_ptr = & translate_matrix[0][0];
    GLfloat *point_homogenization_ptr = & translate_matrix[0][0];

    new_pos_ptr = __self->vector_operations_helper.matrix_multiplier(&translate_matrix_ptr,3,3,&point_homogenization_ptr,3,1);
    return_matrix = &new_pos_ptr;

    return return_matrix;
}

