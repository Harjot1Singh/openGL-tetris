#pragma once

#include <vector>

#include "IDisplay.h"
#include "Block.h"

/* Grid holds an arrangement of Blocks in a matrix */
class Grid
{
	private:
		std::vector<std::vector<Block>> grid;
		static std::vector<std::vector<Block>> createGrid(int width, int height);
		int width;
		int height;
	public:
		static const int BLOCK_WIDTH = 40;
		inline int getWidth() { return width; };
		inline int getHeight() { return height; };
		void display();
		Block* getBlock(int column, int row);
		void rotate(bool clockwise);
		bool overlaps(Grid *grid, int x, int y);
		void merge(Grid *grid, int x, int y);
		void emptyRow(int row);
		Grid(int width, int height);
};
