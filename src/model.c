#include <GL/glut.h>
#include <GL/freeglut.h>

#include <stdio.h>
#include "elephant.h"

const int GL_HEIGHT = 500;
const int GL_WIDTH  = GL_HEIGHT;
const int TIMER_INTERVAL = 100;

int window = 0;
int angle = 0;
int frame = 0;
int WIRED = 0;

double param = 0.1;

void commandKeys(unsigned char key, int x, int y)
{
    switch(key) {
        case 'q':
            glutDestroyWindow(window);
            glutLeaveMainLoop();
            break;
        case 's':
            WIRED = 1 - WIRED;
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

void draw_floor()
{
    glPushMatrix();
        glTranslatef(0.0, -ELEPHANT_HEIGHT, 0.0);
        glBegin(GL_POLYGON);
            glColor3f(0.0, 1.0, 0.0);
            glVertex3d(-1.0, 1.0, -1.0);
            glColor3f(1.0, 0.0, 0.0);
            glVertex3d(-1.0, 1.0, 1.0);
            glColor3f(0.0, 0.0, 1.0);
            glVertex3d(1.0, 1.0, 1.0);
            glColor3f(0.0, 0.5, 1.0);
            glVertex3d(1.0, 1.0, -1.0);
            glColor3f(0.0, 1.0, 1.0);
            glVertex3d(-1.0, -1.0, 1.0);
            //glVertex3d(-1.0, -1.0, -1.0);
            //glVertex3d(1.0, -1.0, 1.0);
            //glVertex3d(1.0, -1.0, -1.0);
        glEnd();
    glPopMatrix();
}

void draw()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glClearColor(1, 1, 1, 1.0f);
    glLoadIdentity();
    glRotatef(angle, 0.0, 1.0, 0.0);
    glRotated(0, 1, 0, 0);
    glPushMatrix();
    glBegin(GL_LINES);
        glColor3d(1.0, 0, 0);
        glVertex3d(-1.0, 0, 0);
        glVertex3d(1.0, 0, 0);
        glColor3d(0, 1, 0);
        glVertex3d(0, -1.0, 0);
        glVertex3d(0, 1, 0);
        glColor3d(0, 0, 1);
        glVertex3d(0, 0, -1);
        glVertex3d(0, 0, 1);
    glEnd();
    glPopMatrix();
    elephant(WIRED, frame, param);
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
