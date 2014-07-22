#include "elephant.h"

void feet(Side side, int frame)
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

void knee(Side side, int frame)
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
        glRotated(movement(KNEE, side, frame), 0, 0, 1);
        glutSolidSphere(JOINT_SIZE, 30, 30);
        glTranslated(0.0, -JOINT_SIZE, 0.0);
        feet(side, frame);
    glPopMatrix();
}

void hips(Side side, int frame)
{
    glPushMatrix();
        glTranslatef(0.0, -HIPS_HEIGHT -JOINT_SIZE, 0.0);
        glRotated(movement(HIPS, side, frame), 0, 0, 1);
        glutSolidSphere(JOINT_SIZE, 30, 30);
        glTranslatef(0.0, -JOINT_SIZE, 0.0);
        knee(side, frame);
    glPopMatrix();
}

void hands(Side side, int frame)
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

void wrist(Side side, int frame)
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
        glRotated(movement(WRIST, side, frame), 0, 0, 1);
        glutSolidSphere(JOINT_SIZE, 30, 30);
        glTranslatef(0.0, -JOINT_SIZE, 0.0);
        hands(side, frame);
    glPopMatrix();
}

void elbow(Side side, int frame)
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
        glRotated(movement(ELBOW, side, frame), 0, 0, 1);
        glutSolidSphere(JOINT_SIZE, 30, 30);
        glTranslatef(0.0, -JOINT_SIZE, 0.0);
        wrist(side, frame);
    glPopMatrix();
}


void shoulder(Side side, int frame)
{
    glPushMatrix();
        glTranslatef(0.0, -SHOULDER_HEIGHT -JOINT_SIZE, 0.0);
        glRotated(movement(SHOULDER, side, frame), 0, 0, 1);
        glutSolidSphere(JOINT_SIZE, 30, 30);
        glTranslatef(0.0, -JOINT_SIZE, 0.0);
        elbow(side, frame);
    glPopMatrix();
}

void trunk(int frame)
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
        glRotated(movement(TRUNK, 1, frame), 0, 0, 1);
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
        glPopMatrix();
    glPopMatrix();
}

void head(int frame)
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
        glRotated(movement(TRUNK, 0, frame), 0, 0, 1);
        glutSolidSphere(JOINT_SIZE, 30, 30);
        glTranslated(JOINT_SIZE, 0.0, 0.0);
        trunk(frame);
    glPopMatrix();
}

void tail(int frame)
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
    glPopMatrix();
}

void elephant(int frame)
{
    glColor3d(0.6, 0.6, 0.6);
    glPushMatrix();
        double angle = movement(TORSO, 0, frame);
        double displ_y = sin(DEGREES(angle))*TORSO_HEIGHT;
        double displ_x = cos(DEGREES((90 + angle)))*TORSO_HEIGHT;
        glTranslated(displ_x, displ_y, 0);
        glRotated(angle, 0, 0, 1);
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
            glRotated(movement(HEAD, 0, frame), 0, 0, 1);
            glutSolidSphere(JOINT_SIZE, 10, 10);
            glTranslated(JOINT_SIZE, 0, 0);
            head(frame);
        glPopMatrix();
        glPushMatrix();
            glTranslated(-TORSO_WIDTH * 0.5 - JOINT_SIZE, TORSO_HEIGHT -JOINT_SIZE, 0.0);
            glRotated(movement(TAIL, 0, frame), 0, 0, 1);
            glutSolidSphere(JOINT_SIZE, 30, 30);
            tail(frame);
        glPopMatrix();
        glPushMatrix();
            glTranslated(SHOULDER_X, TORSO_HEIGHT, TORSO_DEPTH);
            glBegin(GL_LINES);
                glVertex3d(0.0, 0, -TORSO_DEPTH);
                glVertex3d(0.0, -SHOULDER_HEIGHT, 0.0);
            glEnd();
            shoulder(RIGHT, frame);
        glPopMatrix();
        glPushMatrix();
            glTranslated(SHOULDER_X, TORSO_HEIGHT, -TORSO_DEPTH);
            glBegin(GL_LINES);
                glVertex3d(0.0, 0, TORSO_DEPTH);
                glVertex3d(0.0, -SHOULDER_HEIGHT, 0.0);
            glEnd();
            shoulder(LEFT, frame);
        glPopMatrix();
        glPushMatrix();
            glTranslated(HIPS_X, TORSO_HEIGHT, TORSO_DEPTH);
            glBegin(GL_LINES);
                glVertex3d(0.0, 0, -TORSO_DEPTH);
                glVertex3d(0.0, -HIPS_HEIGHT, 0.0);
            glEnd();
            hips(RIGHT, frame);
        glPopMatrix();
        glPushMatrix();
            glTranslated(HIPS_X, TORSO_HEIGHT, -TORSO_DEPTH);
            glBegin(GL_LINES);
                glVertex3d(0.0, 0, TORSO_DEPTH);
                glVertex3d(0.0, -HIPS_HEIGHT, 0.0);
            glEnd();
            hips(LEFT, frame);
        glPopMatrix();
    glPopMatrix();
}
