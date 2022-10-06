#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <GL/glut.h>

typedef struct node
{
    GLfloat x, y;
    struct node_coordinates *next;
    /* data */
} node_coordinates;

node_coordinates *init_node_coordinates_list(float x, float y)
{

    node_coordinates *head = (node_coordinates *)malloc(sizeof(node_coordinates));
    head->x = x;
    head->y = y;
    head->next = NULL;

    return head;
}

void add_node_to_list(node_coordinates *head, float x, float y)
{
    node_coordinates *current = head;
    node_coordinates *newNode = (node_coordinates *)malloc(sizeof(node_coordinates));

    while (current->next != NULL)
    {
        current = (node_coordinates *)current->next;
    }

    newNode->x = x;
    newNode->y = y;
    newNode->next = NULL;

    current->next = (struct node_coordinates *)newNode;
}

void interate_over_list(void (*callback)(), node_coordinates *head)
{
    node_coordinates *current = head;

    while (current != NULL)
    {
        callback(current);
        current = (node_coordinates *)current->next;
        /* code */
    }
}

void call_vertex_2d_from_node(node_coordinates *node)
{
    glVertex2f(node->x, node->y);
}

void init()
{
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0.0, 200.0, 0, 200.0);
}

void draw()
{
    node_coordinates *pointsList = init_node_coordinates_list(50.0f, 100.0f);
    add_node_to_list(pointsList, 75.0f, 150.0f);
    // add_node_to_list(pointsList, 100.0f, 200.0f);

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
    glutMainLoop();

    /* code */
    return 0;
}
