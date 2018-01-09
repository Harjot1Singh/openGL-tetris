#include <GL/glew.h>
#include <GL/glut.h>

#include <iostream>
#include "utils.h"

/* Draws text, where 0 < x, y < 1000 */
void drawText(const int x, const int y, const char* message, const float fontSize)
{
	const int size = 1000;
	void * font = GLUT_BITMAP_9_BY_15;

	// Disable lighting and setup projection matrix
	glDisable(GL_LIGHTING);
	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
		glLoadIdentity();
		// Set up a plane of size x size
		gluOrtho2D(0, size, 0, size);
		// Setup model view matrix and reset
		glMatrixMode(GL_MODELVIEW);
		glPushMatrix();
			glLoadIdentity();
			glColor3f(0.0, 1.0, 0.0);
			glRasterPos2i(900, 900);
			size_t len = sizeof(message);
			for (int i = 0; i < len; i++)
			{
    		glutBitmapCharacter(font, message[i]);
			}
			glMatrixMode(GL_MODELVIEW);
		glPopMatrix();
		glMatrixMode(GL_PROJECTION);
	glPopMatrix();
	// Re-enable lighting
	glEnable(GL_LIGHTING);
}
