 #ifndef GAME_OBJECT_H
 #define GAME_OBJECT_H
 #include <stdlib.h>
 #include <string.h>
 #include <GL/glut.h>
 #include <stdbool.h>
#include "../Collisor/Collisor.h"
#include "../MyPrimitives/Cat.h"

 enum kitty_or_ball{
    Kitty,
    Ball
 };
struct GameObject{
    // remember to cas when using it
    struct Cat graphical_object;
    GLfloat * center_coordinates;
    GLfloat size_scale;
    int type_of_primitive;

    bool has_collider;
    struct Collisor collisor;
    
    // draw itself,translate,deslocate,and scale?
    void  (*draw_it_self_go)(struct GameObject *__self);

};

struct GameObject game_object_constructor(GLfloat * game_object_center_coordinates,GLfloat size_scale,int type_of_primitive,bool has_collider);
void game_object_destructor(void);

#endif