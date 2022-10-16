#include "./GameObject.h"

struct Collisor generate_collisor_for_primitive(struct GameObject * game_object);
void  draw_it_self_go(struct GameObject *__self);
struct GameObject game_object_constructor(
    GLfloat * game_object_center_coordinates,
    GLfloat size_scale,
    int type_of_primitive,
    bool has_collider
    )
{
    
    struct GameObject new_game_object;
    int type_of_collider;
    struct Cat cat_reference;
    struct Cat * verify;
    
    //create the primitive and set it to the graphical_object
                            
    //new_game_object.graphical_object = cat_constructor(game_object_center_coordinates,size_scale);                    
    new_game_object.center_coordinates = game_object_center_coordinates;
    new_game_object.type_of_primitive = type_of_primitive;
    new_game_object.draw_it_self_go = draw_it_self_go;
    new_game_object.size_scale =size_scale;

  



    return new_game_object;

}

void draw_it_self_go(struct GameObject *__self){

    struct Cat* cat_reference;
    struct Ball* ball_reference;

    switch (__self->type_of_primitive)
    {
    case Kitty:
       __self->draw_it_self_go(__self);
        break;
    
    default:
        break;
    }
}
