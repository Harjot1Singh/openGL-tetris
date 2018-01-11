#pragma once

#include "IDisplay.h"

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
		void increaseLevel();
		void startGame();
		void stopGame();
};
