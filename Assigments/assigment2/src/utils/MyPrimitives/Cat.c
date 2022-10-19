#include "./Cat.h"
#include <GL/gl.h>
#define PI 3.141592654


void draw_itself(struct Cat * __self,struct BasicShapeDrawer* drawer, bool *should_transform,GLfloat * destiny_point);
void pursuit_ball(struct Cat * __self);
void prepare_points_list(struct Cat * __self);
void cat_do_flip();
void cat_resize();
void prepare_angles_list(
struct Cat * __self
);

void draw_collisor(struct Cat *__self,struct BasicShapeDrawer *drawer, GLfloat *color);

struct Cat cat_constructor(
GLfloat * cat_center_coordinates,
GLfloat cat_size,
struct Queue * ball_queue,  
struct Queue * points_untill_next_Ball,
struct Queue * points_head_go_trough
){
    struct Cat new_cat;    
    new_cat.cat_center_coordinates = cat_center_coordinates;
    new_cat.cat_size = cat_size;
    new_cat.cat_transformer = transform_constructor();
    new_cat.draw_itself = draw_itself;
    new_cat.ball_queue = ball_queue;
    new_cat.points_untill_next_Ball = points_untill_next_Ball;
    new_cat.pursuit_ball = pursuit_ball;
    new_cat.cat_is_aligned = false;
    new_cat.cat_head_coordinates = NULL;
    new_cat.points_head_go_trough = points_head_go_trough;


    return new_cat;
}

void cat_destructor( struct Cat *cat)
{
    transform_destructor(&cat->cat_transformer);
    free(cat->cat_head_coordinates);     
    free(cat);    
};


