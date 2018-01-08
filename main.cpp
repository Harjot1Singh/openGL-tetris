#include <iostream>

#include <stdlib.h>
#include <stddef.h>

#include <GL/glew.h>
#include <GL/glut.h>

#include "Game.h"

using namespace std;

// Global, since Glut callback functions do not accept parameters
Game game;

/* GLUT hook functions*/
void display()
{
	game.display();
	// Swap the buffers after the game has drawn to it
	glutSwapBuffers();
}

/* Hooks GLUT callback functions */
void hookGlut()
{
	glutDisplayFunc(display);
}

/* Displays version information about GLEW and openGL */
void displayGLInfo()
{
	cout << "Using GLEW " << glewGetString(GLEW_VERSION) << endl;
	cout << "Using OpenGL " << glGetString(GL_VERSION) << endl;
}


/* Initialises GLUT and GLEW */
void initGlut(int argc, char **argv)
{
	cout << "Initialising Tetris..." << endl;
    glutInit(&argc, argv);

	// Double buffering and RBGA mode
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);

	glutInitWindowSize(768, 768);
	glutCreateWindow("TetrisGL");

	glewInit();
}

/* Entry point */
int main(int argc, char **argv)
{
	initGlut(argc, argv);

	displayGLInfo();

	// Instantiate game
	game = Game();

	// Hook the glut callbacks to methods in game
	hookGlut();

    glutMainLoop();

	return 0;
}
