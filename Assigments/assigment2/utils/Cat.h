#ifndef CAT_H
#define CAT_H
#include <GL/freeglut.h>
#include "../Lists/LinkedList.h"

struct Cat
{
    GLfloat cat_initial_x, cat_initial_y;
    GLfloat cat_size;

    struct LinkedList ball_list;
    
    void (*draw_itself)(GLfloat actual_x,GLfloat actual_y,struct Cat * __self);
    void (*pursuit_ball)(GLfloat ball_x, GLfloat ball_y);
    void (*cat_do_flip)(void);
    void (*cat_resize)(void);
};

struct Cat cat_constructor(GLfloat x, GLfloat y);
void cat_destructor(struct Cat *cat);

#endif