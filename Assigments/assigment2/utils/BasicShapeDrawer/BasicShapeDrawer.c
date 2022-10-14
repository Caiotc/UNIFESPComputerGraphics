#include "./BasicShapeDrawer.h"

void draw_quadrilateral_line(GLfloat *a, GLfloat *c,GLfloat *color);
void draw_quadrilateral_filled(GLfloat *a, GLfloat *c,GLfloat *color);
void draw_circle_rope(GLfloat *x, GLfloat *y);
void draw_circle_filled(GLfloat *x, GLfloat *y);

struct BasicShapeDrawer basic_shape_drawer_constructor()
{
    struct BasicShapeDrawer new_basic_shape_drawer;
    new_basic_shape_drawer.draw_quadrilateral_line = draw_quadrilateral_line;
    new_basic_shape_drawer.draw_quadrilateral_filled = draw_quadrilateral_filled;
    // new_basic_shape_drawer.draw_circle_rope = draw_circle_rope;
    // new_basic_shape_drawer.draw_circle_filled = draw_circle_filled;

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

    printf("\n--------- draw quadrilateral wire ---------");
    printf("\n ax: %f ay:%f",((GLfloat *)a)[0],((GLfloat *)a)[1]);
    printf("\n bx: %f by:%f",((GLfloat *)b)[0],((GLfloat *)b)[1]);
    printf("\n cx: %f cy:%f",((GLfloat *)c)[0],((GLfloat *)c)[1]);
    printf("\n dx: %f dy:%f",((GLfloat *)d)[0],((GLfloat *)d)[1]);
    printf("\n--------- draw quadrilateral wire ---------");

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