#include <GL/glut.h>

#include "./Lists/LinkedList.h"
#include "./Lists/Queue.h"
#include "./Lists/Queue.h"
#include "./utils/MyPrimitives/Cat.h"
#include "./utils/Collisor/Collisor.h"
#include "./utils/MyPrimitives/Ball.h"
#include "./utils/BasicShapeDrawer/BasicShapeDrawer.h"

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480




struct Cat cat;
struct Queue ball_queue;
struct BasicShapeDrawer drawer;

 GLfloat a[2] = {0.3f,0.4f};
 GLfloat b[2] = {0.4f,0.7f};

void iterate_over_ball_queue_and_draw_it(struct Queue * ball_queue){
    printf("\n!@# chgou no iterador");
    int list_size = ball_queue->list.length;
    
    struct Ball *cursor ; 
    int i;
    //draw every ball on list
    if(list_size > 0){
        for(i =0;i<list_size;i++){
            cursor =(struct Ball *) ball_queue->list.retrieve(i,&ball_queue->list) ;        
            printf("\n!@# teste da merda da bola x:%f y:%f",cursor->center_coordinates[0],cursor->center_coordinates[1]);
            cursor->draw_it_self(cursor,&drawer);
        }
    }
}

// void collisor_handler(struct GameObject * object_to_compare ,struct LinkedList * list_of_game_objects)
// {
//     int list_length = list_of_game_objects->length;
//     int i = 0;

//     for (int i = 0; i < list_length; i++)
//     {
//         struct GameObject* ball = (struct GameObject*)list_of_game_objects->retrieve(i,list_of_game_objects);
//         bool did_it_collide = verify_colision(object_to_compare,ball);
//         if(did_it_collide)
//             list_of_game_objects->remove(i,list_of_game_objects);
//     }

// }

// bool verify_colision(struct GameObject *a,struct GameObject *b){

//     // struct Collisor * a_collisor = &a->collisor;
//     //     struct Collisor * b_collisor = &b->collisor;

//     // bool collision_in_x = 
//     // (a_collisor->collisor_coordinates[0] + a_collisor->collisor_size >= b_collisor->collisor_coordinates[0] ) &&    
//     // ( b_collisor->collisor_coordinates[0] + b_collisor->collisor_size >= a_collisor->collisor_coordinates[0]);
        
//     // bool collision_in_y = 
//     // (a_collisor->collisor_coordinates[1] + a_collisor->collisor_size >= b_collisor->collisor_coordinates[1] )&& 
//     // (b_collisor->collisor_coordinates[1] + b_collisor->collisor_size >= a_collisor->collisor_coordinates[1]);
//     // return collision_in_x & collision_in_y;
// }


void display()
{
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();    
    double w = glutGet(GLUT_WINDOW_WIDTH);
    double h = glutGet(GLUT_WINDOW_HEIGHT);
    glOrtho(0, w, h, 0, -1, 1);
    
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();


    iterate_over_ball_queue_and_draw_it(&ball_queue);
    cat.draw_itself(&cat,&drawer);    

    glutSwapBuffers();
}


void mouse(int button, int state, int x, int y)
{
    double w = glutGet(GLUT_WINDOW_WIDTH);
    double h = glutGet(GLUT_WINDOW_HEIGHT);
    struct Ball new_ball;
    GLfloat  ball_coordinates[2]; 
    switch (button)
    {
    case GLUT_LEFT_BUTTON:
        if (state == GLUT_DOWN)
        {   
            printf("\n!@# printando as corrdenadas da tels w%f h%f  e x:%f y:%f  ",(GLfloat)w,(GLfloat)h,(GLfloat)x,(GLfloat)y);
            ball_coordinates[0] =(GLfloat)x;
            ball_coordinates[1] =(GLfloat)y  ;
            new_ball = ball_constructor(ball_coordinates);
            printf("\n!@# a porra da boola");
            ball_queue.push(&ball_queue,&new_ball,sizeof(new_ball));
        }
        break;
    default:
        break;
    }
    glutPostRedisplay();
}

int main(int argc, char *argv[])
{
    
    GLfloat cat_center_position[2] = {320.0f,240.0f};
    cat = cat_constructor(cat_center_position,100.4f);
    ball_queue = queue_constructor();
    drawer = basic_shape_drawer_constructor();

    glutInit(&argc, argv);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(SCREEN_WIDTH, SCREEN_HEIGHT);
    glutCreateWindow("ballkity game");

    glutDisplayFunc(display);
    //glutReshapeFunc(reshape);
    glutMouseFunc(mouse);
    glutMainLoop();

    /* code */
    return 0;
}
