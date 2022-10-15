#include "./BasicShapeDrawer.h"
#define PI 3.141592654
/*Methods*/
void draw_point(GLfloat *a,GLfloat  *color);
void draw_line(GLfloat *a,GLfloat *b,GLfloat  *color);
void draw_quadrilateral_line(GLfloat *a, GLfloat *c,GLfloat  *color);
void draw_quadrilateral_filled(GLfloat *a, GLfloat *c,GLfloat  *color);
void draw_circle_rope(GLfloat *center, GLfloat radius,GLfloat  *color);
void draw_circle_filled(GLfloat *center, GLfloat radius,GLfloat  *color);


GLfloat calculate_distance_between_two_given_points(GLfloat *a,GLfloat *b);


struct BasicShapeDrawer basic_shape_drawer_constructor()
{

    printf("\n!@# it entered the shape_drawer constructor");
    struct BasicShapeDrawer new_basic_shape_drawer;

    new_basic_shape_drawer.draw_point = draw_point;
    new_basic_shape_drawer.draw_line = draw_line;    
    new_basic_shape_drawer.draw_quadrilateral_line = draw_quadrilateral_line;     
    new_basic_shape_drawer.draw_quadrilateral_filled = draw_quadrilateral_filled;
    printf("\n!@# it does create the quadrilateral");    
    new_basic_shape_drawer.draw_circle_rope = draw_circle_rope;
    new_basic_shape_drawer.draw_circle_filled = draw_circle_filled;
    printf("\n!@# it does pass the references");    

    return new_basic_shape_drawer;
}

void basic_shape_drawer_destroyer(struct BasicShapeDrawer *basic_shape_drawer)
{
    free(basic_shape_drawer);
}




void draw_point(GLfloat *a,GLfloat  *color){
    printf("\n!@# chegou aqui no desenho do ponto ");
    glPointSize(5.0f);
    glColor3fv(color);
    glBegin(GL_POINTS);
        glVertex2fv(a);
    glEnd();
}
void draw_line(GLfloat *a,GLfloat *b,GLfloat  *color){
    printf("\n!@# chegou aqui ");
    glLineWidth(3.0);
    glColor3fv(color);
    glBegin(GL_LINES);
        glVertex2fv(a);
        glVertex2fv(b);
    glEnd();
}

void draw_quadrilateral_line(GLfloat *a, GLfloat *c, GLfloat  *color)
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

void draw_quadrilateral_filled(GLfloat *a, GLfloat *c,GLfloat  *color)
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

void draw_circle_rope(GLfloat *center,GLfloat radius,GLfloat  *color){
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

void draw_circle_filled(GLfloat *center,GLfloat radius,GLfloat  *color)
{
    int i =0;
    float angle;

    glColor3fv(color);
    glBegin(GL_TRIANGLE_FAN);
    for(i = 0; i<= 360;i++){
        angle = PI * i/ 180.0f;
        glVertex2f(center[0] + radius * cos(angle),center[1] + radius * sin(angle));
    }
    glEnd();

}

GLfloat calculate_distance_between_two_given_points(GLfloat *a,GLfloat *b)
{
    
    GLfloat squared_sum = pow(a[0] - b[0],2) + pow(a[1] - b[1],2);
    GLfloat distance_between_points = sqrt(squared_sum);

    return distance_between_points;
}