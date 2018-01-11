#include <iostream>
#include <cmath>
#include <GL/glew.h>
#include <GL/glut.h>

#include "Grid.h"
#include "utils.h"

#include "Game.h"

using namespace std;

/* Gets the next piece to play */
void Game::getNextPiece()
{
	// If there is no next piece, generate one
	if (!nextPiece)
	{
		nextPiece = Tetromino::random();
	}
	// Free the old current piece's memory
	delete currentPiece;
	// Swap the pieces
	currentPiece = nextPiece;
	// Generate a new piece
	nextPiece = Tetromino::random();
}

/* Increments the level, up to 15 */
void Game::increaseLevel()
{
	if (level != 15)
	{
		level += 1;
	}
}

/* Starts the game */
void Game::startGame()
{
	// Reset the level
	level = 1;
	hasStarted = true;
}

/* Stops the game */
void Game::stopGame()
{
	hasStarted = false;
}

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
	// (0.8-((Level-1)*0.007))(Level-1), from Tetris World
	double seconds = pow(0.8 - ((level - 1) * 0.007), level-1);
	return round(seconds * 1000);
}

/* Handles keypresses */
void Game::keypress(unsigned char key)
{
	switch (key)
	{
		case 13: return startGame(); // Enter key
		case 27: return stopGame(); // ESC key
	}
}

/* Draws the content of the game */
void Game::display()
{
	board.display();
	// Display a message the game has not started
	if (!hasStarted)
	{
		drawText(0, 200, "Press ENTER to start!");
		return;
	}

	// Display controls
	drawText(0, 500, "Use 'LEFT'/'RIGHT' to move the piece");
	drawText(0, 880, "Use 'UP'/'DOWN' to rotate the piece");
	drawText(0, 840, "Use 'ESC' to end the game");
}

Game::Game()
{
	// Initialise the board
	board = Board();
}
