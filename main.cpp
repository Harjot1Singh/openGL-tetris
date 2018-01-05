#include <iostream>

#include <GL/glew.h>
#include <GL/glut.h>

#include <stdlib.h>
#include <stddef.h>

using namespace std;

void displayGLInfo() 
{
	cout << "Using GLEW " << glewGetString(GLEW_VERSION) << endl;
	cout << "Using OpenGL " << glGetString(GL_VERSION) << endl;
}

int main(int argc, char **argv) 
{
	cout << "Initialising Tetris..." << endl;
    glutInit(&argc, argv);

	glutInitWindowSize(512, 512);
	glutInitWindowPosition(50, 50);

	glutCreateWindow("TetrisGL");

    glewInit();
	
	displayGLInfo();
    glutMainLoop();
	return 0;
}
