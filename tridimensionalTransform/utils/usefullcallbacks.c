#include "uselfullcallbacks.h"
#include "../collections/collections.h"
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
    if (node == NULL)
    {
        printf("!@# isso aqui e vazio mano");
        return;
    }
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
    return sqrt(x + y);
}

void draw_rectangle_by_diagonal(node_coordinates *a, node_coordinates *c)
{
    node_coordinates *b = init_node_coordinates_list(a->x + (c->x - a->x), a->y, a->modeToDraw, a->strokeSize, a->colorSelector);
    node_coordinates *d = init_node_coordinates_list(c->x, a->y + (c->y - a->y), c->modeToDraw, c->strokeSize, c->colorSelector);

    printf("\n!@# pontos do retangulo");
    print_node_values(a);
    print_node_values(b);
    print_node_values(c);
    print_node_values(d);

    glBegin(GL_QUAD_STRIP);
    glVertex2f(a->x, a->y);
    glVertex2f(b->x, b->y);

    glVertex2f(c->x, c->y);
    glVertex2f(d->x, d->y);

    glEnd();

    glFlush();
    free(b);
    free(d);
}

void draw_on_two_points(node_coordinates *a, node_coordinates *b)
{
    glColor3fv(DEFAULT_COLORS[a->colorSelector]);
    glPointSize(10);

    glLineWidth(a->strokeSize);

    if (a->modeToDraw != b->modeToDraw)
    {
        printf("\n!@# ai, os dois pontos tem que ser elecionados no mesmo modo\n");
        return;
    }

    if (a->modeToDraw == 1)
    {
        draw_circle(a, calculate_distance_between_points(a, b));
    }
    else if (a->modeToDraw == 2)
    {
        glRectf(a->x, a->y, b->x, b->y);
    }
    else if (a->modeToDraw == 0)
    {
        glBegin(GL_LINES);
        glVertex2f(a->x, a->y);
        glVertex2f(b->x, b->y);
        glEnd();
    }
}
