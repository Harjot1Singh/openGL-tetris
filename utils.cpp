#include <GL/glew.h>
#include <GL/glut.h>
#include <string>
#include "utils.h"

using namespace std;

/* Draws text at x, y, with the given message and size of font */
void drawText(int offsetX, int offsetY, string message, float fontSize, float weight)
{
	// Seperate matrix for each item of text
	glPushMatrix();
		// Size the font
		glScalef(fontSize, fontSize, 1.0f);
		// Place the text within the bounds defined in 2D space, scaling the coordinates correctly
		glTranslatef(offsetX * (1/fontSize), offsetY * (1/fontSize), 0.0f);
		glLineWidth(weight);
		// loop to display character by character
		for (int i = 0; i < message.length(); i++)
		{
			// Paint each character with strokes
			glutStrokeCharacter(GLUT_STROKE_ROMAN, message[i]);
		}
	// Finish with the matrix
	glPopMatrix();
}

/* Draws a solid 1x1 square */
void drawSquare()
{
  glBegin(GL_POLYGON);
    glVertex2f(0.0f, 0.0f);
    glVertex2f(0.0f, 1.0f);
    glVertex2f(1.0f, 1.0f);
    glVertex2f(1.0f, 0.0f);
  glEnd();
}

/* Draws the outline of a 1x1 square */
void drawSquareOutline()
{
	const float padding = 0.00f;
	glBegin(GL_LINE_LOOP);
		glVertex2f(padding, padding);
		glVertex2f(padding, 1.0f - padding);
		glVertex2f(1.0f - padding, 1.0f - padding);
		glVertex2f(1.0f - padding, padding);
	glEnd();
}
