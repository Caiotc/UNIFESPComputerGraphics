#ifndef CAT_H
#define CAT_H
#include <GL/freeglut.h>
#include <stdlib.h>
#include "../../Lists/LinkedList.h"
#include "../BasicShapeDrawer/BasicShapeDrawer.h"




struct Cat
{
    GLfloat coordinates[2];
    GLfloat cat_size;
    GLfloat cat_center;

    struct LinkedList ball_list;
    struct BasicShapeDrawer drawer;

    void (*draw_itself)(struct Cat * __self);
    void (*pursuit_ball)(GLfloat ball_x, GLfloat ball_y);
    void (*cat_do_flip)(void);
    void (*cat_resize)(void);
};

struct Cat cat_constructor(GLfloat x, GLfloat y);
void cat_destructor(struct Cat *cat);

#endif