#include "./Colisor.h"

struct Colisor colisor_constructor(int colisor_type,GLfloat * colisor_coordinates){
    struct Colisor new_colisor;
    new_colisor.colisor_coordinates = colisor_coordinates;
    if
    switch (colisor_type)
    {
    case Cirlce:
        /* code */
        break;
    case Rectangle:
    break;
    default:
        break;
    }
}
void colisor_handler(struct GameObject * object_to_compare ,struct LinkedList * list_of_game_objects)
{
    int list_length = list_of_game_objects->length;
    int i = 0;

    for (int i = 0; i < list_length; i++)
    {
        struct GameObject* ball = (struct GameObject*)list_of_game_objects->retrieve(i,list_of_game_object);
        bool did_it_collide = verify_colision(object_to_compare,ball);
        did_it_collide? list_of_game_objects->remove(i,list_of_game_objects):return;
    }

}

bool verify_colision(struct GameObject *a,struct GameObject *b){
    bool collision_in_x = 
    (a->colisor.coordinates[0] + a->colisor.colisor_size >= b->colisor.coordinates[0] ) &&    
    ( b->colisor.coordinates[0] + b->colisor.colisor_size >= a->colisor.coordinates[0]);
        
    bool collision_in_y = 
    (a->colisor.coordinates[1] + a->colisor.colisor_size >= b->colisor.coordinates[1] )&& 
    (b->colisor.coordinates[1] + b->colisor.colisor_size >= a->colisor.coordinates[1]);
    return collsion_in_x & collision _in_y;
}