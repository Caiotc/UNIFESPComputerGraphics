#include "./Cat.h"

void draw_itself(struct Cat * __self);
void pursuit_ball(GLfloat ball_x,GLfloat ball_y);
void cat_do_flip();
void cat_resize();

struct Cat cat_constructor(GLfloat x,GLfloat y){
    struct Cat new_cat;
    new_cat.coordinates[0] = x;
    new_cat.coordinates[1] = y;
    new_cat.drawer = basic_shape_drawer_constructor();
    new_cat.draw_itself = draw_itself;
    new_cat.ball_list = linked_list_constructor();

    return new_cat;
}

void cat_destructor( struct Cat *cat)
{
    linked_list_destructor(&cat->ball_list);
    basic_shape_drawer_destroyer(&cat->drawer);
    free(cat);    
};


void draw_itself(struct Cat * __self)
{
    printf("\n!@# chegou aqui");
    GLfloat roxo[3] = {0.5f,0.2f,0.4f};
    GLfloat black[3] = {0.0f,0.0f,0.0f};

    
    // GLfloat eye_one coordinate[2];
    // GLfloat eye_two coordinate[2]

    // Glfloat cat_ear1 coordinate[2];
    // Glfloat cat_ear2 coordinate[2];

    // GLfolat head_coordinate[2];
    // GLfloat body_coordinate[2];

    __self->drawer.draw_circle_filled(__self->coordinates,0.1f,roxo);
    __self->drawer.draw_circle_filled(__self->coordinates,0.010f,black);

}


