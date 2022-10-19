#ifndef CAT_H
#define CAT_H
#include <GL/freeglut.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../../Lists/Queue.h"
#include "../BasicShapeDrawer/BasicShapeDrawer.h"
#include "../Collisor/Collisor.h"
#include "../Transform/Transform.h"
#include "./Ball.h"




struct Cat
{
    GLfloat * cat_center_coordinates;
    GLfloat cat_size;
    struct Transform cat_transformer;
    GLfloat *cat_head_coordinates;
    GLfloat angle_between_two_vectors;

    struct Queue * points_untill_next_Ball;
    struct Queue * ball_queue;

    struct Queue * points_head_go_trough;
    
    bool cat_is_aligned;


    void (*draw_itself)(struct Cat * __self,struct BasicShapeDrawer* drawer, bool *should_transform,GLfloat * destiny_point);
    void (*pursuit_ball)(struct Cat * __self);
    void (*cat_do_flip)(void);
    void (*cat_resize)(void);
};

struct Cat cat_constructor(
GLfloat * cat_center_coordinates,
GLfloat cat_size,
struct Queue * ball_queue,  
struct Queue * points_untill_next_Ball,
struct Queue * points_head_go_trough);
void cat_destructor(struct Cat *cat);

#endif