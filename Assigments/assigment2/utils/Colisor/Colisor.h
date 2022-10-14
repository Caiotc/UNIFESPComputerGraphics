#ifndef COLISOR_H
#define COLISOR_H
enum ColisorType {
    Cirlce,
    Rectangle
}
struct Colisor{
    GLfloat colisor_coordinates[2];
    int* colisor_type;
}

struct Colisor colisor_constructor(int* colisor_type,GLfloat * colisor_coordinates);
void colisor_destructor(); 

#endif