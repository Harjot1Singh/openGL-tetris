#include <vector>
#include <map>
#include <array>

#include "Tetromino.h"

using namespace std;

/* Holds the dimensions of each Tetromino block */
const map<TetrominoType, vector<vector<int>>> dimensions =
{
  { O, {
      { 1, 1 },
      { 1, 1 }
    } },
  { I, { { 1, 1, 1, 1 } } },
  { T, {
      { 1, 1, 1 },
      { 0, 1, 0 }
    } },
  { S, {
      { 0, 1, 1 },
      { 1, 1, 0 }
  } },
  { Z, {
      { 1, 1, 0 },
      { 0, 1, 1 }
  } },
  { J, {
      { 1, 1, 1 },
      { 0, 0, 1 }
  } },
  { L, {
      { 1, 1, 1 },
      { 1, 0, 0}
  } }
};

/* Holds the color of each tetromino block */
const map<TetrominoType, array<float, 3>> colors =
{
  { O, { 0.85f, 0.85f, 0.0f } },
  { I, { 0.0f, 0.85f, 0.85f } },
  { T, { 0.85f, 0.0f, 0.85f } },
  { Z, { 0.0f, 0.85f, 0.0f } },
  { S, { 0.85f, 0.0f, 0.0f } },
  { L, { 0.0f, 0.0f, 0.85f } },
  { J, { 0.85f, 0.35f, 0.0f } },
};

/* Get the tetromino width from the dimensions map */
int getTetrominoWidth(TetrominoType tetrominoType)
{
  return dimensions.at(tetrominoType).size();
}

/* Get the tetromino height from the dimensions map */
int getTetrominoHeight(TetrominoType tetrominoType)
{
  return dimensions.at(tetrominoType).at(0).size();
}

Tetromino::Tetromino(TetrominoType type) :
  Grid(getTetrominoWidth(type), getTetrominoHeight(type))
{
  // Get the dimensions for the type
  vector<vector<int>> layout = dimensions.at(type);
  // Get the color for the type
  array<float, 3> color = colors.at(type);

  // Get height and width again
  int height = getTetrominoHeight(type);
  int width = getTetrominoWidth(type);

  // Set the blocks to non-empty as per the map
  for (int col = 0; col < width; col++)
  {
    for ( int row = 0; row < height; row++)
    {
      // If the block is non-0 in the layout matrix, enable it
      if (layout.at(col).at(row))
      {
        // Set the block to visible
        Block* block = getBlock(col, row);
        block->setEmpty(false);
        block->setColor(color);
      }
    }
  }
}

/* Static method to get a random Tetromino*/
Tetromino* Tetromino::random()
{
  // Grab a random type from the enum
  TetrominoType type = static_cast<TetrominoType>(rand() % TYPE_COUNT);
  return new Tetromino(type);
}
