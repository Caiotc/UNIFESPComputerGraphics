#include <stdio.h>
#include <math.h>

#include "./collections/collections.h"
#include "./utils/uselfullcallbacks.h"

node_coordinates *pointsList = NULL;
int ShapeColor[] = {0, 0, 255};

void drawDot()
{
}

void keyboard_callback(unsigned char key, int x, int y)
{
    printf("key_code =%d  \n", key);
    switch (key)
    {
    case 48:
        /* code */
        ShapeColor[0] = 255;
        ShapeColor[1] = 0;
        ShapeColor[2] = 0;
        break;
    case 49:
        ShapeColor[0] = 0;
        ShapeColor[1] = 255;
        ShapeColor[2] = 0;
        /* code */
        break;
    case 50:
        ShapeColor[0] = 0;
        ShapeColor[1] = 0;
        ShapeColor[2] = 255;
        /* code */
        break;
    case 51:
        ShapeColor[0] = 0;
        ShapeColor[1] = 0;
        ShapeColor[2] = 0;
        /* code */
        break;
    case 52:
        ShapeColor[0] = 255;
        ShapeColor[1] = 0;
        ShapeColor[2] = 98;
        /* code */
        break;
    case 53:
        ShapeColor[0] = 157;
        ShapeColor[1] = 0;
        ShapeColor[2] = 255;
        /* code */
        break;
    case 54:
        ShapeColor[0] = 255;
        ShapeColor[1] = 0;
        ShapeColor[2] = 0;
        /* code */
        break;
    case 55:
        ShapeColor[0] = 0;
        ShapeColor[1] = 247;
        ShapeColor[2] = 255;
        /* code */
        break;
    case 56:
        ShapeColor[0] = 39;
        ShapeColor[1] = 150;
        ShapeColor[2] = 20;
        /* code */
        break;
    case 57:
        ShapeColor[0] = 0;
        ShapeColor[1] = 255;
        ShapeColor[2] = 75;
        /* code */
    default:
        break;
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
            remove_node_of_list_begin(&pointsList);
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

    printf("!@# color %d", ShapeColor[0]);
    glColor3iv(ShapeColor);
    // glColor3f(0.0, 0.4, 0.2);
    glPointSize(10);

    glBegin(GL_POINTS);
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
