#pragma once

#include "IDisplay.h"
#include "Grid.h"

enum TetrominoType { I, J, O, L, S, Z, T };

/* Constructs the provided Tetromino */
class Tetromino : public Grid, public IDisplay
{
	public:
		Tetromino(TetrominoType type);
};
