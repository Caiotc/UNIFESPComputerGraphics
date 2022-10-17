#include "./Collisor.h"

struct Collisor collisor_constructor(int collisor_type,GLfloat * collisor_coordinates){
    struct Collisor new_collisor;
    new_collisor.collisor_coordinates = collisor_coordinates;
    switch (collisor_type)
    {
    case Circle:
        /* code */
        break;
    case Rectangle:
    break;
    default:
        break;
    }
}
