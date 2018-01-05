#pragma once
#include <vector>

#include "Block.h"

/* Grid holds an arrangement of Blocks in a matrix */
class Grid
{
public:
	std::vector<std::vector<int>> grid;
	Grid(int width, int height);
	~Grid();
};

