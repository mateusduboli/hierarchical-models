#include <GL/gl.h>
#include <GL/glut.h>

#include <stdio.h>

double a = 0.0;
double s = 0.0;
double d = 0.0;

const double STEP = 0.05;

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(a, s, d,0.0,0.0,0.0,0.0,1.0,0.0);

    glPushMatrix();
        glPushMatrix();
            glTranslated(0, 0, -3);
            glutWireTeapot(1);
            glTranslated(0, 2, 0);
            glutSolidTeapot(1);
        glPopMatrix();
        glTranslated(0, -2, -1);
        glutSolidTeapot(1);
    glPopMatrix();

    glFlush();
}

void reshape(int width, int heigth)
{
    glViewport(0, 0, width, heigth);
}

void keyboard(unsigned char key, int x, int y)
{
    switch(key) {
        case 'a':
            a+=STEP;
            break;
        case 'A':
            a-=STEP;
            break;
        case 'd':
            d+=STEP;
            break;
        case 'D':
            d-=STEP;
            break;
        case 's':
            s+=STEP;
            break;
        case 'S':
            s-=STEP;
            break;
    }

    glutPostRedisplay();

    printf("Key %c : a %f : s %f : d %f \n", key, a, s, d);
}


int main(int argc, char** argv)
{
    glutInit(&argc, argv);

    glutInitWindowSize(500, 500);
    glutInitWindowPosition(0, 0);
    glutInitDisplayMode(GLUT_RGB);

    glutCreateWindow("Hello Teapot");
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60, 1, 1, 10);

    glutMainLoop();

    return 0;
}
