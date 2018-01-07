#include <GL/GLUT.h>

#include "Game.h"

/* Draws text */
void drawText(int x,  i )

/* Draws the content of the game */
void Game::display()
{
	glLineWidth(1.0);
	glDisable(GL_LIGHTING);
	// put some help on the screen
	draw_text(20, 960, "Use ' ' to spin the model");
	draw_text(20, 920, "Use 'x'/'X' to rotate the model in X axis");
	draw_text(20, 880, "Use '+'/'-' to change line width");
	draw_text(20, 840, "Use 'q' to quit");
	glEnable(GL_LIGHTING);
}

Game::Game()
{
}
