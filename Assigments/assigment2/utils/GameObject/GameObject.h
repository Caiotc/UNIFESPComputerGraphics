 #ifndef GAME_OBJECT_H
 #define GAME_OBJECT_H
#include <GL/glut.h>
 #include "../Colisor/Colisor.h"
struct GameObject{
    // how can i do it without casting?
    void *GraphicalObject;
    GLfloat * coordinates;
    struct Colisor colisor;
    // draw itself,translate,deslocate,and scale?
    void  (*draw_itself)(void);

};

struct GameObject game_object_constructor(void*GraphicalObject,Colisor colisor);
void game_object_destructor(void);

 #endif