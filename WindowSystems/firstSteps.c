/**
 * This shit assa program only display a black window and a green line
 *
 * **/

// #include <windows.h>
// #include <GL/gl.h>
// #include <GL/glu.h>

/*
 since the glut(graphic library toolkit)
includes all that shit above wer aro only
gonna include GL/glut.h
**/
#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

GLenum ErrorCheck()
{
    GLenum code;
    const GLubyte *string;
    code = glGetError();

    if (code != GL_NO_ERROR)
    {
        string = gluErrorString(code);
        fprintf(stderr, "OpenGL error: %s\n", string);
    }
}

void init()
{
    // this sets a windows background color RGB,ALPHA
    glClearColor(1.0, 1.0, 1.0, 0.0);

    glMatrixMode(GL_PROJECTION);
    // Set projection parameters.
    // defines the coordinate reference  frame within
    // the display window
    gluOrtho2D(0.0, 200.0, 0.0, 150.0);
}
void lineSegment()
{
    glClear(GL_COLOR_BUFFER_BIT); // Clear Display window

    glColor3f(0.0, 0.4, 0.2); // set figure color => green
    glBegin(GL_LINES);
    glVertex2i(180, 15);
    glVertex2i(10, 145);
    glEnd();

    // this forces the execution of openGl functions
    glFlush(); // process opengl quick as possible
}

int main(int argc, char *argv[])
{
    // glutInit also process any command line arguments
    glutInit(&argc, argv);
    // we can set other options for the display window
    // such as buffering and a choice of color modes
    //  SINGLE MODE AND RGB ARE THE DEFAULT VALUE
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    /*
     there are two functions that can be used
     to set the window position and size
    here i set them with their default value
    - same shit if we just ignore both of them
    */
    glutInitWindowPosition(50, 100);
    glutInitWindowSize(400, 600);
    //////////////////////////////

    // the window will be created with a given title  bar
    glutCreateWindow("This is the first going throuygh this shit");

    init();

    // well, this assigns the picture definition to the display window
    glutDisplayFunc(lineSegment);

    // must be the last one in our program, it displays the initial
    // graphics and puts the program into an infinite loop
    //  that checks for input from devices, such
    glutMainLoop();

    /* code */
    return 0;
}
