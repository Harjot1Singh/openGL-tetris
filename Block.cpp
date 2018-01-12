#include <iostream>
#include <GL/glew.h>
#include <GL/glut.h>

#include "Block.h"

using namespace std;

void Block::display()
{
  // Only display if the block is isVisible
  if (isEmpty)
  {
    return;
  }

  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  gluLookAt(1, 1, 2,  // eye position
            0, 0, 0,  // reference point
            0, 1, 0); // up vector

  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();

  glOrtho(-20, 20, -20, 20, -4, 4);
  glDisable(GL_LIGHTING);
  glutSolidCube(1.0f);
  renderBlock();
  glEnable(GL_LIGHTING);
}

/* Render a 3D cube, similar to glutSolidCube */
void Block::renderBlock()
{
  static GLfloat n[6][3] =
  {
    {-1.0, 0.0, 0.0},
    {0.0, 1.0, 0.0},
    {1.0, 0.0, 0.0},
    {0.0, -1.0, 0.0},
    {0.0, 0.0, 1.0},
    {0.0, 0.0, -1.0}
  };
  static GLint faces[6][4] =
  {
    {0, 1, 2, 3},
    {3, 2, 6, 7},
    {7, 6, 5, 4},
    {4, 5, 1, 0},
    {5, 6, 2, 1},
    {7, 4, 0, 3}
  };
  GLfloat v[8][3];
  GLint i;

  v[0][0] = v[1][0] = v[2][0] = v[3][0] =
  v[0][1] = v[1][1] = v[4][1] = v[5][1] =
  v[0][2] = v[3][2] = v[4][2] = v[7][2] = -1;

  v[4][0] = v[5][0] = v[6][0] = v[7][0] =
  v[2][1] = v[3][1] = v[6][1] = v[7][1] =
  v[1][2] = v[2][2] = v[5][2] = v[6][2] = 1;

  for (i = 0; i < 6; i++) {
    glBegin(GL_POLYGON);
      glNormal3fv(&n[i][0]);
      glVertex3fv(&v[faces[i][0]][0]);
      glVertex3fv(&v[faces[i][1]][0]);
      glVertex3fv(&v[faces[i][2]][0]);
      glVertex3fv(&v[faces[i][3]][0]);
    glEnd();
  }
}

Block::Block()
{
}
