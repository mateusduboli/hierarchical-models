#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <GL/freeglut.h>

#include <stdio.h>
#include <stdbool.h>
#include "elephant.h"

const int GL_HEIGHT = 500;
const int GL_WIDTH  = GL_HEIGHT;
const int TIMER_INTERVAL = 50;
const double CAMERA_STEP = 1;

double camera_x = 0;
double camera_y = 0;

int window = 0;
int frame = 0;

void commandKeys(unsigned char key, int x, int y)
{
    switch(key) {
        case 'q':
            glutDestroyWindow(window);
            glutLeaveMainLoop();
            break;
        case 'w':
            walking();
            frame=0;
            break;
        case 'r':
            raising();
            frame=0;
            break;
    }
}

void movementKeys(int key, int x, int y)
{
    switch(key) {
        case GLUT_KEY_RIGHT:
            camera_x+=CAMERA_STEP;
            break;
        case GLUT_KEY_LEFT:
            camera_x-=CAMERA_STEP;
            break;
        case GLUT_KEY_UP:
            camera_y+=CAMERA_STEP;
            break;
        case GLUT_KEY_DOWN:
            camera_y-=CAMERA_STEP;
            break;
    }
}

void drawFloor()
{
    glPushMatrix();
        glTranslated(0, -ELEPHANT_HEIGHT, 0);
        glColor3d(0.0, 123.0/256, 12.0/256);
        glBegin(GL_QUADS);
            glVertex3d(-100, 0, -100);
            glVertex3d(-100, 0, 100);
            glVertex3d(100, 0, 100);
            glVertex3d(100, 0, -100);
        glEnd();
    glPopMatrix();
}

void initProjection()
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60, 1, 1, 1000);
}

void initLights()
{
    const GLfloat ambient[] =  {0, 0, 0, 1};
    const GLfloat diffuse[] =  {1, 1, 1, 1};
    const GLfloat position[] = {1, 1, 0};

    glLightfv(GL_LIGHT0, GL_AMBIENT, ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse);
    glLightfv(GL_LIGHT0, GL_POSITION, position);

    //glEnable(GL_LIGHTING);
    //glEnable(GL_LIGHT0);
    //glEnable(GL_COLOR_MATERIAL);
}

void draw()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glClearColor(0, 0, 0, 0.0f);

    glLoadIdentity();
    gluLookAt(0, 0, 2, 0, 0, 0, 0, 1, 0);
    glRotated(camera_x, 0, 1, 0);
    glRotated(camera_y, 1, 0, 0);

    drawFloor();
    elephant(frame);
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
    glEnable(GL_DEPTH_TEST);

    glHint(GL_POLYGON_SMOOTH_HINT, GL_NICEST);
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);

    initProjection();
    initLights();

    glutMainLoop();
    return 0;
}
