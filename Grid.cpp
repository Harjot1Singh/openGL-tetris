#include <GL/glew.h>
#include <GL/glut.h>

#include "Block.h"
#include "Grid.h"

using namespace std;

/* Empties a row from the board, shifting the others down */
void Grid::emptyRow(int row)
{
	// Erase the row
	grid.erase(grid.begin() + row);

	vector<Block> newRow;
	// Resize the new row
	newRow.resize(height);
	// Add the row to the front
	grid.insert(grid.begin(), newRow);
}

/* Merges the current grid with another */
void Grid::merge(Grid *source, int x, int y)
{
	// Get grid height and width
	int sourceHeight = source->getHeight();
	int sourceWidth = source->getWidth();

	for (int col = 0; col < sourceWidth; col++)
	{
		for (int row = 0; row < sourceHeight; row++)
		{
			// Get the source block, deferenced
			Block sourceBlock = *source->getBlock(col, row);
			// Only replace non-empty blocks
			if (!sourceBlock.getEmpty())
			{
				// x[0] is on the right-hand side of the grid
				int destX = getWidth() - (x - col + sourceWidth);
				int destY = y + row - 1;
				// Set the new block at the correct point in the grid
				grid[destY][destX] = *source->getBlock(col, row);
			}
		}
	}
}

/* Returns true if the grid at x, y overlaps any blocks in the current grid */
bool Grid::overlaps(Grid *source, int x, int y)
{
	// Get grid width and height
	int sourceWidth = source->getWidth();
	int sourceHeight = source->getHeight();

	// Check if going over any boundaries
	if ((x + sourceWidth) > getWidth() || x < 0 || (y + sourceHeight - 1) > getHeight())
	{
		return true;
	}

	// Check each active block in the grid
	for (int row = 0; row < sourceHeight; row++)
	{
		for (int col = 0; col < sourceWidth; col++)
		{
			// Get the block from the subgrid
			Block *block = source->getBlock(col, row);

			// If the block is empty, don't bother checking it
			if (block->getEmpty())
			{
				continue;
			}

			// x[0] is on the right-hand side of the grid
			int targetX = getWidth() - (x - col + sourceWidth);
			int targetY = y + row - 1;

			// Don't bother checking any of remaining row if targetY ends up being off-grid
			if (targetY < 0)
			{
				break;
			}

			// If there's another non-empty block at the same spot, there is a collision
			if (!getBlock(targetX, targetY)->getEmpty())
			{
				return true;
			}
		}
	}

	return false;
}

/* Displays all the items in the grid */
void Grid::display()
{
	// Get height and widths
	int height = getHeight();
	int width = getWidth();

	glPushMatrix();
		// Scale/size everything by BLOCK_WIDTH
		glScalef(BLOCK_WIDTH, BLOCK_WIDTH, BLOCK_WIDTH);
		// Iterate over each run the display method
		for (int col = 0; col < width; col++)
		{
			// Matrix per grid-column
			glPushMatrix();
				// Translate each column to the correct height, inverting the column
				glTranslatef(col * -1.0f, 0.0f, 0.0f);
				for (int row = 0; row < height; row++)
				{
					// Setup a matrix for each grid row
					glPushMatrix();
						// Move the row accordingly, inverting the row
						glTranslatef(0.0f, row * -1.0f, 0.0f);
						// Display the 1x1 block with all the above transformations
						grid.at(row).at(col).display();
					// Pop the matrix stack for rows
					glPopMatrix();
				}
			// Pop the matrix stack for columns
			glPopMatrix();
		}
	 // Pop the entire grid matrix stack
	glPopMatrix();
}

/* Initialises a grid and allocates the memory */
vector<vector<Block>> Grid::createGrid(int width, int height)
{
	vector<vector<Block>> grid;

	// Let's initialise our vectors
	grid.resize(height);

	// Set the height of each column
	for (int i = 0; i < height; i++)
	{
		grid[i].resize(width);
	}

	return grid;
}

/* Getter with protection for blocks */
Block* Grid::getBlock(int column, int row)
{
	return &grid.at(row).at(column);
}

/* Rotates a grid 90 degrees in the desired direction*/
void Grid::rotate(bool clockwise)
{
	// Switch around the heights and width dimensions
	int newHeight = getWidth();
	int newWidth = getHeight();

	// Get a correctly sized grid
	vector<vector<Block>> newGrid = createGrid(newWidth, newHeight);

	// Place each value that was in a column in the row
	for (int col = 0; col < newWidth; col++)
	{
		for (int row = 0; row < newHeight; row++)
		{
			newGrid[row][col] = clockwise ? grid[col][newHeight - row - 1] : grid[newWidth - col - 1][row];
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
