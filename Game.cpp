#include <iostream>

#include <GL/glew.h>
#include <GL/glut.h>

#include "Game.h"

using namespace std;

/* Draws text */
void drawText(const int x, const int y, const char* message)
{
	glMatrixMode (GL_MODELVIEW) ;
	glPushMatrix();
		glTranslatef(x, y, 0);
		glScalef(0.25f, 0.25f, 1.0f);
		//get the length of the string to display
		size_t len = strlen(message);
		// loop to display character by character
		for (int i = 0; i < len; i++)
		{
			glutStrokeCharacter(GLUT_STROKE_ROMAN, message[i]);
		}
	glPopMatrix();
}

/* Draws the content of the game */
void Game::display()
{
	glLineWidth(1.0);
	glDisable(GL_LIGHTING);
	// put some help on the screen
	drawText(0, 0, "Use ' ' to spin the model");
	drawText(0, 600, "Use 'x'/'X' to rotate the model in X axis");
	drawText(100, 880, "Use '+'/'-' to change line width");
	drawText(100, 840, "Use 'q' to quit");
	glEnable(GL_LIGHTING);
}

Game::Game()
{
}
