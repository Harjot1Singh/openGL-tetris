#include <iostream>

#include <GL/glew.h>
#include <GL/glut.h>

#include "Game.h"

using namespace std;

// Global, since Glut callback functions do not accept parameters
Game game;

/* GLUT callback functions*/
void tick(int value)
{
		// Tick the game everytime the glut timer fires
		game.nextTick();
		// Redraw everything
		glutPostRedisplay();
		// The timer should be set depending on the level the user is on
		glutTimerFunc(game.getSpeed(), tick, 0);
}

/* Handles keypress mappings */
void keypress(unsigned char key, int, int)
{
	// Let the game handle keypresses
	game.keypress(key);
	// Redisplay after a keypress
	glutPostRedisplay();
}

/* Passes on special key presses to the normal keypress handler */
void specialKeypress(int key, int x, int y)
{
	keypress(key, x, y);
}

/* Resizes the window to maintain an aspect ratio of 1:1 */
void resizeWindow(int width, int height)
{
	// Switch to project matrix and clear it
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();

	// The left position is set to the middle-est possible within the ratio
  int left = (width - height) / 2;

	// Set the viewport to the new dimensions
  glViewport(left, 0, height, height);

	// Reinitialise the game display
	game.initDisplay();

	// Redraw everything
  glutPostRedisplay();
}

/* Displays the game */
void display()
{
	game.display();
	// Swap the buffers after the game has drawn to it
	glutSwapBuffers();
}

/* Hooks GLUT callback functions */
void hookGlut()
{
	glutTimerFunc(500, tick, 0);
	glutDisplayFunc(display);
	glutKeyboardFunc(keypress);
	glutReshapeFunc(resizeWindow);
	glutSpecialFunc(specialKeypress);
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
	glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGBA);

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