void draw_itself(struct Cat * __self,struct BasicShapeDrawer* drawer, bool *should_transform,GLfloat * destiny_point)
{
    GLfloat ** new_coordinate = (GLfloat **)malloc(3 * sizeof(GLfloat *));
    GLfloat * rotation_new_point;
    for (int i = 0; i < 3; i++) 
        new_coordinate[i] = (GLfloat *)malloc( sizeof(GLfloat));



    ///////////////////////
    // calculate cat proporstions
    GLfloat cat_size = __self->cat_size;
    GLfloat tail_circle_size = cat_size * 1.0f/12.0f;
    GLfloat second_circle_tail_size = cat_size * 1.0f/12.0f;
    GLfloat third_circle_tail_size = cat_size * 1.0f/12.0f;
    GLfloat body_size = cat_size *1.0f/2.0f;
    GLfloat head_size = cat_size *2.0f/12.0f;
    GLfloat eye_size = head_size/4.0f;
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
    //GLfloat first_circle_tail_center_coordinates[2] = {extremity_left_point[0] + tail_circle_size/2,__self->cat_center_coordinates[1]};
    //GLfloat second_circle_tail_center_coordinates[2] = {first_circle_tail_center_coordinates[0] + tail_circle_size,__self->cat_center_coordinates[1]};
    //GLfloat third_circle_tail_center_coordinates[2] = {second_circle_tail_center_coordinates[0] + tail_circle_size,__self->cat_center_coordinates[1]};
    // GLfloat body_center_coordinate[2] = { extremity_left_point[0] + body_size/2 ,__self->cat_center_coordinates[1] };
    // GLfloat cat_head_coordinates[2] = {body_center_coordinate[0] + body_size/2 + head_size/2,};

    GLfloat first_circle_tail_center_coordinates[2] = {extremity_left_point[0] + tail_circle_size/2,__self->cat_center_coordinates[1]};
    GLfloat second_circle_tail_center_coordinates[2] = {first_circle_tail_center_coordinates[0] + tail_circle_size,__self->cat_center_coordinates[1]};
    GLfloat third_circle_tail_center_coordinates[2] = {second_circle_tail_center_coordinates[0] + tail_circle_size,__self->cat_center_coordinates[1]};
    GLfloat body_center_coordinate[2] = { third_circle_tail_center_coordinates[0] + body_size/2 + tail_circle_size/2,__self->cat_center_coordinates[1] };    
    GLfloat head_center_coordinate[2] = {body_center_coordinate[0] + body_size/2 + head_size/2,__self->cat_center_coordinates[1]};
    GLfloat eye_one_center_coordinate[2]= {head_center_coordinate[0] + head_size/4,head_center_coordinate[1] + eye_size };
    GLfloat eye_two_center_coordinate[2]= {head_center_coordinate[0] + head_size/4,head_center_coordinate[1] - eye_size };
    GLfloat mustache_base_a_coordinates[2] = {head_center_coordinate[0] + head_size/2 + mustache_base_size/2,__self->cat_center_coordinates[1] +  mustache_base_size/2 };
    
    GLfloat mustache_a_one_base[2] = {head_center_coordinate[0] + head_size/2 + mustache_base_size/6, __self->cat_center_coordinates[1] +  mustache_base_size/2};
    GLfloat mustache_a_two_base[2] = {head_center_coordinate[0] + head_size/2 +  mustache_base_size/2, __self->cat_center_coordinates[1] +  mustache_base_size/2};
    GLfloat mustache_a_three_base[2] = {head_center_coordinate[0] + head_size/2 +  mustache_base_size, __self->cat_center_coordinates[1] +  mustache_base_size/2};
    GLfloat mustache_a_one[2] = {head_center_coordinate[0] - head_size/2 + mustache_base_size/6, __self->cat_center_coordinates[1] + 2*mustache_base_size};
    GLfloat mustache_a_two[2] = {head_center_coordinate[0] + head_size/2 +  mustache_base_size/2, __self->cat_center_coordinates[1] + 2*mustache_base_size};
    GLfloat mustache_a_three[2] = {head_center_coordinate[0] + head_size +  mustache_base_size, __self->cat_center_coordinates[1] +  2*mustache_base_size};
    
    
    GLfloat mustache_base_b_coordinates[2] = {head_center_coordinate[0] + head_size/2 + mustache_base_size/2,__self->cat_center_coordinates[1] -  mustache_base_size/2 };

    GLfloat mustache_b_one_base[2] = {head_center_coordinate[0] + head_size/2 + mustache_base_size/6, __self->cat_center_coordinates[1] -  mustache_base_size/2};
    GLfloat mustache_b_two_base[2] = {head_center_coordinate[0] + head_size/2 +  mustache_base_size/2, __self->cat_center_coordinates[1] -  mustache_base_size/2};
    GLfloat mustache_b_three_base[2] = {head_center_coordinate[0] + head_size/2 +  mustache_base_size, __self->cat_center_coordinates[1] -  mustache_base_size/2};
    GLfloat mustache_b_one[2] = {head_center_coordinate[0] - head_size/2 + mustache_base_size/6, __self->cat_center_coordinates[1] - 2*mustache_base_size};
    GLfloat mustache_b_two[2] = {head_center_coordinate[0] + head_size/2 +  mustache_base_size/2, __self->cat_center_coordinates[1] - 2*mustache_base_size};
    GLfloat mustache_b_three[2] = {head_center_coordinate[0] + head_size +  mustache_base_size, __self->cat_center_coordinates[1] -  2*mustache_base_size};
    
    
    



    // if( __self->cat_head_coordinates == NULL){
    //     __self->cat_head_coordinates = (GLfloat*)malloc(2*sizeof(GLfloat));            
    //     __self->cat_head_coordinates[0] = body_center_coordinate[0] + body_size/2 + head_size/2;
    //     __self->cat_head_coordinates[1] = __self->cat_center_coordinates[1];
    // }


   
    //Draw cat 
    drawer->draw_circle_filled(first_circle_tail_center_coordinates,tail_circle_size/2,orange);
    drawer->draw_circle_filled(second_circle_tail_center_coordinates,tail_circle_size/2,gray);
    drawer->draw_circle_filled(third_circle_tail_center_coordinates,tail_circle_size/2,orange);
    drawer->draw_circle_filled(body_center_coordinate,body_size/2,orange);
    drawer->draw_circle_filled(head_center_coordinate,head_size/2,orange);
    drawer->draw_circle_filled(eye_one_center_coordinate,eye_size/2,black);
    drawer->draw_circle_filled(eye_two_center_coordinate,eye_size/2,black);

    drawer->draw_circle_filled(mustache_base_a_coordinates,mustache_base_size/2,gray);
    drawer->draw_circle_filled(mustache_base_b_coordinates,mustache_base_size/2,gray);

    drawer->draw_line(mustache_a_one_base,mustache_a_one,black);
    drawer->draw_line(mustache_a_two_base,mustache_a_two,black);
    drawer->draw_line(mustache_a_three_base,mustache_a_three,black);

    drawer->draw_line(mustache_b_one_base,mustache_b_one,black);
    drawer->draw_line(mustache_b_two_base,mustache_b_two,black);
    drawer->draw_line(mustache_b_three_base,mustache_b_three,black);    


    //referencial draw
    // drawer->draw_line(extremity_left_point,extremity_right_point,green);
    // drawer->draw_point(__self->cat_center_coordinates,black);


    // draw_collisor(__self,drawer,green);

    __self->cat_transformer.vector_operations_helper.free_matrix(new_coordinate,3);        

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
    GLfloat angle;
    GLfloat angle_to_transform;

    if(__self->ball_queue->list.length == 0)
        return;
    struct Ball * ball_ref = (struct Ball *)__self->ball_queue->peek(__self->ball_queue);

    //BLOCO DA ROTACAO Q EU N CONSEGUI FAZER
    // angle = __self->cat_transformer.vector_operations_helper.
    //     angle_between_two_vectors(__self->cat_center_coordinates,ball_ref->center_coordinates);
    // if(angle > 0 && __self->points_head_go_trough->list.length == 0 && !__self->cat_is_aligned){
    //     prepare_angles_list(__self);
    //     __self->cat_is_aligned = true;
    // }
    // if(__self->points_head_go_trough->list.length >0){

    //     angle_to_transform = *((GLfloat *)__self->points_head_go_trough->peek(__self->points_head_go_trough));        
    //     new_coordinate = (GLfloat **)malloc(3 * sizeof(GLfloat *));
    //     for (int i = 0; i < 3; i++) 
    //         new_coordinate[i] = (GLfloat *)malloc( sizeof(GLfloat));
    //     //get the new coord for head;
    //     __self->cat_transformer.rotate(
    //         new_coordinate,
    //         __self->cat_center_coordinates,
    //         __self->cat_head_coordinates,
    //         angle_to_transform
    //         ,&__self->cat_transformer);

    //     __self->cat_head_coordinates[0] = new_coordinate[0][0] ;
    //     __self->cat_head_coordinates[1] = new_coordinate[1][0]   ;

    //     __self->cat_transformer.vector_operations_helper.free_matrix(new_coordinate,3);
    //     __self->points_head_go_trough->pop(__self->points_head_go_trough);
    //     printf("\n!@# ta dando pop nessa porra tamanho da lista %d\n",__self->points_head_go_trough->list.length);

       
    //     return;

    // }    
    
    
    if(__self->ball_queue->list.length > 0 && __self->points_untill_next_Ball->list.length == 0) {
        //sets pointslist
        printf("\n!@# a fila de pontos entre o gato e a bola vai ser  \n");
        prepare_points_list(__self);
         //__self->cat_is_aligned = false;
          
    }
   
   if(__self->ball_queue->list.length > 0 && __self->points_untill_next_Ball->list.length != 0){ 
        actual_coordinate = (GLfloat *)__self->points_untill_next_Ball->peek(__self->points_untill_next_Ball);
        new_coordinate = (GLfloat **)malloc(3 * sizeof(GLfloat *));
        for (int i = 0; i < 3; i++) 
            new_coordinate[i] = (GLfloat *)malloc( sizeof(GLfloat));

        __self->cat_transformer.translate(new_coordinate,__self->cat_center_coordinates,actual_coordinate,&__self->cat_transformer);
        // // use it
        //  GLfloat dist_x  =  sqrt(pow(new_coordinate[0][0] -__self->cat_center_coordinates[0]  ,2));
        //     GLfloat dist_y  =sqrt(pow(new_coordinate[1][0] - __self->cat_center_coordinates[1] ,2));

        //     if(__self->cat_center_coordinates[0]>__self->cat_head_coordinates[0])
        //         dist_x *= -1;
        //     if(__self->cat_center_coordinates[1]>__self->cat_head_coordinates[1])
        //             dist_y *= -1;
        // // __self->cat_head_coordinates[0] += dist_x;
        // // __self->cat_head_coordinates[1] += dist_y ;

        __self->cat_center_coordinates[0] = new_coordinate[0][0];
        __self->cat_center_coordinates[1] = new_coordinate[1][0];
        
        __self->cat_transformer.vector_operations_helper.free_matrix(new_coordinate,3);        
        __self->points_untill_next_Ball->pop(__self->points_untill_next_Ball);
        
        
        if(__self->points_untill_next_Ball->list.length == 0){
            __self->ball_queue->pop(__self->ball_queue);
        }

        return;

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

        for(int i =0;i<35;i++){
            GLfloat coordinate_to_insert[2];
            if(__self->points_untill_next_Ball->list.length == 0){
                coordinate_to_insert[0] = __self->cat_center_coordinates[0] + x_dist/35;
                coordinate_to_insert[1] = __self->cat_center_coordinates[1] + y_dist/35;
                __self->points_untill_next_Ball->push(__self->points_untill_next_Ball,coordinate_to_insert,sizeof(coordinate_to_insert));
                continue;
            }
               GLfloat * lastPoint =  (GLfloat *)__self->points_untill_next_Ball->list.retrieve(__self->points_untill_next_Ball->list.length -1,&__self->points_untill_next_Ball->list);
            

                coordinate_to_insert[0] = lastPoint[0] + x_dist/35;
                coordinate_to_insert[1] = lastPoint[1] + y_dist/35;

                __self->points_untill_next_Ball->push(__self->points_untill_next_Ball,coordinate_to_insert,sizeof(coordinate_to_insert));
        }                             

}

void align_cat(struct Cat * __self){

}

void prepare_angles_list(
struct Cat * __self
){
    GLfloat x_dist;
    GLfloat y_dist;    
    GLfloat ** new_coordinate;
    GLfloat new_coord_pair[2];
    GLfloat angle_between_two_vectors;
    
    printf("\n!@#coordenadas da cabeca do gato x%f y%f \n",
    __self->cat_head_coordinates[0],
    __self->cat_head_coordinates[1]);

    new_coordinate = (GLfloat **)malloc(3 * sizeof(GLfloat *));
    for (int i = 0; i < 3; i++) 
        new_coordinate[i] = (GLfloat *)malloc( sizeof(GLfloat));


    struct Ball * ball_ref;
    ball_ref = (struct Ball *)__self->ball_queue->peek(__self->ball_queue);

    
    angle_between_two_vectors =
     __self->cat_transformer.vector_operations_helper.
        angle_between_two_vectors_given_a_referential(__self->cat_center_coordinates,__self->cat_head_coordinates,ball_ref->center_coordinates);
        GLfloat * value =(GLfloat*) malloc(sizeof(GLfloat));
        *value = angle_between_two_vectors/40;
        for(int i =0;i<40;i++){        
            __self->points_head_go_trough->push(__self->points_head_go_trough,value,sizeof(angle_between_two_vectors));            
        } 
        free(value);
    __self->cat_transformer.vector_operations_helper.free_matrix(new_coordinate,3);

    printf("\n!@# se liga nessa fita tamanho de coordenadas da cabeca : %d da um bisu na primeira %f\n",
    __self->points_head_go_trough->list.length,
    
    *((GLfloat *)__self->points_head_go_trough->peek(__self->points_head_go_trough)) 
    );        


}
