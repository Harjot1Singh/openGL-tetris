#include <cmath>
#include <string>
#include <ctime>

#include <GL/glew.h>
#include <GL/glut.h>

#include "utils.h"
#include "Grid.h"
#include "Game.h"

using namespace std;

/* Display the current piece, if it exists */
void Game::displayCurrentPiece()
{
  if (currentPiece)
  {
    glPushMatrix();
      // Calculate x position by taking into account columns and widths
      float x = Grid::BLOCK_WIDTH * (currentColumn - board.getWidth() + currentPiece->getWidth());
      // Calculate y, using the row and block width
      float y = Grid::BLOCK_WIDTH * (1 - currentRow);
      glTranslatef(x, y, 0.0f);
      currentPiece->display();
    glPopMatrix();
  }
}

/* Moves the piece one column left or right, if possible */
void Game::movePiece(bool right)
{
  int modifier = right ? 1 : -1;
  // Adjust the column in the correct directiom
  currentColumn += modifier;
  // Reverse the change if there is an overlap
  if (board.overlaps((Grid*) currentPiece, currentColumn, currentRow))
  {
    currentColumn -= modifier;
  }
}

/* Rotates the piece anti-clockwise, if possible */
void Game::rotatePiece(bool clockwise)
{
  // Try rotating it
  currentPiece->rotate(clockwise);

  // If it overlaps, un-rotate it
  if (board.overlaps((Grid*) currentPiece, currentColumn, currentRow))
  {
    currentPiece->rotate(!clockwise);
  }
}

/* Moves the piece down, if there's space, else merges it */
void Game::movePieceDown()
{
	// Move the piece down
	currentRow += 1;

	// Reverse the movement if it overlaps, and merge the grids
  if (board.overlaps((Grid*) currentPiece, currentColumn, currentRow))
  {
    currentRow -= 1;

		// The game has ended if we've already collided
		if (currentRow <= 0)
		{
			stop();
		} else {
			// Otherwise, proceed with merging the tetromino to the board
			board.merge((Grid *) currentPiece, currentColumn, currentRow);
			// Delete the block and free the memory
			delete currentPiece;
			currentPiece = nullptr;
		}
  }
}

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
	// Set the next piece on the board
	currentPiece = nextPiece;
	// Spawn the piece one row in
	currentRow = 2 - currentPiece->getHeight();
	// Spawn the piece vaguely in the middle
	currentColumn = (board.getWidth() + currentPiece->getWidth()) / 2 - 1;
	// Generate a new piece
	nextPiece = Tetromino::random();
}

/* Gets the level, up to 15. Every level = 5 lines. */
int Game::getLevel()
{
	// Return either 15, or any quotient of the lines/5
 	return min(div(lines, 5).quot, 15);
}

/* Starts the game */
void Game::start()
{
	// Don't be restarting a game
	if (hasStarted)
	{
		return;
	}
	// Randomise the seeds for rand()
	srand(time(0));
	// Initialise the board
	board = Board();
	// Reset the total lines and score
	lines = 0;
	score = 0;
	hasStarted = true;
	// Set the first piece
	getNextPiece();
}

/* Stops the game */
void Game::stop()
{
	hasStarted = false;
}

/* Updates the score, given the lines removed */
void Game::updateScore(int scoredLines)
{
	// Using formula from http://tetris.wikia.com/wiki/Scoring
	const int scoreMultipliers[4] = { 40, 100, 300, 1200 };
	score += scoreMultipliers[scoredLines - 1] * (getLevel() + 1);
}

/* Handles movement of blocks */
void Game::nextTick()
{
	// Don't do anything if the game hasn't started
	if (!hasStarted)
	{
		return;
	}

	// Move the piece down, if the board has one
	if (currentPiece)
	{
		// Move the piece down, if possible
		movePieceDown();
		// Get the number of lines removed
		int scoredLines = board.removeCompleteLines();
		// Update the score and line count if there were any removed lines
		if (scoredLines)
		{
			updateScore(scoredLines);
			lines += scoredLines;
		}
	} else {
		// Set the next piece for the board, if it's no longer in play
		getNextPiece();
	}
}

/* Gets the speed in milliseconds that the game should tick at */
int Game::getSpeed()
{
	int level = getLevel();
	// (0.8-((Level-1)*0.007))^(Level-1), from Tetris World, modified
	double seconds = pow(0.8 - ((level - 1) * 0.007), (level-1)/1.1);
	return round(seconds * 1000);
}

/* Handles keypresses */
void Game::keypress(unsigned char key)
{
	switch (key)
	{
		case 13: return start(); // Enter key
		case 27: return stop(); // ESC key
	}

	// If the game has started, handle the in-game keypresses
	if (hasStarted && currentPiece)
	{
		gameKeypress(key);
	}
}

