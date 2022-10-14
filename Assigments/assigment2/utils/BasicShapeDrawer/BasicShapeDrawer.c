#include "./BasicShapeDrawer.h"
#define PI 3.141592654


void draw_quadrilateral_line(GLfloat *a, GLfloat *c,GLfloat *color);
void draw_quadrilateral_filled(GLfloat *a, GLfloat *c,GLfloat *color);
void draw_circle_rope(GLfloat *center, GLfloat radius,GLfloat *color);
void draw_circle_filled(GLfloat *center, GLfloat radius,GLfloat *color);

struct BasicShapeDrawer basic_shape_drawer_constructor()
{
    struct BasicShapeDrawer new_basic_shape_drawer;
    new_basic_shape_drawer.draw_quadrilateral_line = draw_quadrilateral_line;
    new_basic_shape_drawer.draw_quadrilateral_filled = draw_quadrilateral_filled;
    new_basic_shape_drawer.draw_circle_rope = draw_circle_rope;
    new_basic_shape_drawer.draw_circle_filled = draw_circle_filled;

    return new_basic_shape_drawer;
}

void basic_shape_drawer_destroyer(struct BasicShapeDrawer *basic_shape_drawer)
{
    free(basic_shape_drawer);
}

void draw_quadrilateral_line(GLfloat *a, GLfloat *c, GLfloat *color)
{
    GLfloat b[2] = {((GLfloat *)c)[0], ((GLfloat *)a)[1]};
    GLfloat d[2] = {((GLfloat *)a)[0], ((GLfloat *)c)[1]};

    glColor3fv(color);
    glBegin(GL_LINES);
        glVertex2f(a[0], a[1]);
        glVertex2f(b[0], b[1]);
    
        glVertex2f(b[0], b[1]);
        glVertex2f(c[0], c[1]);

        glVertex2f(c[0], c[1]);
        glVertex2f(d[0], d[1]);

        glVertex2f(d[0], d[1]);
        glVertex2f(a[0], a[1]);

    glEnd();
}

void draw_quadrilateral_filled(GLfloat *a, GLfloat *c,GLfloat *color)
{
    GLfloat b[2] = {((GLfloat *)c)[0], ((GLfloat *)a)[1]};
    GLfloat d[2] = {((GLfloat *)a)[0], ((GLfloat *)c)[1]};
    glColor3fv(color);
    glBegin(GL_QUADS);
        glVertex2f(a[0], a[1]);
        glVertex2f(b[0], b[1]);
        glVertex2f(c[0], c[1]);
        glVertex2f(d[0], d[1]);
    glEnd();

}

void draw_circle_rope(GLfloat *center,GLfloat radius,GLfloat *color){
    int i =0;
    float angle;

    glColor3fv(color);
    glBegin(GL_LINE_LOOP);
    for(i = 0; i<= 360;i++){
        angle = PI * i/ 180.0f;
        glVertex2f(center[0] + radius * cos(angle),center[0] + radius * sin(angle));
    }
    glEnd();
}

void draw_circle_filled(GLfloat *center,GLfloat radius,GLfloat *color)
{
    int i =0;
    float angle;

    glColor3fv(color);
    glBegin(GL_TRIANGLE_FAN);
    for(i = 0; i<= 360;i++){
        angle = PI * i/ 180.0f;
        glVertex2f(center[0] + radius * cos(angle),center[0] + radius * sin(angle));
    }
    glEnd();

}
