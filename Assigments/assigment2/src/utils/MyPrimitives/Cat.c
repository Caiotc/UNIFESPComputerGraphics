#include "./Cat.h"
#define PI 3.141592654


void draw_itself(struct Cat * __self,struct BasicShapeDrawer* drawer, bool *should_transform,GLfloat * destiny_point);
void pursuit_ball(struct Cat * __self);
void prepare_points_list(struct Cat * __self);
void cat_do_flip();
void cat_resize();

void draw_collisor(struct Cat *__self,struct BasicShapeDrawer *drawer, GLfloat *color);
struct Cat cat_constructor(GLfloat * cat_center_coordinates,GLfloat cat_size,struct Queue * ball_queue,  struct Queue * points_untill_next_Ball){
    struct Cat new_cat;    
    new_cat.cat_center_coordinates = cat_center_coordinates;
    new_cat.cat_size = cat_size;
    new_cat.cat_transformer = transform_constructor();
    new_cat.draw_itself = draw_itself;
    new_cat.ball_queue = ball_queue;
    new_cat.points_untill_next_Ball = points_untill_next_Ball;
    new_cat.pursuit_ball = pursuit_ball;

    return new_cat;
}

void cat_destructor( struct Cat *cat)
{
    transform_destructor(&cat->cat_transformer);     
    free(cat);    
};


void draw_itself(struct Cat * __self,struct BasicShapeDrawer* drawer, bool *should_transform,GLfloat * destiny_point)
{


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

    ///////////////////////////////////////////
    //Kitty Collors
        GLfloat gray[3] ={0.5490196f,0.61568f,0.517647f}; 
        GLfloat roxo[3] = {243, 2, 247};
        GLfloat black[3] = {0.0f, 0.0f, 0.f};
        GLfloat green[3] = {0.0f, 1.0f, 0.f};
        GLfloat blue[3] = {0.0f,0.0f,1.0f};
        GLfloat orange[3] = {1.0f,0.60392f,0.011764f};
   
    
    
    /////////////////////////////////////////////////
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

void pursuit_ball(struct Cat * __self){
    GLfloat * actual_coordinate;
    GLfloat ** new_coordinate;
    
    if(__self->ball_queue->list.length == 0)
        return;

    if(__self->ball_queue->list.length > 0 && __self->points_untill_next_Ball->list.length == 0) {
        //sets pointslist
        printf("\n!@# a lista vai ser preparada");
        prepare_points_list(__self);          
    }
   
   if(__self->ball_queue->list.length > 0 && __self->points_untill_next_Ball->list.length != 0){ 
        actual_coordinate = (GLfloat *)__self->points_untill_next_Ball->peek(__self->points_untill_next_Ball);
        new_coordinate = (GLfloat **)malloc(3 * sizeof(GLfloat *));
        for (int i = 0; i < 3; i++) 
            new_coordinate[i] = (GLfloat *)malloc( sizeof(GLfloat));

        __self->cat_transformer.translate(new_coordinate,__self->cat_center_coordinates,actual_coordinate,&__self->cat_transformer);
        // use it
        __self->cat_center_coordinates[0] = new_coordinate[0][0];
        __self->cat_center_coordinates[1] = new_coordinate[1][0];

        __self->cat_transformer.vector_operations_helper.free_matrix(new_coordinate,3);        
        __self->points_untill_next_Ball->pop(__self->points_untill_next_Ball);
        
        
        if(__self->points_untill_next_Ball->list.length == 0){
            __self->ball_queue->pop(__self->ball_queue);
        }

   }
}

void prepare_points_list(struct Cat * __self){

    GLfloat x_dist;
    GLfloat y_dist;
    struct Ball * actual_ball;

        // this code prepares the points between the ball and the cat
        actual_ball = (struct Ball *)__self->ball_queue->peek(__self->ball_queue);
        x_dist =  __self->cat_transformer.vector_operations_helper.distance_x_point(__self->cat_center_coordinates,actual_ball->center_coordinates);
        y_dist = __self->cat_transformer.vector_operations_helper.distance_y_point(__self->cat_center_coordinates,actual_ball->center_coordinates);
        
        if(__self->cat_center_coordinates[0] > actual_ball->center_coordinates[0]){
            x_dist *= -1;
        }
        if(__self->cat_center_coordinates[1]>actual_ball->center_coordinates[1])
            y_dist *= -1;

        for(int i =0;i<60;i++){
            GLfloat coordinate_to_insert[2];
            if(__self->points_untill_next_Ball->list.length == 0){
                coordinate_to_insert[0] = __self->cat_center_coordinates[0] + x_dist/60;
                coordinate_to_insert[1] = __self->cat_center_coordinates[1] + y_dist/60;
                __self->points_untill_next_Ball->push(__self->points_untill_next_Ball,coordinate_to_insert,sizeof(coordinate_to_insert));
            }
               GLfloat * lastPoint =  (GLfloat *)__self->points_untill_next_Ball->list.retrieve(__self->points_untill_next_Ball->list.length -1,&__self->points_untill_next_Ball->list);
            

                coordinate_to_insert[0] = lastPoint[0] + x_dist/60;
                coordinate_to_insert[1] = lastPoint[1] + y_dist/60;

                __self->points_untill_next_Ball->push(__self->points_untill_next_Ball,coordinate_to_insert,sizeof(coordinate_to_insert));
        }                             

}

