#include <GL/glut.h>

#include "./Lists/LinkedList.h"
#include "./Lists/Queue.h"
#include "./utils/MyPrimitives/Cat.h"

struct Cat cat; 
 GLfloat a[2] = {0.3f,0.4f};
 GLfloat b[2] = {0.4f,0.7f};

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
    cat.draw_itself(&cat);
    glFlush();
}
int main(int argc, char *argv[])
{
    printf("\n!@# reaches here wo many times it reaches here");
    cat = cat_constructor(0.5f, 0.5f);
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
