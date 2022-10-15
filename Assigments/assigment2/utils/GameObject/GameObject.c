#include "./GameObject.h"
#include <string.h>

struct Collisor generate_collisor_for_primitive(struct GameObject * game_object);

struct GameObject game_object_constructor(void*graphical_object,int type_of_primitive,struct Collisor collisor)
{
    GLfloat origin[2] = {0.0f,0.0f};
    struct GameObject new_game_object;
    
    new_game_object.graphical_object = malloc(sizeof(1));
    memcpy(new_game_object.graphical_object,graphical_object,sizeof(1));
    new_game_object.coordinates = origin;
    new_game_object.type_of_primitive = type_of_primitive;

    return new_game_object;

}


struct Collisor generate_collisor_for_primitive(struct GameObject * game_object){

}
