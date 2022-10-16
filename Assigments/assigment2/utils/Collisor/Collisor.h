#ifndef COLISOR_H
#define COLISOR_H
#include <GL/glut.h>
#include "../../Lists/LinkedList.h"
#include <stdbool.h>
enum CollisorType {
    Circle,
    Rectangle
};
struct Collisor{
    GLfloat * collisor_coordinates;
    int collisor_type;
    GLfloat collisor_size;
};

struct Collisor collisor_constructor(int collisor_type,GLfloat * collisor_coordinates);
void collisor_destructor(); 

#endif