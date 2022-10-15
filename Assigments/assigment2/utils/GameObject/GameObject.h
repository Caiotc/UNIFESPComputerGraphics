 #ifndef GAME_OBJECT_H
 #define GAME_OBJECT_H
 #include <GL/glut.h>
 #include <stdlib.h>
 #include "../Collisor/Collisor.h"

 enum kitty_or_ball{
    Kitty,
    Ball
 };
struct GameObject{
    // how can i do it without casting?
    void *graphical_object;
    GLfloat * coordinates;
    struct Collisor * collisor;
    int type_of_primitive;
    GLfloat size_scale;
    // draw itself,translate,deslocate,and scale?
    void  (*draw_itself)(void);

};

struct GameObject game_object_constructor(void*graphical_object,int type_of_primitive,struct Collisor collisor);
void game_object_destructor(void);

#endif