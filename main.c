#include <GL/glut.h>
#include <GL/freeglut.h>
#include <stdio.h>
#include "elephant.h"

const int GL_WIDTH  = 400;
const int GL_HEIGHT = 400;

int window = 0;

void commandKeys(unsigned char key, int x, int y)
{
    printf("Button %c presset at (%i, %i)\n", key, x, y);
    switch(key) {
        case 'q':
            glutDestroyWindow(window);
            glutLeaveMainLoop();
            break;
    }
}

void movementKeys(int key, int x, int y)
{
    printf("Button %i presset at (%i, %i)\n", key, x, y);
    switch(key) {
        case GLUT_KEY_UP:
            break;
        case GLUT_KEY_DOWN:
            break;
        case GLUT_KEY_LEFT:
            break;
        case GLUT_KEY_RIGHT:
            break;
    }
}

void draw()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glClearColor(1.0f, 0, 0, 1.0f);
    glLoadIdentity();
    elephant();
    glutSwapBuffers();
}

int initWindow(int argc, char** argv)
{
    glutInitWindowSize(GL_HEIGHT, GL_WIDTH);
    glutInitWindowPosition(0, 0);
    glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);
    glutInit(&argc, argv);

    return glutCreateWindow("INE5420 - Modelos Hierarquicos");
}

int main(int argc, char** argv)
{
    window = initWindow(argc, argv);

    glutKeyboardFunc(&commandKeys);
    glutSpecialFunc(&movementKeys);
    glutDisplayFunc(&draw);

    glutMainLoop();
    return 0;
}
