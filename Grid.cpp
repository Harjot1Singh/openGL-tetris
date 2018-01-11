#include <iostream>

#include "Block.h"

#include "Grid.h"

using namespace std;

/* Displays all the items in the grid */
void Grid::display()
{
	// Get height and widths
	int height = getHeight();
	int width = getWidth();

	// Iterate over each run the display method
	for (int col = 0; col < width; col++)
	{
		for (int row = 0; row < height; row++)
		{
			// Display the block
			grid.at(col).at(row).display();
		}
	}
}

/* Initialises a grid and allocates the memory */
vector<vector<Block>> Grid::createGrid(int width, int height)
{
	vector<vector<Block>> grid;

	// Let's initialise our vectors
	grid.resize(width);

	// Set the height of each column
	for (int i = 0; i < width; i++)
	{
		grid[i].resize(height);
	}

	return grid;
}

/* Getter with protection for blocks */
Block* Grid::getBlock(int column, int row)
{
	return &grid.at(column).at(row);
}

/* Rotates a grid 90 degrees in the desired direction*/
void Grid::rotate(bool clockwise)
{
	// Switch around the heights and width dimensions
	int newHeight = getWidth();
	int newWidth = getHeight();

	// Get a correctly sized grid
	vector<vector<Block>> newGrid = createGrid(newWidth, newHeight);

	int direction = clockwise ? 1 : -1;

	// Place each value that was in a column in the row
	for (int col = 0; col < newWidth; col += direction)
	{
		for (int row = 0; row < newHeight; row += direction)
		{
			newGrid[col][row] = grid[row][col];
		}
	}

	// Replace the heights
	height = newHeight;
	width = newWidth;

	// Swap the grids around
	grid = newGrid;
}

/* Initialises a grid of width by height */
Grid::Grid(int width, int height) : height(height), width(width)
{
	grid = createGrid(width, height);
}
