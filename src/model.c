#include <GL/glut.h>
#include <GL/freeglut.h>

#include <stdio.h>
#include "wire_elephant.h"

const int GL_HEIGHT = 400;
const int GL_WIDTH  = GL_HEIGHT;
const int TIMER_INTERVAL = 200;

int window = 0;
int angle = 0;
int frame = 0;

double param = 0.1;

void commandKeys(unsigned char key, int x, int y)
{
    switch(key) {
        case 'q':
            glutDestroyWindow(window);
            glutLeaveMainLoop();
            break;
        case 'a':
            param+=0.01;
            break;
        case 'd':
            param-=0.01;
            break;
    }
    printf("param: %f\n", param);
}

void movementKeys(int key, int x, int y)
{
    switch(key) {
        case GLUT_KEY_RIGHT:
            angle+=5;
            angle%=360;
            break;
        case GLUT_KEY_LEFT:
            angle-=5;
            angle%=360;
            break;
    }
    printf("H: %i deg\n", angle);
}

void draw()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glClearColor(0, 0, 0, 1.0f);
    glLoadIdentity();
    glRotatef(angle, 0.0, 1.0, 0.0);
    elephant(frame, param);
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

void timer(int value)
{
    frame++;
    printf("Frame: %d\n", frame);
    glutPostRedisplay();
    glutTimerFunc(TIMER_INTERVAL, &timer, 0);
}

int main(int argc, char** argv)
{
    window = initWindow(argc, argv);

    glutKeyboardFunc(&commandKeys);
    glutSpecialFunc(&movementKeys);
    glutDisplayFunc(&draw);
    glutTimerFunc(TIMER_INTERVAL, &timer, 0);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    glutMainLoop();
    return 0;
}
