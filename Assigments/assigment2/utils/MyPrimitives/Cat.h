#ifndef CAT_H
#define CAT_H
#include <GL/freeglut.h>
#include <stdlib.h>
#include "../../Lists/Queue.h"
#include "../BasicShapeDrawer/BasicShapeDrawer.h"
#include "../Collisor/Collisor.h"




struct Cat
{
    GLfloat * cat_center_coordinates;
    GLfloat cat_size;



    void (*draw_itself)(struct Cat * __self,struct BasicShapeDrawer *drawer);
    void (*pursuit_ball)(GLfloat ball_x, GLfloat ball_y);
    void (*cat_do_flip)(void);
    void (*cat_resize)(void);
};

struct Cat cat_constructor(GLfloat * cat_center_coordinates,GLfloat cat_size);
void cat_destructor(struct Cat *cat);

#endif