#include <vector>
#include <map>

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
},

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

}
