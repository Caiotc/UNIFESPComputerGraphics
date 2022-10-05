#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>

void draw()
{
}

int main(int argc, char *argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

	glutInitWindowPosition(50, 100);

	glutInitWindowSize(400, 300);

	glutCreateWindow("New Opengl Window");

	glutDisplayFunc(draw);

	glutMainLoop();

	/* code */
	return 0;
}
