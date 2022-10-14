#include <stdio.h>
#include <math.h>
#include "./collections/collections.h"
#include "./utils/uselfullcallbacks.h"

GLint rings = 40;
GLint nsides = 50;
GLint slices = 20;

GLfloat xRota = 0.2;
GLfloat yRota = 0.2;
GLfloat zRota = 0.2;

void display()
{
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    ///////////////////
    // research
    // this basicly does the scale transformation
    // through the view port and window
    // double w = glutGet(GLUT_WINDOW_WIDTH);
    // double h = glutGet(GLUT_WINDOW_HEIGHT);
    // glOrtho(0, w, h, 0, -1, 1);

    glPushMatrix();
    glTranslatef(-0.5, -0.5, 0.0);
    glColor3f(0.0, 0.0, 0.0);
    glRotatef(xRota, 1.0, 0.0, 0.0);
    glRotatef(yRota, 0.0, 1.0, 0.0);
    glRotatef(zRota, 0.0, 0.0, 1.0);
    glScalef(1.0, 1.0, 1.0);
    glutSolidTorus(0.25, 0.3, nsides, rings);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.9, 0.9, 0.0);
    glColor3f(0.0, 0.82, 0.27);
    glRotatef(0.0, 1.0, 0.0, 0.0);
    glRotatef(0.0, 0.0, 1.0, 0.0);
    glRotatef(1.0, 0.0, 0.0, 0.0);
    glScalef(1.0, 1.0, 1.0);
    glutSolidTorus(0.25, 0.3, nsides, rings);
    glPopMatrix();

    glFlush();
}

void keyboard_callback(unsigned char key, int x, int y)
{
    switch (key)
    {
    case 'x':
        xRota = xRota + 0.5;
        break;
    case 'y':
        yRota = yRota + 0.5;
        break;
    case 'z':
        zRota = zRota + 0.5;
        break;
    default:
        break;
    }
    glutPostRedisplay();
}

void mouse()
{
}
int main(int argc, char *argv[])
{

    glutInit(&argc, argv);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(640, 480);
    glutCreateWindow("primitives");

    glutDisplayFunc(display);

    glutKeyboardFunc(keyboard_callback);
    // glutMouseFunc(mouse);
    glutMainLoop();
    /* code */
    return 0;
}
