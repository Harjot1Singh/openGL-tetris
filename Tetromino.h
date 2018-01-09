#pragma once

#include "IDisplay.h"
#include "Grid.h"

class Tetromino : public Grid, public IDisplay
{
	public:
		void display();
		Tetromino();
};
