#include "uselfullcallbacks.h"
#include <stdio.h>
#include <math.h>
#define PI 3.141592654

void call_vertex_2d_from_node(node_coordinates *node)
{
    // test

    glVertex2f(node->x, node->y);
}

void print_node_values(node_coordinates *node)
{

    printf("\n posX: %f posY:%f drawMode%d strokeSize:%d nextMemAddress:%p", node->x, node->y, node->modeToDraw, node->strokeSize, node->next);
}
void draw_circle(node_coordinates *a, GLfloat radius)
{
    node_coordinates *radiusPoint = (node_coordinates *)a->next;
    printf("\n\n!@#/////////////////////////////////////////  ");
    printf("\n!@# desenhou circulo");
    printf("\n!@# ponto do centro %f, %f\n e essa e a coordenada do ponto que define o raio %f, %f\n e esse e o calculo de raio %f", a->x, a->y, radiusPoint->x, radiusPoint->y, radius);
    printf("\n!@#/////////////////////////////////////////  ");

    float i = 0;
    double angle;
    glBegin(GL_LINE_LOOP);
    for (i = 0; i <= 360; i++)
    {
        angle = PI * i / 180;
        glVertex2d(a->x + radius * cos(angle), a->y + radius * sin(angle));
    }
    glEnd();
}

float calculate_distance_between_points(node_coordinates *a, node_coordinates *b)
{
    float x = pow(a->x - b->x, 2);
    float y = pow(a->y - b->y, 2);
    printf("\n\n////////////////calculando a distancia dos pontos///////////////////");
    printf("\nx**2 => %f \n y**2=>%f \n x**2+y**2 =>%f \n distancia de a-b =>  %f ", x, y, x + y, sqrt(x + y));
    printf("\n\n///////////////////////////////////");

    return sqrt(x + y);
}
void draw_on_two_points(node_coordinates *a, node_coordinates *b)
{

    glColor3fv(DEFAULT_COLORS[a->colorSelector]);
    glPointSize(a->strokeSize);
    glLineWidth(a->strokeSize);

    if (a->modeToDraw != b->modeToDraw)
    {
        printf("\n!@# ai, os dois pontos tem que ser elecionados no mesmo modo\n");
        return;
    }
    if (a->modeToDraw)
    {
        draw_circle(a, calculate_distance_between_points(a, b));
    }
    else
    {
        glBegin(GL_LINES);
        glVertex2f(a->x, a->y);
        glVertex2f(b->x, b->y);
        glEnd();
    }
}
