#ifndef BALL_H
#define BALL_H

#include <GL/glut.h>
#include "../Collisor/Collisor.h"
#include "../BasicShapeDrawer/BasicShapeDrawer.h"


struct Ball{
    GLfloat  center_coordinates[2];
    struct Collisor ball_collisor;
    struct BasicShapeDrawer drawer;
    void (*draw_it_self)(struct Ball * __self,struct BasicShapeDrawer *drawer); 
};
struct Ball ball_constructor(GLfloat * center_coordinates);
void ball_destroyer(struct Ball * ball);

#endif