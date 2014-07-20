#include "wire_elephant.h"

int _frame = 0;

void wire_feet(int index, double param)
{
    glPushMatrix();
        glBegin(GL_LINES);
            glVertex3d(0.0, 0.0, 0.0);
            glVertex3d(0.0, -FEET_HEIGHT, 0.0);
        glEnd();
        glTranslatef(0.0, -FEET_HEIGHT, 0.0);
        glutSolidSphere(JOINT_SIZE, 30, 30);
    glPopMatrix();
}

void wire_thighs(int index, double param)
{
    glPushMatrix();
        glBegin(GL_LINES);
            glVertex3d(0.0, 0.0, 0.0);
            glVertex3d(0.0, -THIGHS_HEIGHT, 0.0);
        glEnd();
        glTranslatef(0.0, -THIGHS_HEIGHT, 0.0);
        glutSolidSphere(JOINT_SIZE, 30, 30);
        wire_feet(index, param);
    glPopMatrix();
}

void wire_shoulder(int index, double param)
{
    glPushMatrix();
        double displac = displacement(SHOULDER, index, _frame);
        glBegin(GL_LINES);
            glVertex3d(0.0, 0.0, 0.0);
            glVertex3d(0.0, -SHOULDER_HEIGHT-displac, 0.0);
        glEnd();
        glTranslatef(0.0, -SHOULDER_HEIGHT-displac, 0.0);
        glutSolidSphere(JOINT_SIZE, 30, 30);
        wire_thighs(index, param);
    glPopMatrix();
}

void wire_trunk(double param)
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
void wire_head(double param)
{
    glPushMatrix();
        glBegin(GL_LINES);
            glVertex3d(0.0, 0.0, 0.0);
            glVertex3d(HEAD_WIDTH/2, -HEAD_WIDTH/2, 0.0);
        glEnd();
        glTranslatef(HEAD_WIDTH/2, -HEAD_WIDTH/2, 0.0);
        glutSolidSphere(JOINT_SIZE, 30, 30);
        wire_trunk(param);
    glPopMatrix();
}

void wire_tail(double param)
{
    glPushMatrix();
        glBegin(GL_LINES);
            glVertex3d(0.0, 0.0, 0.0);
            glVertex3d(-TAIL_WIDTH, -TAIL_HEIGHT, 0.0);
        glEnd();
        glTranslatef(-TAIL_WIDTH, -TAIL_HEIGHT, 0.0);
        glutSolidSphere(JOINT_SIZE, 30, 30);
    glPopMatrix();
}

void wire_elephant(int frame, double param)
{
    _frame = frame;
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
        glColor3f(1.0, 0.0, 0.0);
        glBegin(GL_LINES);
            glVertex3d(TORSO_WIDTH, TORSO_HEIGHT, 0.0);
            glVertex3d(-TORSO_WIDTH, TORSO_HEIGHT, 0.0);
        glEnd();
        glPushMatrix();
            glTranslatef(TORSO_WIDTH, TORSO_HEIGHT, 0.0);
            glutSolidSphere(JOINT_SIZE, 30, 30);
            wire_head(param);
        glPopMatrix();
        glPushMatrix();
            glTranslatef(-TORSO_WIDTH, TORSO_HEIGHT, 0.0);
            glutSolidSphere(JOINT_SIZE, 30, 30);
            wire_tail(param);
        glPopMatrix();
        for(int i = 0; i < 4; i++) {
            glPushMatrix();
                int a = pow(-1, i);
                int b = pow(-1, floor(i/2));
                glTranslatef(a*TORSO_WIDTH, TORSO_HEIGHT, b*TORSO_DEPTH);
                wire_shoulder(i, param);
            glPopMatrix();
        }
    glPopMatrix();
}
