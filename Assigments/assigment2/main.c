#include <GL/glut.h>

#include "./Lists/LinkedList.h"
#include "./Lists/Queue.h"
#include "./utils/Cat.h"
#include "./utils/BasicShapeDrawer/BasicShapeDrawer.h"

 struct Cat cat; 
 struct BasicShapeDrawer drawer;
 GLfloat a[2] = {0.3f,0.4f};
 GLfloat b[2] = {0.4f,0.7f};
 GLfloat color[3] = {0.5f,0.2f,0.4f};

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
    
    drawer.draw_quadrilateral_filled(a,b,color);
    glFlush();
}
int main(int argc, char *argv[])
{
    cat = cat_constructor(0.0, 0.0);
    drawer= basic_shape_drawer_constructor();
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
