#include "./Cat.h"

void draw_itself(struct Cat * __self,struct BasicShapeDrawer *drawer);
void pursuit_ball(GLfloat ball_x,GLfloat ball_y);
void cat_do_flip();
void cat_resize();

void draw_collisor(struct Cat *__self,struct BasicShapeDrawer *drawer, GLfloat *color);
struct Cat cat_constructor(GLfloat * cat_center_coordinates,GLfloat cat_size){
    struct Cat new_cat;    
    new_cat.cat_center_coordinates = cat_center_coordinates;
    new_cat.cat_size = cat_size;
    new_cat.draw_itself = draw_itself;

    return new_cat;
}

void cat_destructor( struct Cat *cat)
{
    
    free(cat);    
};


void draw_itself(struct Cat * __self,struct BasicShapeDrawer* drawer)
{
    printf("\n!@# the cat will be draw");
    ///////////////////////
    // calculate cat proporstions
    GLfloat cat_size = __self->cat_size;
    GLfloat tail_circle_size = cat_size * 1.0f/12.0f;
    GLfloat second_circle_tail_size = cat_size * 1.0f/12.0f;
    GLfloat third_circle_tail_size = cat_size * 1.0f/12.0f;
    GLfloat body_size = cat_size *1.0f/2.0f;
    GLfloat head_size = cat_size *2.0f/12.0f;
    GLfloat mustache_base_size = cat_size * 1.0f/12.0f; 
    GLfloat mustache_size = mustache_base_size*2;
    ///////////////////////////////////////


    GLfloat gray[3] ={0.5490196f,0.61568f,0.517647f}; 
    GLfloat roxo[3] = {243, 2, 247};
    GLfloat black[3] = {0.0f, 0.0f, 0.f};
    GLfloat green[3] = {0.0f, 1.0f, 0.f};
    GLfloat blue[3] = {0.0f,0.0f,1.0f};
    GLfloat orange[3] = {1.0f,0.60392f,0.011764f};

    //Referencial points
    GLfloat extremity_right_point[2] = {__self->cat_center_coordinates[0] + cat_size/2,__self->cat_center_coordinates[1]};
    GLfloat extremity_left_point[2] = {__self->cat_center_coordinates[0] - cat_size/2,__self->cat_center_coordinates[1]};
    
    
    ///////define points from cat center point -> since the center is 
    GLfloat first_circle_tail_center_coordinates[2] = {extremity_left_point[0] + tail_circle_size/2,__self->cat_center_coordinates[1]};
    GLfloat second_circle_tail_center_coordinates[2] = {first_circle_tail_center_coordinates[0] + tail_circle_size,__self->cat_center_coordinates[1]};
    GLfloat third_circle_tail_center_coordinates[2] = {second_circle_tail_center_coordinates[0] + tail_circle_size,__self->cat_center_coordinates[1]};
    GLfloat body_center_coordinate[2] = { third_circle_tail_center_coordinates[0] + body_size/2 + tail_circle_size/2,__self->cat_center_coordinates[1] };    
    GLfloat head_center_coordinate[2] = {body_center_coordinate[0] + body_size/2 + head_size/2,__self->cat_center_coordinates[1]};
    GLfloat mustache_base_a_coordinates[2] = {head_center_coordinate[0] + head_size/2 + mustache_base_size/2,__self->cat_center_coordinates[1] +  mustache_base_size/2 };
    GLfloat mustache_base_b_coordinates[2] = {head_center_coordinate[0] + head_size/2 + mustache_base_size/2,__self->cat_center_coordinates[1] -  mustache_base_size/2 };


    //Draw cat 
    drawer->draw_circle_filled(first_circle_tail_center_coordinates,tail_circle_size/2,orange);
    drawer->draw_circle_filled(second_circle_tail_center_coordinates,tail_circle_size/2,gray);
    drawer->draw_circle_filled(third_circle_tail_center_coordinates,tail_circle_size/2,orange);
    drawer->draw_circle_filled(body_center_coordinate,body_size/2,orange);
    drawer->draw_circle_filled(head_center_coordinate,head_size/2,orange);
    drawer->draw_circle_filled(mustache_base_a_coordinates,mustache_base_size/2,gray);
    drawer->draw_circle_filled(mustache_base_b_coordinates,mustache_base_size/2,gray);

    //referencial draw
    drawer->draw_line(extremity_left_point,extremity_right_point,green);
    drawer->draw_point(__self->cat_center_coordinates,black);


    draw_collisor(__self,drawer,green);
}

void draw_collisor(struct Cat *__self,struct BasicShapeDrawer *drawer, GLfloat *color){
    GLfloat collisor_center[2] = {__self->cat_center_coordinates[0],__self->cat_center_coordinates[1]};
    GLfloat collisor_height = __self->cat_size *1.0f/2.0f;

    GLfloat first_diagonal_collisor_point[2] ={__self->cat_center_coordinates[0] - __self->cat_size/2,__self->cat_center_coordinates[1] - collisor_height/2};
    GLfloat second_diagonal_collisor_point[2] ={__self->cat_center_coordinates[0] + __self->cat_size/2,__self->cat_center_coordinates[1] + collisor_height/2};

    drawer->draw_quadrilateral_line(first_diagonal_collisor_point,second_diagonal_collisor_point,color);
}


