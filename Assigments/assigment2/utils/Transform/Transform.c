#include "./Transform.h"


void translate(GLfloat *point_a,GLfloat*point_b);
void scale(GLfloat *point_a,float scale_factor);
void rotate(GLfloat * point_a, GLfloat * point_b);

struct Transform transform_constructor(){
    struct Transform new_transform;
    new_transform.translate = translate;
    new_transform.scale = scale;
    new_transform.rotate = rotate;

    return new_transform;
}

void translate(GLfloat *point_a,GLfloat*point_b){
    GLfloat [3][3] = {
        {1, 0,}
    }
}

