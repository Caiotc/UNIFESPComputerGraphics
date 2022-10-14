 #ifndef GAME_OBJECT_H
 #define GAME_OBJECT_H
struct GameObject{
    // how can i do it without casting?
    void *GraphicalObject;

    // draw itself,translate,deslocate,and scale?
    void  (*draw_itself)(void);

}

struct GameObject game_object_constructor(void*GraphicalObject);
void game_object_destructor(void);

 #endif