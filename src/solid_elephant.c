#include "solid_elephant.h"

void feet(int index, int frame, double param)
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

void thighs(int index, int frame, double param)
{
    glPushMatrix();
        glBegin(GL_LINES);
            glVertex3d(0.0, 0.0, 0.0);
            glVertex3d(0.0, -THIGHS_HEIGHT, 0.0);
        glEnd();
        glTranslatef(0.0, -THIGHS_HEIGHT, 0.0);
        glutSolidSphere(JOINT_SIZE, 30, 30);
        glRotatef(movementAngle(THIGHTS, index, frame), 0.0, 0.0, 1.0);
        feet(index, frame, param);
    glPopMatrix();
}

void shoulder(int index, int frame, double param)
{
    glPushMatrix();
        glBegin(GL_LINES);
            glVertex3d(0.0, 0.0, 0.0);
            glVertex3d(0.0, -SHOULDER_HEIGHT, 0.0);
        glEnd();
        glTranslatef(0.0, -SHOULDER_HEIGHT, 0.0);
        glutSolidSphere(JOINT_SIZE, 30, 30);
        glRotatef(movementAngle(SHOULDER, index, frame), 0.0, 0.0, 1.0);
        thighs(index, frame, param);
    glPopMatrix();
}

void trunk(int frame, double param)
{
    glPushMatrix();
        glBegin(GL_LINES);
            glVertex3d(0.0, 0.0, 0.0);
            glVertex3d(TRUNK_HEIGHT * 0.5, 0.0, 0.0);
        glEnd();
        glPushMatrix();
            glRotated(90, 0, 1, 0);
            glutSolidCylinder(JOINT_SIZE, TRUNK_HEIGHT * 0.5, 20, 20);
        glPopMatrix();
        glTranslatef(TRUNK_HEIGHT * 0.5 + JOINT_SIZE, 0.0, 0.0);
        glutSolidSphere(JOINT_SIZE, 30, 30);
        glTranslatef(JOINT_SIZE, 0.0, 0.0);
        glPushMatrix();
            glBegin(GL_LINES);
                glVertex3d(0.0, 0.0, 0.0);
                glVertex3d(TRUNK_HEIGHT * 0.5, 0.0, 0.0);
            glEnd();
            glPushMatrix();
                glRotated(90, 0, 1, 0);
                glutSolidCylinder(JOINT_SIZE, TRUNK_HEIGHT * 0.5, 20, 20);
            glPopMatrix();
            glTranslatef(TRUNK_HEIGHT * 0.5 + JOINT_SIZE, 0.0, 0.0);
            glutSolidSphere(JOINT_SIZE, 30, 30);
        glPopMatrix();
    glPopMatrix();
}
void head(int frame, double param)
{
    glPushMatrix();
        glRotated(-45, 0, 0, 1);
        glBegin(GL_LINES);
            glVertex3d(0.0, 0.0, 0.0);
            glVertex3d(HEAD_WIDTH, 0.0, 0.0);
        glEnd();
        glTranslated(HEAD_WIDTH, 0.0, 0.0);
        glutSolidSphere(HEAD_WIDTH, 30, 30);
        glTranslated(HEAD_WIDTH,0.0, 0.0);
        glRotated(-45, 0, 0, 1);
        glTranslated(JOINT_SIZE, 0.0, 0.0);
        glutSolidSphere(JOINT_SIZE, 30, 30);
        glTranslated(JOINT_SIZE, 0.0, 0.0);
        trunk(frame, param);
    glPopMatrix();
}

void tail(int frame, double param)
{
    glPushMatrix();
        glRotated(255, 0, 0, 1);
        glBegin(GL_LINES);
            glVertex3d(0.0, 0.0, 0.0);
            glVertex3d(TAIL_HEIGHT, 0.0, 0.0);
        glEnd();
        glPushMatrix();
            glRotated(90, 0, 1, 0);
            glutSolidCylinder(TAIL_WIDTH, TAIL_HEIGHT, 20, 20);
        glPopMatrix();
        glTranslated(TAIL_HEIGHT, 0.0, 0.0);
        glutSolidSphere(JOINT_SIZE, 30, 30);
    glPopMatrix();
}

void solid_elephant(int frame, double param)
{
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
        glColor3d(0.8, 0.8, 0.8);
        glBegin(GL_LINES);
            glVertex3d(TORSO_WIDTH * 0.5, TORSO_HEIGHT, 0.0);
            glVertex3d(-TORSO_WIDTH * 0.5, TORSO_HEIGHT, 0.0);
        glEnd();

        glPushMatrix();
            glTranslated(-TORSO_WIDTH * 0.5, TORSO_HEIGHT, 0.0);
            glScaled(1.0, 1.0, 7 * TORSO_DEPTH);
            glRotated(90, 0.0, 1.0, 0.0);
            glutSolidCylinder(TORSO_HEIGHT*0.5, TORSO_WIDTH, 20, 20);
        glPopMatrix();

        glPushMatrix();
            glTranslated(TORSO_WIDTH * 0.5 + JOINT_SIZE, NECK_HEIGHT, 0.0);
            glutSolidSphere(JOINT_SIZE, 10, 10);
            glTranslated(JOINT_SIZE, 0, 0);
            head(frame, param);
        glPopMatrix();
        glPushMatrix();
            glTranslated(-TORSO_WIDTH * 0.5 - JOINT_SIZE, TORSO_HEIGHT -JOINT_SIZE, 0.0);
            glutSolidSphere(JOINT_SIZE, 30, 30);
            tail(frame, param);
        glPopMatrix();
        for(int i = 0; i < 4; i++) {
            glPushMatrix();
                int a = pow(-1, i);
                int b = pow(-1, floor(i/2));
                glTranslatef(a*TORSO_WIDTH * 0.5, TORSO_HEIGHT, b*TORSO_DEPTH);
                shoulder(i,frame, param);
            glPopMatrix();
        }
    glPopMatrix();
}
