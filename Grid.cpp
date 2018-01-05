#include "Grid.h"

using namespace std;

/* Initialises a grid and allocates the memory */
vector<vector<Block>> Grid::createGrid(int width, int height) {
	vector<vector<Block>> grid;

	// Let's initialise our vectors
	grid.reserve(width);

	// Set the height of each column
	for (int i = 0; i < grid.size; i++)
	{
		grid[i].reserve(height);
	}

	return grid;
}

/* Sets a block in the column and row provided, returning the previous occupant */
Block Grid::setBlock(int column, int row, Block block)
{
	// Guard against out of bounds by throwing exception
	Block oldBlock = grid.at(column).at(row);
	grid[column][row] = block;

	return oldBlock;
}

Block Grid::getBlock(int column, int row)
{
	// Guard against out of bounds by throwing exception
	return grid.at(column).at(row);
}

/* Rotates a grid 90 degrees in the desired direction*/
void Grid::rotate(bool clockwise)
{
	// Switch around the heights and width dimensions
	int newHeight = grid[0].size();
	int newWidth = grid.size();

	// Get a correctly sized grid
	vector<vector<Block>> newGrid = createGrid(newWidth, newHeight);

	// Place each value that was in a column in the row
	for (int i = 0; i < newWidth; i++)
	{
		for (int j = 0; j < newHeight; j++)
		{
			newGrid[i][j] = grid[j][i];
		}
	}

	// Swap the grids around
	grid = newGrid;
}

/* Initialises a grid of width by height */
Grid::Grid(int width, int height)
{
	grid = createGrid(width, height);
}
