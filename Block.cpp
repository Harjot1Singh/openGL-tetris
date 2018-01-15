#include <array>
#include <GL/glew.h>
#include <GL/glut.h>

#include "utils.h"
#include "Block.h"

using namespace std;

void Block::setColor(array<float, 3> color)
{
  // Copy the arrays, using std::array
  this->color = color;
  // Now make the outline color
  this->outlineColor = color;
  // Add some "darkness" to the outline colour
  for (float &value : this->outlineColor)
  {
    value += 0.15f;
  }
}

/* Display the block, if it's not "empty" */
void Block::display()
{
  // Only display if the block is isVisible
  if (isEmpty)
  {
    return;
  }

  // Set the square color and draw the square
  glColor3fv(color.data());
  drawSquare();

  // Set the outline colour and draw the outline
  glColor3fv(outlineColor.data());
  drawSquareOutline();
}

Block::Block() {}
