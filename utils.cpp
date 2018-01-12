#include <GL/glew.h>
#include <GL/glut.h>

#include <iostream>
#include "utils.h"

#include <stdlib.h>
#include <stddef.h>

/* Draws text, where 0 < x, y < 1000 */
void drawText(const int x, const int y, const char* message, const float fontSize)
{
	const int size = 1000;
	// Disable lighting and setup projection matrix
	glDisable(GL_LIGHTING);
	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
		// Reset view and define "viewing box"
		glLoadIdentity();
		gluOrtho2D(0, size, 0, size);
		// Setup Model view matrix and reset it
		glMatrixMode(GL_MODELVIEW);
		glPushMatrix();
			glLoadIdentity();
			// Size the font
			glScalef(fontSize, fontSize, 1.0f);
			// Place the text within the bounds defined in 2D space
			glTranslatef(x, y, 0.0f);
			// Color it white
			glColor3f(1.0f, 1.0f, 1.0f);
			// Get the length of the string
			size_t len = strlen(message);
			// loop to display character by character
			for (int i = 0; i < len; i++)
			{
				// Paint each character with strokes
				glutStrokeCharacter(GLUT_STROKE_ROMAN, message[i]);
			}
		// Finish with the matricies
		glPopMatrix();
	glPopMatrix();
	// Re-enable lighting
	glEnable(GL_LIGHTING);
}

void drawSquare(const int x, const int y, const int size)
{
	glDisable(GL_LIGHTING);
	glPushMatrix();
		glLoadIdentity();
		glTranslatef(x, y, 0.0f);
		glScalef(size, size, size);
		glColor3f(1.0f, 0.2f, 1.0f);
		glBegin(GL_POLYGON);
			glVertex2f(-1.0f, -1.0f);
			glVertex2f(-1.0f, 1.0f);
			glVertex2f(1.0f, 1.0f);
			glVertex2f(1.0f, -1.0f);
		glEnd();
		glColor3f(1.0f, 1.0f, 1.0f);
		glBegin(GL_LINE_LOOP);
			glVertex2f(-1.0f, -1.0f);
			glVertex2f(-1.0f, 1.0f);
			glVertex2f(1.0f, 1.0f);
			glVertex2f(1.0f, -1.0f);
		glEnd();
	glPopMatrix();
	glEnable(GL_LIGHTING);
}
