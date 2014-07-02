
#include "model.h"

GLfloat diffuse[] = {1.0, 1.0, 1.0, 1.0};
GLfloat ambient[] = {1.0, 1.0, 1.0, 0.1};
GLfloat position[] = {0.0, 2.0, 0.0, 0.0};

void repaint(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT) ;
	frame++;
	Cow();
	glutSwapBuffers() ;
}

void keyboard (unsigned char key, int x, int y)
{
	switch (key)
	{
		case '1' :
			if(SMOOTH == 1){
				SMOOTH = 0;
				glShadeModel(GL_FLAT) ;
			}else{
				SMOOTH = 1;
				glShadeModel(GL_SMOOTH) ;
			}
			break ;
		case '2':
			if(WIRED == 1)
				WIRED = 0;
			else
				WIRED = 1;
			break;
		case 'w':
			break;
		case 'a':
				rotateAngle += 10;
			break;
		case 'd':
				rotateAngle -=10;
			break;
		case ' ':
				WALKING = !WALKING;
				break;
		case 'f':
				posicao-=0.1/SCALE;
			break;
		case 't':
				posicao+=0.1/SCALE;
			break;
		case 'v':
				fly=!fly;
			break;
		default :
			break ;
	}
	glutPostRedisplay() ;
}

void init()
{

	glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB) ;
	glutInitWindowSize (1000, 1000) ;
	glutInitWindowPosition (1000, 500) ;
	glutCreateWindow ("Modelos Hierarquicos - Vaca. Andre e Leonardo") ;
	glClearColor( 0.5, 0.5, 1.0,1.0 ) ;

    glViewport(0, 0, (GLsizei) 1000, (GLsizei) 1000);
    glMatrixMode (GL_PROJECTION);
    glLoadIdentity();

    gluPerspective((GLdouble)40.0, (GLdouble) 1.0, (GLdouble)1.0, (GLdouble)100.0);

    glMatrixMode(GL_MODELVIEW);
    glTranslatef(0.0, 0., -3.0);

    glShadeModel(GL_SMOOTH);

    glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse);
    glLightfv(GL_LIGHT0, GL_AMBIENT, ambient);
    glLightfv(GL_LIGHT0, GL_POSITION, position);
    glEnable(GL_LIGHT0);
    glEnable(GL_LIGHTING);
    glEnable(GL_DEPTH_TEST);

	glutDisplayFunc(&repaint);
	glutIdleFunc(&repaint);
	glutKeyboardFunc(&keyboard);
	glutMainLoop () ;
}


int main(int argc, char** argv)
{
	glutInit (&argc, argv) ;
	init() ;
	return 0 ;
}
