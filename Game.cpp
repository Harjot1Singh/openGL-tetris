#include <iostream>

#include "Game.h"
#include "utils.h"

using namespace std;

/* Draws the content of the game */
void Game::display()
{
	drawText(0, 200, "Use ' ' to spin the model");
	drawText(0, 500, "Use 'x'/'X' to rotate the model in X axis");
	drawText(0, 880, "Use '+'/'-' to change line width");
	drawText(0, 840, "Use 'q' to quit");
}

Game::Game()
{
}
