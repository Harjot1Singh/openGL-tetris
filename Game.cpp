#include <iostream>

#include <GL/glew.h>
#include <GL/glut.h>

#include "utils.h"

#include "Menu.h"
#include "Game.h"

using namespace std;

/* Draws the content of the game */
void Game::display()
{
		glColor3f(1.0f, 1.0f, 1.0f);
		glBegin(GL_POLYGON);
			glVertex2f(-0.5f, -0.5f);
			glVertex2f(-0.2f, -0.5f);
			glVertex2f(-0.5f, -0.2f);
			glVertex2f(-0.3f, -0.2f);
		glEnd();

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
