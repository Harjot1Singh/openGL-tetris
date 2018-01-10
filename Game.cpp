#include <iostream>

#include <GL/glew.h>
#include <GL/glut.h>

#include "utils.h"

#include "Menu.h"
#include "Game.h"

using namespace std;

/* Handles movement of blocks */
void Game::nextTick()
{
	// Don't do anything if the game hasn't started
	if (!hasStarted)
	{
		return;
	}
}

/* Gets the speed in milliseconds that the game should tick at */
int Game::getSpeed()
{
	switch (difficulty)
	{
		case Easy: return 1300; // 1.3 seconds per move
		case Medium: return 1000; // 1 second per move
		case Hard: return 700; // 0.7 seconds per move
	}
}

/* Handles keypresses */
void Game::keypress(unsigned char key)
{
	cout << key << endl;
}

/* Draws the content of the game */
void Game::display()
{
	glMatrixMode ( GL_MODELVIEW ) ;
glLoadIdentity () ;
gluLookAt (1 , 1 , 2 , // eye position
0, 0 , 0 , // reference point
0, 1 , 0 // up vector
);
glMatrixMode ( GL_PROJECTION );
glLoadIdentity () ;

glOrtho(-20, 20, -20, 20, -34, 4);
glDisable(GL_LIGHTING);
glutSolidCube(1.0f);
glEnable(GL_LIGHTING);

	// Display the menu if the game has not started
	if (!hasStarted)
	{
		menu.display();
		return;
	}

	drawText(0, 200, "Use ' ' to spin the model");
	drawText(0, 500, "Use 'x'/'X' to rotate the model in X axis");
	drawText(0, 880, "Use '+'/'-' to change line width");
	drawText(0, 840, "Use 'q' to quit");
}

Game::Game()
{
	menu = Menu();
}
