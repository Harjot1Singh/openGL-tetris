#pragma once

#include "IDisplay.h"

#include "Menu.h"

enum Difficulty { Easy, Medium, Hard };

class Game : public IDisplay
{
	public:
		void display();
		void keypress(unsigned char key);
		void nextTick();
		int getSpeed();
		Game();
	private:
		Menu menu;
		Difficulty difficulty;
		bool hasStarted = false;
};
