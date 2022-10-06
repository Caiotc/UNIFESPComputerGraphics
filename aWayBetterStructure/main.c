#include <stdio.h>
#include <math.h>

#include "./collections/collections.h"
#include "./utils/uselfullcallbacks.h"

node_coordinates *pointsList;

void init()
{
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0.0, 200.0, 0, 200.0);

    ///
    pointsList = init_node_coordinates_list(50.0f, 100.0f);
}

void MouseInt(int botao, int estado, int x, int y)
{
    switch (botao)
    {
    case GLUT_LEFT_BUTTON:
        if (estado == GLUT_DOWN)
            add_node_to_list(pointsList, 100.0f, 200.0f);
        ;
        break;
    case GLUT_RIGHT_BUTTON:
        if (estado == GLUT_DOWN)
            glShadeModel(GL_FLAT);
        break;
    default:
        break;
    }
    glutPostRedisplay();
}

void draw()
{

    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(0.0, 0.4, 0.2);
    glBegin(GL_LINES);
    interate_over_list(call_vertex_2d_from_node, pointsList);
    glEnd();

    glFlush();
}

int main(int argc, char *argv[])
{

    glutInit(&argc, argv);

    glutCreateWindow("primitives");

    glutDisplayFunc(draw);

    init();

    glutMouseFunc(MouseInt);
    glutMainLoop();

    /* code */
    return 0;
}
