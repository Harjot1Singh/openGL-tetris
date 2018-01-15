#pragma once

#include "Tetromino.h"
#include "Grid.h"
#include "IDisplay.h"

class Board :	public Grid
{
	private:
		void displayOutline();
		bool isRowComplete(int row);
	public:
		void display();
		int removeCompleteLines();
		Board();
};
