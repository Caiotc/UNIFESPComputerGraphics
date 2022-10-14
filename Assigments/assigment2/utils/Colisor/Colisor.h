#ifndef COLISOR_H
#define COLISOR_H
#include <GL/glut.h>
#include "../../Lists/LinkedList.h"
#include "../GameObject/GameObject.h"
#include <stdbool.h>
enum ColisorType {
    Cirlce,
    Rectangle
};
struct Colisor{
    GLfloat * colisor_coordinates;
    int colisor_type;
    GLfloat colisor_size;
};

struct Colisor colisor_constructor(int colisor_type,GLfloat * colisor_coordinates);
void colisor_destructor(); 

void colisor_handler (struct LinkedList * list_of_game_objects);

#endif