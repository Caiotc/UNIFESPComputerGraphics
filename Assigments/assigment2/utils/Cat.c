#include "./Cat.h"

void draw_itself(GLfloat actual_x,GLfloat actual_y,struct Cat * __self);
void pursuit_ball(GLfloat ball_x,GLfloat ball_y);
void cat_do_flip();
void cat_resize();

struct Cat cat_constructor(GLfloat x,GLfloat y){
    struct Cat new_cat;
    new_cat.cat_initial_x = x;
    new_cat.cat_initial_y = y;
    //new_cat.draw_itself = draw_itself;
    new_cat.ball_list = linked_list_constructor();

    return new_cat;
}