/* Handle keypresses during a game */
void Game::gameKeypress(unsigned char key)
{
	switch(key)
	{
		case ' ': return nextTick();
		case GLUT_KEY_UP: return rotatePiece(false);
		case GLUT_KEY_DOWN: return rotatePiece(true);
		case GLUT_KEY_LEFT: return movePiece(false);
		case GLUT_KEY_RIGHT: return movePiece(true);
	}
}

/* Draws the content of the game */
void Game::display()
{
	// Clear the screen and depth buffer
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

	if (!hasStarted)
	{
		// Display a message if the game has not started
		return displayMenu();
	}

	// Display controls, score, leve, and the next piece
	displayControls();
	displayScore();
	displayLevel();
	displayNextPiece();

	// Push a matrix for the centre area
	glPushMatrix();
		// Centre the grid and blocks in the correct place
		glTranslatef(650.0f, 775.0f, 0.0f);
		// Display the board with existing pieces
		board.display();
		// Display the current piece, if it exists
		displayCurrentPiece();
	glPopMatrix();
}

/* Display text information about the controls */
void Game::displayControls()
{
	// Predefine the messages
	const vector<string> messages =
	{
			"Use 'LEFT'/'RIGHT' to move the piece",
			"Use 'UP'/'DOWN' to rotate the piece",
			"Press 'SPACE' to move the piece down",
			"Press 'ESC' to end the game"
	};

	glPushMatrix();
		// Color it white
		glColor3f(1.0f, 1.0f, 1.0f);
		// Place all text in top left corner
		glTranslatef(0.0f, GAME_SIZE - (messages.size() -1) * 50.0f, 0.0f);
		// Display each message with an offset
		for (int i = 0; i < messages.size(); i++)
		{
			// Offset each y coordinate and draw the text
			drawText(0, 35 * i, messages[i], 0.18f, 1.2f);
		}
	glPopMatrix();
}

/* Displays the next piece on the side */
void Game::displayNextPiece()
{
	glPushMatrix();
		// Move to right quarter of screen
		glTranslatef(850.0f, 650.0f, 0.0f);
		// Draw header
		glColor3f(0.8f, 0.8f, 0.8f);
		drawText(-100.0f, 100.0f, "Next Piece", 0.3f, 1.5f);
		// Display the piece
		nextPiece->display();
	glPopMatrix();
}

/* Displays the score separately */
void Game::displayScore()
{
	glPushMatrix();
		// Move to bottom left quarter of screen
		glTranslatef(0.0f, 300.0f, 0.0f);
		// Draw Level header
		glColor3f(0.8f, 0.8f, 0.8f);
		drawText(0.0f, 0.0f, "Score", 0.3f, 1.5f);
		// Display the score
		glColor3f(0.0f, 0.0f, 0.8f);
		drawText(50.0f, -100.0f, to_string(score), 0.5f, 3.0f);
	glPopMatrix();
}

/* Displays the current level */
void Game::displayLevel()
{
	int level = getLevel();
	glPushMatrix();
		// Move to top left quarter of screen
		glTranslatef(0.0f, 700.0f, 0.0f);
		// Draw Level header
		glColor3f(0.8f, 0.8f, 0.8f);
		drawText(0.0f, 0.0f, "Level", 0.3f, 1.5f);
		// The color will go from green to red depending on the level
		glColor3f((0.05f * (level-1)), 0.9f - (0.05f * (level-1)), 0.0f);
		// Display the level in a BIG font size
		drawText(50.0f, -175.0f, to_string(level), 1.2f, 6.0f);
	glPopMatrix();
}

/* Displays any menu text */
void Game::displayMenu()
{
	glColor3f(1.0f, 1.0f, 1.0f);
	drawText(200.0f, 100.0f, "Press ENTER to continue!", 0.35f, 2.0f);

	// Draw game over text if there was a previous score
	if (score > -1)
	{
		// Draw game over text in bold red
		glColor3f(1.0f, 0.0f, 0.0f);
		drawText(300.0f, 700.0f, "GAME OVER!", 0.45f, 5.0f);
		// Draw score
		glColor3f(0.0f, 0.0f, 0.8f);
		drawText(300.0f, 500.0f, "Score: " + to_string(score), 0.5f, 4.0f);
	}
}

/* Sets up the scene for the game */
void Game::initDisplay()
{
	// Disable the lighting
	glDisable(GL_LIGHTING);

	// Select the projection matrix
	glMatrixMode(GL_PROJECTION);

	// Set the game bounds
	gluOrtho2D(PADDING, GAME_SIZE, PADDING, GAME_SIZE);

	// Switch to the modelview matrix
	glMatrixMode(GL_MODELVIEW);
}

/* Constructor for Game sets up the board and scene */
Game::Game()
{
	// Initialise any display requirements
	initDisplay();
}
