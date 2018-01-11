#pragma once

#include "IDisplay.h"
#include "Grid.h"

enum TetrominoType { I, J, O, L, S, Z, T, TYPE_COUNT };

/* Constructs the provided Tetromino */
class Tetromino : public Grid
{
	public:
		Tetromino(TetrominoType type);
		static Tetromino* random();
};
