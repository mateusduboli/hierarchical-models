#include "wire_elephant.h"

int _frame = 0;

void feet(int index, double param)
{
    int a = pow(-1, index);
    int b = pow(-1, floor(index/2));
    glPushMatrix();
        glBegin(GL_LINES);
            glVertex3d(0.0, 0.0, 0.0);
            glVertex3d(0.0, -FEET_HEIGHT, 0.0);
        glEnd();
        glTranslatef(0.0, -FEET_HEIGHT, 0.0);
        glutSolidSphere(JOINT_SIZE, 30, 30);
    glPopMatrix();
}

void thighs(int index, double param)
{
    int a = pow(-1, index);
    int b = pow(-1, floor(index/2));
    glPushMatrix();
        glBegin(GL_LINES);
            glVertex3d(0.0, 0.0, 0.0);
            glVertex3d(0.0, -THIGHS_HEIGHT, 0.0);
        glEnd();
        glTranslatef(0.0, -THIGHS_HEIGHT, 0.0);
        glutSolidSphere(JOINT_SIZE, 30, 30);
        feet(index, param);
    glPopMatrix();
}

void shoulder(int index, double param)
{
    int a = pow(-1, index);
    int b = pow(-1, floor(index/2));
    glPushMatrix();
        glBegin(GL_LINES);
            glVertex3d(a*TORSO_WIDTH, TORSO_HEIGHT, 0.0);
            glVertex3d(a*TORSO_WIDTH, 0.0, b*TORSO_DEPTH);
        glEnd();
        glTranslatef(a*TORSO_WIDTH, 0.0, b*TORSO_DEPTH);
        glutSolidSphere(JOINT_SIZE, 30, 30);
        glRotatef(movementAngle(SHOULDER, index, _frame), 0.0, 0.0, 1.0);
        thighs(index, param);
    glPopMatrix();
}

void trunk(double param)
{
    glPushMatrix();
        glBegin(GL_LINES);
            glVertex3d(0.0, 0.0, 0.0);
            glVertex3d(0.0, -TRUNK_HEIGHT/2, 0.0);
        glEnd();
        glTranslatef(0.0, -TRUNK_HEIGHT/2, 0.0);
        glutSolidSphere(JOINT_SIZE, 30, 30);
        glPushMatrix();
            glBegin(GL_LINES);
                glVertex3d(0.0, 0.0, 0.0);
                glVertex3d(0.0, -TRUNK_HEIGHT/2, 0.0);
            glEnd();
            glTranslatef(0.0, -TRUNK_HEIGHT/2, 0.0);
            glutSolidSphere(JOINT_SIZE, 30, 30);
        glPopMatrix();
    glPopMatrix();
}
void head(double param)
{
    glPushMatrix();
        glTranslatef(TORSO_WIDTH, TORSO_HEIGHT, 0.0);
        glBegin(GL_LINES);
            glVertex3d(0.0, 0.0, 0.0);
            glVertex3d(HEAD_WIDTH/2, -HEAD_WIDTH/2, 0.0);
        glEnd();
        glTranslatef(HEAD_WIDTH/2, -HEAD_WIDTH/2, 0.0);
        glutSolidSphere(JOINT_SIZE, 30, 30);
        trunk(param);
    glPopMatrix();
}

void tail(double param)
{
    glPushMatrix();
        glTranslatef(-TORSO_WIDTH, TORSO_HEIGHT, 0.0);
        glBegin(GL_LINES);
            glVertex3d(0.0, 0.0, 0.0);
            glVertex3d(-TAIL_WIDTH, -TAIL_HEIGHT, 0.0);
        glEnd();
        glTranslatef(-TAIL_WIDTH, -TAIL_HEIGHT, 0.0);
        glutSolidSphere(JOINT_SIZE, 30, 30);
    glPopMatrix();
}

void elephant(int frame, double param)
{
    _frame = frame;
    glMatrixMode(GL_MODELVIEW);
    glColor3f(0.0, 1.0, 0.0);
    glPushMatrix();
        glTranslatef(TORSO_WIDTH, TORSO_HEIGHT, 0.0);
        glutSolidSphere(JOINT_SIZE, 30, 30);
    glPopMatrix();
    glPushMatrix();
        glTranslatef(-TORSO_WIDTH, TORSO_HEIGHT, 0.0);
        glutSolidSphere(JOINT_SIZE, 30, 30);
    glPopMatrix();
    glBegin(GL_LINES);
        glVertex3d(TORSO_WIDTH, TORSO_HEIGHT, 0.0);
        glVertex3d(-TORSO_WIDTH, TORSO_HEIGHT, 0.0);
    glEnd();
    for(int i = 0; i < 4; i++)
        shoulder(i, param);
    head(param);
    tail(param);
}
