#include <stdio.h>
#include <math.h>

#include "./collections/collections.h"
#include "./utils/uselfullcallbacks.h"

node_coordinates *pointsList = NULL;
GLfloat ShapeColor[3] = {0, 0, 0};

void drawDot()
{
}

void keyboard_callback(unsigned char key, int x, int y)
{
    // printf("key_code =%d  \n", key);
    switch (key)
    {
    case 'r':
        remove_node_of_list_end(pointsList);
        printf("\n\n");
        interate_over_list(print_node_values, pointsList);
        break;
    case '1':
        ShapeColor[0] = 0;
        ShapeColor[1] = 0;
        ShapeColor[2] = 1;
        break;
    case '2':
        /* code */
        ShapeColor[0] = 1;
        ShapeColor[1] = 0;
        ShapeColor[2] = 0;
        break;
    case '3':
        ShapeColor[0] = 0;
        ShapeColor[1] = 1;
        ShapeColor[2] = 0;
        /* code */
        break;
    case '4':
        ShapeColor[0] = 0;
        ShapeColor[1] = 0;
        ShapeColor[2] = 0;
        /* code */
        break;
    case '5':
        ShapeColor[0] = 1;
        ShapeColor[1] = 0;
        ShapeColor[2] = 0.5;
        /* code */
        break;
    case '6':
        ShapeColor[0] = 0.5;
        ShapeColor[1] = 0;
        ShapeColor[2] = 1;
        /* code */
        break;
    case '7':
        ShapeColor[0] = 1;
        ShapeColor[1] = 0;
        ShapeColor[2] = 0;
        /* code */
        break;
    case '8':
        ShapeColor[0] = 0;
        ShapeColor[1] = 0.9;
        ShapeColor[2] = 1;
        /* code */
        break;
    case '9':
        ShapeColor[0] = 0.2;
        ShapeColor[1] = 0.7;
        ShapeColor[2] = 0.11;
        /* code */
        break;
    case '0':
        ShapeColor[0] = 0;
        ShapeColor[1] = 1;
        ShapeColor[2] = 0.75;
        /* code */
    default:
        break;
    }
    glutPostRedisplay();
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

    glColor3fv(ShapeColor);
    glPointSize(10);
    glLineWidth(5);

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
