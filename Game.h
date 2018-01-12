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
		Game();
	private:
		bool hasStarted = false;
		int level = 1;
		Board board;
		Tetromino* currentPiece = nullptr;
		Tetromino* nextPiece = nullptr;
		void start();
		void stop();
		void getNextPiece();
		void increaseLevel();
};
