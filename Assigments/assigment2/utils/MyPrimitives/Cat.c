#include "./Cat.h"

void draw_itself(struct Cat * __self);
void pursuit_ball(GLfloat ball_x,GLfloat ball_y);
void cat_do_flip();
void cat_resize();

struct Cat cat_constructor(GLfloat x,GLfloat y,GLfloat cat_size){
    printf("\n!@# cat constructor");
    struct Cat new_cat;
    new_cat.coordinates[0] = x;
    new_cat.coordinates[1] = y;
    new_cat.cat_size = cat_size;
    printf("\n!@# it does create the cat, now it will create the drawer");
    new_cat.drawer = basic_shape_drawer_constructor();
    printf("\n!@# it does create the drawer");

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
    ///////////////////////
    // calculate cat proporstions
    GLfloat cat_size = __self->cat_size;
    GLfloat first_circle_tail_size = cat_size * 1.0f/12.0f;
    GLfloat second_circle_tail_size = cat_size * 1.0f/12.0f;
    GLfloat third_circle_tail_size = cat_size * 1.0f/12.0f;
    GLfloat body_size = cat_size *1.0f/2.0f;
    GLfloat head_size = cat_size *2.0f/12.0f;
    GLfloat mustache_base_size = cat_size * 1.0f/12.0f; 
    GLfloat mustache_size = mustache_base_size*2;
    ///////////////////////////////////////

    GLint blue[3] = {50, 64, 168};
    GLint orange[3] = {232, 96, 5};
    GLint green[3]={30, 255, 0};

    GLint roxo[3] = {243, 2, 247};
    GLint black[3] = {0, 0, 0};



    //Referencial points
    GLfloat extremity_right_point[2] = {__self->coordinates[0] + cat_size/2,__self->coordinates[1]};
    GLfloat extremity_left_point[2] = {__self->coordinates[0] - cat_size/2,__self->coordinates[1]};
    

    
    ///////define points from cat center point -> since the center is 
    //Glfloat first_circle_tail_center_coordinates[2] = {__self->coordinates[0]}
    //GLfloat body_center_coordinate[2] = {__self->coordinates[0] - __self->coordinates[0]*body_size,__self->coordinates[1] };
    // GLfloat head_center_coordinate[2] = {body_center_coordinate[0] +  (body_center_coordinate[0]*head_size),__self->coordinates[1]};
    // GLfloat mustache_base_a_coordinates[2] = {head_center_coordinate[0] + (head_center_coordinate[0]*mustache_base_size),head_center_coordinate[1] + head_center_coordinate[1]*mustache_base_size};
    // GLfloat mustache_base_b_coordinates[2] = {head_center_coordinate[0] + (head_center_coordinate[0]*mustache_base_size),head_center_coordinate[1] - head_center_coordinate[1]*mustache_base_size};




    //printf("\n!@# coordenada x:%f,coordenada y:%f",body_center_coordinate[0],body_center_coordinate[1]);
    //Dray cat body
     //__self->drawer.draw_circle_filled(body_center_coordinate,body_size/2,roxo);
    // __self->drawer.draw_circle_filled(head_center_coordinate,head_size/2,black);
    // __self->drawer.draw_circle_filled(mustache_base_a_coordinates,mustache_base_size/2,roxo);
    // __self->drawer.draw_circle_filled(mustache_base_b_coordinates,mustache_base_size/2,roxo);

    //__self->drawer.draw_circle_filled(__self->coordinates,0.010f,black);

    //referencial draw
    __self->drawer.draw_line(extremity_left_point,extremity_right_point,green);
    __self->drawer.draw_point(__self->coordinates,black);

}


