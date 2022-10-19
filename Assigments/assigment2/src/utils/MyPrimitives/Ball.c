#include "./Ball.h"

//private
void draw_it_self(struct Ball * __self,struct BasicShapeDrawer *drawer);

struct Ball ball_constructor(GLfloat * center_coordinates){
    struct Ball new_ball;
    new_ball.center_coordinates[0] = center_coordinates[0];
    new_ball.center_coordinates[1] = center_coordinates[1];
    new_ball.drawer = basic_shape_drawer_constructor();
    //new_ball.ball_collisor = collisor_constructor(Circle,center_coordinates);

    new_ball.draw_it_self = draw_it_self;
    return new_ball;
}

void draw_it_self(struct Ball * __self,struct BasicShapeDrawer *drawer){
    GLfloat size = 35.0f;
    GLfloat blue[3] = {0.0f,0.0f,1.0f};
    //GLfloat teste_coordinates[2] = {0.7f,0.7f};

    drawer->draw_circle_filled(__self->center_coordinates,size/2,blue);
}