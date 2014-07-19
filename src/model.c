#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <GL/freeglut.h>

#include <stdio.h>
#include <stdbool.h>
#include "elephant.h"

const int GL_HEIGHT = 500;
const int GL_WIDTH  = GL_HEIGHT;
const int TIMER_INTERVAL = 100;
const int ANGLE_STEP = 2;

int window = 0;
int angle = 0;
int ver_angle = 0;
int frame = 0;
bool isWired = false;

double param = 0.1;

void commandKeys(unsigned char key, int x, int y)
{
    switch(key) {
        case 'q':
            glutDestroyWindow(window);
            glutLeaveMainLoop();
            break;
        case 's':
            isWired = !isWired;
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
            angle+=ANGLE_STEP;
            angle%=360;
            break;
        case GLUT_KEY_LEFT:
            angle-=ANGLE_STEP;
            angle%=360;
            break;
        case GLUT_KEY_UP:
            ver_angle+=ANGLE_STEP;
            ver_angle%=360;
            break;
        case GLUT_KEY_DOWN:
            ver_angle-=ANGLE_STEP;
            ver_angle%=360;
            break;
    }
    printf("H: %i deg\n", angle);
}

void drawFloor()
{
    glPushMatrix();
        glTranslated(0.0, -ELEPHANT_HEIGHT, 0.0);
        glColor3d(0, 1, 0);
        glScaled(2.0, 1, 2.0);
        glutSolidCube(1.0);
    glPopMatrix();
}

void initProjection()
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(6, 6, 6, 6, 6, 6);
}

void initLights()
{
    const GLfloat ambient[] =  {0, 0, 0, 1};
    const GLfloat diffuse[] =  {1, 1, 1, 1};
    const GLfloat position[] = {1, 1, 0};

    glLightfv(GL_LIGHT0, GL_AMBIENT, ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse);
    glLightfv(GL_LIGHT0, GL_POSITION, position);

    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_COLOR_MATERIAL);
}

void drawAxis()
{
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
}

void draw()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glClearColor(1, 1, 1, 1.0f);
    glLoadIdentity();
    glRotated(angle, 0.0, 1.0, 0.0);
    glRotated(ver_angle, 0.0, .0, 1.0);
    drawAxis();
    drawFloor();
    elephant(isWired, frame, param);
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
    glHint(GL_POLYGON_SMOOTH_HINT, GL_NICEST);
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);

    initProjection();
    initLights();

    glutMainLoop();
    return 0;
}
