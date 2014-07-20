#include "solid_elephant.h"

void feet(Side side, int frame, double param)
{
    glPushMatrix();
        glBegin(GL_LINES);
            glVertex3d(0.0, 0.0, 0.0);
            glVertex3d(0.0, -FEET_HEIGHT, 0.0);
        glEnd();
        glPushMatrix();
            glRotated(90, 0, 0, 0);
            glutSolidCylinder(JOINT_SIZE, FEET_HEIGHT, 20, 20);
        glPopMatrix();
    glPopMatrix();
}

void knee(Side side, int frame, double param)
{
    glPushMatrix();
        glBegin(GL_LINES);
            glVertex3d(0.0, 0.0, 0.0);
            glVertex3d(0.0, -KNEE_HEIGHT, 0.0);
        glEnd();
        glPushMatrix();
            glRotated(90, 0, 0, 0);
            glutSolidCylinder(JOINT_SIZE, KNEE_HEIGHT, 20, 20);
        glPopMatrix();
        glTranslatef(0.0, -KNEE_HEIGHT - JOINT_SIZE, 0.0);
        glutSolidSphere(JOINT_SIZE, 30, 30);
        glTranslated(0.0, -JOINT_SIZE, 0.0);
        glRotated(movement(KNEE, side, frame), 0, 0, 1);
        feet(side, frame, param);
    glPopMatrix();
}

void hips(Side side, int frame, double param)
{
    glBegin(GL_LINES);
        glVertex3d(0.0, 0, TORSO_DEPTH);
        glVertex3d(0.0, -HIPS_HEIGHT, 0.0);
    glEnd();
    glPushMatrix();
        glTranslatef(0.0, -HIPS_HEIGHT -JOINT_SIZE, 0.0);
        glutSolidSphere(JOINT_SIZE, 30, 30);
        glTranslatef(0.0, -JOINT_SIZE, 0.0);
        glRotated(movement(HIPS, side, frame), 0, 0, 1);
        knee(side, frame, param);
    glPopMatrix();
}

void hands(Side side, int frame, double param)
{
    glPushMatrix();
        glBegin(GL_LINES);
            glVertex3d(0.0, 0.0, 0.0);
            glVertex3d(0.0, -HAND_HEIGHT, 0.0);
        glEnd();
        glPushMatrix();
            glRotated(90, 0, 0, 0);
            glutSolidCylinder(JOINT_SIZE, HAND_HEIGHT, 20, 20);
        glPopMatrix();
    glPopMatrix();
}

void wrist(Side side, int frame, double param)
{
    glPushMatrix();
        glBegin(GL_LINES);
            glVertex3d(0.0, 0.0, 0.0);
            glVertex3d(0.0, -WRIST_HEIGHT, 0.0);
        glEnd();
        glPushMatrix();
            glRotated(90, 0, 0, 0);
            glutSolidCylinder(JOINT_SIZE, WRIST_HEIGHT, 20, 20);
        glPopMatrix();
        glTranslatef(0.0, -WRIST_HEIGHT -JOINT_SIZE, 0.0);
        glutSolidSphere(JOINT_SIZE, 30, 30);
        glTranslatef(0.0, -JOINT_SIZE, 0.0);
        glRotated(movement(WRIST, side, frame), 0, 0, 1);
        hands(side, frame, param);
    glPopMatrix();
}

void elbow(Side side, int frame, double param)
{
    glPushMatrix();
        glBegin(GL_LINES);
            glVertex3d(0.0, 0.0, 0.0);
            glVertex3d(0.0, -ELBOW_HEIGHT, 0.0);
        glEnd();
        glPushMatrix();
            glRotated(90, 0, 0, 0);
            glutSolidCylinder(JOINT_SIZE, ELBOW_HEIGHT, 20, 20);
        glPopMatrix();
        glTranslatef(0.0, -ELBOW_HEIGHT -JOINT_SIZE, 0.0);
        glutSolidSphere(JOINT_SIZE, 30, 30);
        glTranslatef(0.0, -JOINT_SIZE, 0.0);
        glRotated(movement(ELBOW, side, frame), 0, 0, 1);
        wrist(side, frame, param);
    glPopMatrix();
}


