#include <GL/glew.h>
#include <GL/glut.h>

#include "utils.h"
#include "Board.h"

/* Removes any complete lines, returning the number */
int Board::removeCompleteLines()
{
  int completeLines = 0;

  int height = getHeight();
  // Check every column in a row is filled
  for (int row = 0; row < height; row++)
  {
    // If the row is complete, remove the row and increment
    if (isRowComplete(row))
    {
      completeLines++;
      emptyRow(row);
    }
  }

  return completeLines;
}

/* Returns true if the given row is complete */
bool Board::isRowComplete(int row)
{
  int width = getWidth();
  for (int col = 0; col < width; col++)
  {
    // If there is an empty column, row is incomplete
    if (getBlock(col, row)->getEmpty())
    {
      return false;
    }
  }
  // Else, we have a complete row
  return true;
}


/* Displays the outlines of the grid */
void Board::displayOutline()
{
  // Get height and widths
  int height = getHeight();
  int width = getWidth();

  glPushMatrix();
    // Set the color to white
    glColor3f(1.0f, 1.0f, 1.0f);
    // Set the line width to 1.5f
    glLineWidth(1.5f);
    // Scale/size everything by BLOCK_WIDTH
    glScalef(BLOCK_WIDTH, BLOCK_WIDTH, BLOCK_WIDTH);
    // Iterate over each run the display method
    for (int col = 0; col < width; col++)
    {
      // Matrix per grid-column
      glPushMatrix();
        // Translate each column to the correct height, inverting the column
        glTranslatef(col * -1, 0.0f, 0.0f);
        for (int row = 0; row < height; row++)
        {
          // Setup a matrix for each grid row
          glPushMatrix();
            // Move the row accordingly, inverting the row
            glTranslatef(0.0f, row * -1, 0.0f);
            // Display a square outline
            drawSquareOutline();
          // Pop the matrix stack for rows
          glPopMatrix();
        }
      // Pop the matrix stack for columns
      glPopMatrix();
    }
   // Pop the entire grid matrix stack
  glPopMatrix();
}

/* Draws the board, along with an outlined grid */
void Board::display()
{
  // Display the grid outlines
  displayOutline();
  // Finally, draw the contents of the grid
  Grid::display();
}

/* A board is a 10x20 grid */
Board::Board() : Grid(10, 20) { }
