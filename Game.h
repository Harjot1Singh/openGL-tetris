#pragma once

#include "IDisplay.h"
#include "Board.h"

class Game : public IDisplay
{
	public:
		void display();
		void keypress(unsigned char key);
		void nextTick();
		int getSpeed();
		void initDisplay();
		Game();
	private:
		bool hasStarted = false;
		int score = -1;
		int lines;
		Board board;
		Tetromino* nextPiece = nullptr;
		Tetromino* currentPiece = nullptr;
		int currentRow;
		int currentColumn;
		int getLevel();
		void start();
		void stop();
		void updateScore(int scoredLines);
		void displayCurrentPiece();
		void movePiece(bool right);
		void rotatePiece(bool clockwise);
		void movePieceDown();
		void displayControls();
		void displayMenu();
		void displayNextPiece();
		void displayScore();
		void displayLevel();
		void getNextPiece();
		void gameKeypress(unsigned char key);
};

// The size and padding of the board
const int GAME_SIZE = 1000;
const int PADDING = -20;
