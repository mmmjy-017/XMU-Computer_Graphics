/////////////////////////////////          
// box.cpp
//
// This program draws a wire box.
//
// Sumanta Guha.
/////////////////////////////////

#include <iostream>

#include <GL/glew.h>
#include <GL/freeglut.h> 

// Drawing routine.
void drawScene(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0, 0.0, 0.0);
	glLoadIdentity();

	// Modeling transformations.
	glTranslatef(0.0, 0.0, -15.0);

	glutWireCube(5.0); // Box.

	glColor3f(1.0, 0.0, 0.0);
	glTranslatef(0.0, 4.0, 0.0);
	glRotatef(45.0, 0.0, 0.0, 1.0);
	glutWireCube(2.0);

	glLoadIdentity();
	glTranslatef(-2.0, -4.0, -15.0);
	//glRotatef(30.0, 1.0, 0.0, 0.0);
	glScalef(1.0, 3.0, 1.0);
	glutWireCube(1.0);

	glLoadIdentity();
	glTranslatef(2.0, -4.0, -15.0);
	//glRotatef(30.0, 1.0, 0.0, 0.0);
	glScalef(1.0, 3.0, 1.0);
	glutWireCube(1.0);

	glFlush();
}

// Initialization routine.
void setup(void)
{
	glClearColor(1.0, 1.0, 1.0, 0.0);
}

// OpenGL window reshape routine.
void resize(int w, int h)
{
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glFrustum(-5.0, 5.0, -5.0, 5.0, 5.0, 100.0);

	glMatrixMode(GL_MODELVIEW);
}

// Keyboard input processing routine.
void keyInput(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 27:
		exit(0);
		break;
	default:
		break;
	}
}

// Main routine.
int main(int argc, char **argv)
{
	glutInit(&argc, argv);

	glutInitContextVersion(4, 3);
	glutInitContextProfile(GLUT_COMPATIBILITY_PROFILE);

	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("box.cpp");
	glutDisplayFunc(drawScene);
	glutReshapeFunc(resize);
	glutKeyboardFunc(keyInput);

	glewExperimental = GL_TRUE;
	glewInit();

	setup();

	glutMainLoop();
}

