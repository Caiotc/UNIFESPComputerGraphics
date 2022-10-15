#include <GL/glut.h>

#include "./Lists/LinkedList.h"
#include "./Lists/Queue.h"
#include "./utils/MyPrimitives/Cat.h"
#include "./utils/GameObject/GameObject.h"
#include "./utils/Collisor/Collisor.h"


bool verify_colision(struct GameObject *a,struct GameObject *b);
void collisor_handler(struct GameObject * object_to_compare ,struct LinkedList * list_of_game_objects);

struct Cat cat; 
 GLfloat a[2] = {0.3f,0.4f};
 GLfloat b[2] = {0.4f,0.7f};


void collisor_handler(struct GameObject * object_to_compare ,struct LinkedList * list_of_game_objects)
{
    int list_length = list_of_game_objects->length;
    int i = 0;

    for (int i = 0; i < list_length; i++)
    {
        struct GameObject* ball = (struct GameObject*)list_of_game_objects->retrieve(i,list_of_game_objects);
        bool did_it_collide = verify_colision(object_to_compare,ball);
        if(did_it_collide)
            list_of_game_objects->remove(i,list_of_game_objects);
    }

}

bool verify_colision(struct GameObject *a,struct GameObject *b){

    // struct Collisor * a_collisor = &a->collisor;
    //     struct Collisor * b_collisor = &b->collisor;

    // bool collision_in_x = 
    // (a_collisor->collisor_coordinates[0] + a_collisor->collisor_size >= b_collisor->collisor_coordinates[0] ) &&    
    // ( b_collisor->collisor_coordinates[0] + b_collisor->collisor_size >= a_collisor->collisor_coordinates[0]);
        
    // bool collision_in_y = 
    // (a_collisor->collisor_coordinates[1] + a_collisor->collisor_size >= b_collisor->collisor_coordinates[1] )&& 
    // (b_collisor->collisor_coordinates[1] + b_collisor->collisor_size >= a_collisor->collisor_coordinates[1]);
    // return collision_in_x & collision_in_y;
}

void reshape(int w, int h)
{
    if (w >= h)
        glViewport(0, 0, (GLsizei)h, (GLsizei)h);
    else
        glViewport(0, 0, (GLsizei)w, (GLsizei)w);
    // load projection matrix
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 1.0, 0.0, 1.0);
    // load  modelview matrix
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}
void display()
{
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT);
    printf("\n!@# it reaches the draw itself");
    cat.draw_itself(&cat);

    glFlush();
}
int main(int argc, char *argv[])
{
    printf("\n!@# reaches here wo many times it reaches here");
    cat = cat_constructor(0.5f, 0.5f,0.5f);
    glutInit(&argc, argv);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(640, 480);
    glutCreateWindow("ballkity game");

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutMainLoop();

    /* code */
    return 0;
}
