#include <vector>
#include <map>
#include <iostream>

#include "Tetromino.h"

using namespace std;

/* Holds the dimensions of each Tetromino block */
const map<TetrominoType, vector<vector<int>>> dimensions = {
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

/* Get the tetromino width from the dimensions map */
getTetrominoWidth(TetrominoType type)
{
  return dimensions.at(type).size();
}

/* Get the tetromino height from the dimensions map */
getTetrominoHeight(TetrominoType type)
{
  return dimensions.at(type).at(0).size();
}

Tetromino::Tetromino(TetrominoType type) :
  Grid(getTetrominoWidth(type), getTetrominoHeight(type))
{
  // Get the dimensions for the type
  vector<vector<int>> layout = dimensions.at(type);
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
        block->setVisible(true);
        cout << "Setting " << col << row << endl;
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
