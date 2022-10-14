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
    //new_cat.draw_itself = draw_itself;
    new_cat.ball_list = linked_list_constructor();

    return new_cat;
}

void draw_itself(struct Cat * __self)
{
    printf("!@# chegou aqui");
    GLfloat color[3] = {0.5f,0.2f,0.4f};

    __self->drawer.draw_circle_filled(__self->coordinates,0.1f,color);

}


