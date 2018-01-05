#pragma once
#include <vector>

#include "Block.h"

/* Grid holds an arrangement of Blocks in a matrix */
class Grid
{
private:
	std::vector<std::vector<Block>> grid;
	static vector<vector<Block>> createGrid(int width, int height);

public:
	Block setBlock(int column, int row, Block block);
	Block getBlock(int column, int row);
	void rotate(bool clockwise = true);
	Grid(int width, int height);
	~Grid();
};

