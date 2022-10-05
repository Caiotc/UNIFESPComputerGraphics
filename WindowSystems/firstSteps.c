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

void lineSegment() {}

int main(int argc, char *argv[])
{
    // glutInit also process any command line arguments
    glutInit(&argc, argv);
    // the window will be created with a given title  bar
    glutCreateWindow("This is the first going throuygh this shit");
    // well, this assigns the picture definition to the display window
    glutDisplayFunc(lineSegment);

    // must be the last one in our program, it displays the initial
    // graphics and puts the program into an infinite loop
    //  that checks for input from devices, such
    glutMainLoop();

    /* code */
    return 0;
}