void shoulder(Side side, int frame, double param)
{
    glPushMatrix();
        glTranslatef(0.0, -SHOULDER_HEIGHT -JOINT_SIZE, 0.0);
        glutSolidSphere(JOINT_SIZE, 30, 30);
        glTranslatef(0.0, -JOINT_SIZE, 0.0);
        glRotated(movement(SHOULDER, side, frame), 0, 0, 1);
        elbow(side, frame, param);
    glPopMatrix();
}

void trunk(int frame, double param)
{
    glPushMatrix();
        glRotated(movement(TRUNK, 0, frame), 0, 0, 1);
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
            glRotated(movement(TRUNK, 1, frame), 0, 0, 1);
            glBegin(GL_LINES);
                glVertex3d(0.0, 0.0, 0.0);
                glVertex3d(TRUNK_HEIGHT * 0.5, 0.0, 0.0);
            glEnd();
            glPushMatrix();
                glRotated(90, 0, 1, 0);
                glutSolidCylinder(JOINT_SIZE, TRUNK_HEIGHT * 0.5, 20, 20);
            glPopMatrix();
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
        glRotated(movement(TAIL, 0, frame), 0, 0, 1);
        glRotated(255, 0, 0, 1);
        glBegin(GL_LINES);
            glVertex3d(0.0, 0.0, 0.0);
            glVertex3d(TAIL_HEIGHT, 0.0, 0.0);
        glEnd();
        glPushMatrix();
            glRotated(90, 0, 1, 0);
            glutSolidCylinder(TAIL_WIDTH, TAIL_HEIGHT, 20, 20);
        glPopMatrix();
    glPopMatrix();
}

void solid_elephant(int frame, double param)
{
    glColor3d(0.8, 0.8, 0.8);
    glPushMatrix();
        glBegin(GL_LINES);
            glVertex3d(TORSO_WIDTH * 0.5, TORSO_HEIGHT, 0.0);
            glVertex3d(-TORSO_WIDTH * 0.5, TORSO_HEIGHT, 0.0);
        glEnd();

        glPushMatrix();
            glTranslated(-TORSO_WIDTH * 0.5, TORSO_HEIGHT * 0.5, 0.0);
            glScaled(1.0, 1.0, 0.9); //Proportion between depth and Width
            glRotated(90, 0.0, 1.0, 0.0);
            glutSolidCylinder(TORSO_HEIGHT, TORSO_WIDTH, 10, 10);
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
        glPushMatrix();
            glTranslated(SHOULDER_X, TORSO_HEIGHT, TORSO_DEPTH);
            glBegin(GL_LINES);
                glVertex3d(0.0, 0, -TORSO_DEPTH);
                glVertex3d(0.0, -SHOULDER_HEIGHT, 0.0);
            glEnd();
            shoulder(RIGHT, frame, param);
        glPopMatrix();
        glPushMatrix();
            glTranslated(SHOULDER_X, TORSO_HEIGHT, -TORSO_DEPTH);
            glBegin(GL_LINES);
                glVertex3d(0.0, 0, TORSO_DEPTH);
                glVertex3d(0.0, -SHOULDER_HEIGHT, 0.0);
            glEnd();
            shoulder(LEFT, frame, param);
        glPopMatrix();
        glPushMatrix();
            glTranslated(HIPS_X, TORSO_HEIGHT, TORSO_DEPTH);
            glBegin(GL_LINES);
                glVertex3d(0.0, 0, -TORSO_DEPTH);
                glVertex3d(0.0, -HIPS_HEIGHT, 0.0);
            glEnd();
            hips(RIGHT, frame, param);
        glPopMatrix();
        glPushMatrix();
            glTranslated(HIPS_X, TORSO_HEIGHT, -TORSO_DEPTH);
            hips(LEFT, frame, param);
        glPopMatrix();
    glPopMatrix();
}
