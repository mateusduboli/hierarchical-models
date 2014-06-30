#include <GL/glut.h>
#include <GL/freeglut.h>
#include <stdio.h>

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
    glPushMatrix();
    glutSolidCylinder(0.7, 0.7, 16, 16);
    glPopMatrix();
}

int main(int argc, char** argv)
{
    glutInitWindowSize(GL_HEIGHT, GL_WIDTH);
    glutInitWindowPosition(0, 0);
    glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);
    glutInit(&argc, argv);

    window = glutCreateWindow("INE5420 - Modelos Hierarquicos");
    glutKeyboardFunc(&commandKeys);
    glutSpecialFunc(&movementKeys);

    glClearColor(0.5f, 0.5f, 0.5f, 1.0);
    glClearDepth(1.0f);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);
    glLoadIdentity();

    glutMainLoop();
    return 0;
}
