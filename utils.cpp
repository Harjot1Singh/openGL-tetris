#include <GL/glew.h>
#include <GL/glut.h>

#include "utils.h"

/* Draws text, where 0 < x, y < 1000 */
void drawText(const int x, const int y, const char* message, const float fontSize)
{
	const int padding = 20;
	const int size = 1000;
	// Disable lighting and setup projection matrix
	glDisable(GL_LIGHTING);
	glMatrixMode (GL_PROJECTION);
	glPushMatrix();
		// Reset view and define "viewing box"
		glLoadIdentity();
		gluOrtho2D(-padding, size, -padding, size); // -padding to add "padding" to window
		// Setup Model view matrix and reset it
		glMatrixMode(GL_MODELVIEW);
		glPushMatrix();
			glLoadIdentity();
			// Place the text within the bounds defined in 2D space
			glTranslatef(x, y, 0.0f);
			// Size the font
			glScalef(fontSize, fontSize, 1.0f);
			// Get the length of the string
			size_t len = strlen(message);
			// loop to display character by character
			for (int i = 0; i < len; i++)
			{
				// Paint each character with strokes
				glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN, message[i]);
			}
		// Finish with the matricies
		glPopMatrix();
	glPopMatrix();
	// Re-enable lighting
	glEnable(GL_LIGHTING);
}
