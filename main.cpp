#include <GL/glew.h>
#include <GL/glut.h>

#include <iostream>
#include <stdlib.h>
#include <stddef.h>

int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glewInit();

    glutMainLoop();
}
