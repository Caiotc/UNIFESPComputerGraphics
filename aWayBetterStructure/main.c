#include <stdio.h>
#include <math.h>

#include "./collections/collections.h"
#include "./utils/uselfullcallbacks.h"

node_coordinates *pointsList = NULL;

void keyboard_callback(unsigned char key, int x, int y)
{
    if (key == 'f')
    {
        glutFullScreen();
    }
}

void mouse(int button, int state, int x, int y)
{
    switch (button)
    {
    case GLUT_LEFT_BUTTON:
        if (state == GLUT_DOWN)
        {
            add_node_to_list_end(&pointsList, x, y);
            printf("\n");
            interate_over_list(print_node_values, pointsList);
        }
        break;
    default:
        break;
    }
    glutPostRedisplay();
}

void display()
{
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT);

    glMatrixMode(GL_PROJECTION);

    ///////////////////
    // research
    // this basicly does the scale transformation
    // through the view port and window
    glLoadIdentity();
    double w = glutGet(GLUT_WINDOW_WIDTH);
    double h = glutGet(GLUT_WINDOW_HEIGHT);
    glOrtho(0, w, h, 0, -1, 1);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    ///////////////////////

    glColor3f(0.0, 0.4, 0.2);

    glBegin(GL_LINES);
    interate_over_list(call_vertex_2d_from_node, pointsList);
    glEnd();

    glutSwapBuffers();
}

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(640, 480);
    glutCreateWindow("primitives");

    glutDisplayFunc(display);

    glutKeyboardFunc(keyboard_callback);
    glutMouseFunc(mouse);
    glutMainLoop();

    /* code */
    return 0;
}
