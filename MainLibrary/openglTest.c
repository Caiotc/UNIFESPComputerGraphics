#include "./Lists/LinkedList.h"
#include <GL/glut.h>
#include <string.h>

void reshape(int w, int h)
{
    if (w >= h)
        glViewport(0, 0, (GLsizei)h, (GLsizei)h);
    else
        glViewport(0, 0, (GLsizei)w, (GLsizei)w);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 1.0, 0.0, 1.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void display()
{
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(0.2f, 0.2f, 0.2f);

    char *texto = "esse e um texto";
    glRasterPos2f(0, 0);
    for (int i = 0; i < strlen(texto); i++)
    {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10, texto[i]);
    }

    glFlush();
}
int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(640, 480);
    glutCreateWindow("HUD library");

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutMainLoop();
    /* code */
    return 0;
}
