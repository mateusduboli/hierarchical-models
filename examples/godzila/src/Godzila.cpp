/*Modelo de um Lagarto Humanóide
* Grupo:
*	Victor Simas Silva - 98132377
*   Aldo Menezes Daquino Neto - 97232009
*   Brian Schmitz Tani - 98132512
* UFSC 2002
*/

#include <stdlib.h>	
#include "math.h"
#include <stdio.h>	
#include <GL/glut.h>

#include "Godzila.h"
							
#define ESCAPE	27

//Variáveis Globais
int		window;	
int		Width;	
int		Height;	
int		angle = 0;
int		frames = FRAMES_CAMINHADA;		
int		frame_atual = 0;
int		prox_frame = 0;
float	deslocamento = 0;
float	angulo_objeto = 0;
float   qtd_deslocamento = DESLOC_CAMINHADA;
int		MVNT = CAMINHADA;
bool    Wireframe = true;
GLfloat x_ant = 0;
GLfloat y_ant = 0;
GLfloat z_ant = -550;
bool    ortogonal=false;	// Indica se escolhemos uma projecao ortogonal ou em perspectiva.
int		segmentos = SEG_CAMINHADA;

//Diferentes Vetores de Luz
GLfloat			diffuseLight[] = { 0.5f, 0.5f, 0.5f, 1.0};
GLfloat			ambientLight[] = { 0.5f, 0.5f, 0.5f, 0.7};
GLfloat			emissiveLight[] = { 1.0f, 1.0f, 1.0f, 1.0};
GLfloat			lightPos[] = { 300.0f, 300.0f, 300.0f, 0.0f };
GLfloat			mat_spec[] = { 0.8f, 0.2f, 0.2f, 1.0};
GLfloat			mat_diff[] = { 0.8f, 0.2f, 0.2f, 1.0};
GLfloat			mat_shin[] = { 10.0f};
 


void desenhaBracoInteiro(int Lado)
{
	GLUquadricObj	*obj;

	if (Lado==ESQUERDA) Lado = BRACO_ESQUERDO;

	if (Lado!=BRACO_ESQUERDO)
	{
		glTranslatef(0.0f, 0.0f, 30);
		glRotatef(20, 1.0f, 0.0f, 0.0f);
	}
	else
	{
		glTranslatef(0.0f, 0.0f, -30);
		glRotatef(-20, 1.0f, 0.0f, 0.0f);		
	}
//<--     Ombro + Braço
	glRotatef(movimentacao[BRACO+MVNT+Lado+Z], 0.0f, 0.0f, 1.0f);
	glRotatef(movimentacao[BRACO+MVNT+Lado+X], 1.0f, 0.0f, 0.0f);
	glRotatef(movimentacao[BRACO+MVNT+Lado+Y], 0.0f, 1.0f, 0.0f);
	glPushMatrix();
		//Ombro
		if (Wireframe) 
			glutWireSphere(15, 10, 10);
		else
			glutSolidSphere(15, 10, 10);
	glPopMatrix();
	
	glTranslatef(0.0f, 30.0f, 0.0f);

	glPushMatrix();
		//Braço
		if (Wireframe) 
		{	
			glScalef(25.0f, 35.0f, 20.0f);
			glutWireCube(1.0);
		}
		else
		{
			obj = gluNewQuadric();
			glTranslatef(0.0f, 20.0f, 0.0f);
			glRotatef(90,1,0,0);
			gluCylinder(obj,10,15,50,20,20);
		}
	glPopMatrix();	

	glTranslatef(0.0f, 25.5f, 0.0f);
	if (Lado!=BRACO_ESQUERDO)
		glRotatef(-15, 1.0f, 0.0f, 0.0f);				
	else
		glRotatef(15, 1.0f, 0.0f, 0.0f);

//-->
//<--	  Cotovelo + Antebraço
	glRotatef(movimentacao[ANTEBRACO+MVNT+Lado+Z], 0.0f, 0.0f, 1.0f);
	glRotatef(movimentacao[ANTEBRACO+MVNT+Lado+X], 1.0f, 0.0f, 0.0f);
	glRotatef(movimentacao[ANTEBRACO+MVNT+Lado+Y], 0.0f, 1.0f, 0.0f);
	glPushMatrix();
		//Cotovelo
		if (Wireframe) 
			glutWireSphere(10, 10, 10);
		else
			glutSolidSphere(10, 10, 10);
	glPopMatrix();
	glTranslatef(0.0f, 25.0f, 0.0f);

	glPushMatrix();
		//Antebraco

		if (Wireframe) 
		{	
			glScalef(18.0f, 35.0f, 17.0f);
			glutWireCube(1.0);
		}
		else
		{
			obj = gluNewQuadric();
			glTranslatef(0.0f, 20.0f, 0.0f);
			glRotatef(90,1,0,0);
			glScalef(1.0,0.7,1.0);
			gluCylinder(obj,8,10,40,20,20);
		}
	glPopMatrix();

	glTranslatef(0.0f, 22.0f, 0.0f);
//-->

//<--	  Mão + Punho + Garras
	glRotatef(movimentacao[MAO+MVNT+Lado+Z], 0.0f, 0.0f, 1.0f);
	glRotatef(movimentacao[MAO+MVNT+Lado+X], 1.0f, 0.0f, 0.0f);
	glRotatef(movimentacao[MAO+MVNT+Lado+Y], 0.0f, 1.0f, 0.0f);
	if (Lado!=BRACO_ESQUERDO)
	{
		glRotatef(-5, 1.0f, 0.0f, 0.0f);
		glRotatef(50, 0.0f, 1.0f, 0.0f);
	}
	else
	{
		glRotatef(5, 1.0f, 0.0f, 0.0f);
		glRotatef(-50, 0.0f, 1.0f, 0.0f);
	}
	glPushMatrix();
		//Punho
		if (Wireframe) 
			glutWireSphere(7, 10, 10);
		else
			glutSolidSphere(7, 10, 10);
	glPopMatrix();
	
	glTranslatef(0.0f, 17.0f, 0.0f);

	glPushMatrix();
		//Mão
		if (Wireframe) 
		{	
			glScalef(15.0f, 15.0f, 10.0f);
			glutWireCube(1.0);
		}
		else
		{
			obj = gluNewQuadric();
			glTranslatef(0.0f,8.0f, 0.0f);
			glRotatef(90,1,0,0);

			glScalef(1.2,0.5,1.0);
			gluCylinder(obj,10,8,20,20,20);
		}
	glPopMatrix();
		//Garras
	glPushMatrix();
		//Dedo Indicador
		if (Lado!=BRACO_ESQUERDO)
		{
			glRotatef(-121,1.0,0.0,0.0);
			glTranslatef(7.0f, -6.0f, 7.0f);
			glRotatef(10, 0.0, 1.0 , 0.0);	
		}
		else
		{
			glRotatef(-59,1.0,0.0,0.0);
			glTranslatef(7.0f, 6.0f, 7.0f);
			glRotatef(10, 0.0, 1.0 , 0.0);	
		}
		if (Wireframe) 
			glutWireCone(3,18,10,10);
		else
			glutSolidCone(3,18,10,10);		
	glPopMatrix();
	glPushMatrix();
		//Dedo Médio
		if (Lado!=BRACO_ESQUERDO)
		{
			glRotatef(-105,1.0,0.0,0.0);
			glTranslatef(3.5f, -6.0f, 7.0f);
			glRotatef(6, 0.0, 1.0 , 0.0);
		}
		else
		{
			glRotatef(-75,1.0,0.0,0.0);
			glTranslatef(3.5f, 6.0f, 7.0f);
			glRotatef(6, 0.0, 1.0 , 0.0);	
		}
		if (Wireframe) 
			glutWireCone(3,22,10,10);
		else
			glutSolidCone(3,22,10,10);		
	glPopMatrix();
	glPushMatrix();
		//Dedo Anelar
		if (Lado!=BRACO_ESQUERDO)
		{
	
			glRotatef(-120,1.0,0.0,0.0);
			glTranslatef(0.0f, -6.0f, 7.0f);

		}
		else
		{
			glRotatef(-60,1.0,0.0,0.0);
			glTranslatef(0.0f, 6.0f, 7.0f);
		}
		if (Wireframe) 
			glutWireCone(3,20,10,10);
		else
			glutSolidCone(3,20,10,10);		
	glPopMatrix();
	glPushMatrix();
		//Dedo Mindinho
		if (Lado!=BRACO_ESQUERDO)
		{
			glRotatef(-130,1.0,0.0,0.0);
			glTranslatef(-3.5f, -6.0f, 7.0f);
			glRotatef(0, 0.0, 1.0 , 0.0);

		}
		else
		{
			glRotatef(-50,1.0,0.0,0.0);
			glTranslatef(-3.5f, 6.0f, 7.0f);
			glRotatef(0, 0.0, 1.0 , 0.0);	
		}
		if (Wireframe) 
			glutWireCone(3,16,10,10);
		else
			glutSolidCone(3,16,10,10);		
	glPopMatrix();
	glPushMatrix();
		//Dedo Polegar
		glRotatef(20, 0.0, 1.0 , 0.0);
		if (Lado!=BRACO_ESQUERDO)
		{
			glTranslatef(6.0f, -5.0f, 0.0f);
			glRotatef(-120, 0, -1.0 , 0.0);	
			glRotatef(-30, 1, 0.0 , 0.0);

		}
		else
		{
			glTranslatef(6.0f, -5.0f, 0.0f);
			glRotatef(-20, 0, -1.0 , 0.0);	
			glRotatef(-30, 1, 0.0 , 0.0);	
		}

		if (Wireframe) 
			glutWireCone(3,18,10,10);
		else
			glutSolidCone(3,18,10,10);		
	glPopMatrix();
	
}

void desenhaPerna(int Lado)
{
	GLUquadricObj	*obj;

	if (Lado==ESQUERDA)
	{
		glTranslatef(0.0f, 0.0f, -16);
		glRotatef(5, 1.0f, 0.0f, 0.0f);		
	}
	else
	{
		glTranslatef(0.0f, 0.0f, 16);
		glRotatef(-5, 1.0f, 0.0f, 0.0f);
	}
//<--     Coxa + Articulação
	glRotatef(movimentacao[COXA+MVNT+Lado+Z], 0.0f, 0.0f, 1.0f);
	glRotatef(movimentacao[COXA+MVNT+Lado+Y], 0.0f, 1.0f, 0.0f);
	glRotatef(movimentacao[COXA+MVNT+Lado+X], 1.0f, 0.0f, 0.0f);

	glPushMatrix();
		//Articulação
		if (Wireframe) 
			glutWireSphere(20, 10, 10);
		else
			glutSolidSphere(20, 10, 10);
	glPopMatrix();
	
	glTranslatef(0.0f, -35.0f, 0.0f);

	glPushMatrix();
		//Coxa
		if (Wireframe) 
		{	
			glScalef(25.0f, 45.0f, 25.0f);
			glutWireCube(1.0);
		}
		else
		{
			obj = gluNewQuadric();
			glTranslatef(0.0f, 30.0f, 0.0f);
			glRotatef(90,1,0,0);
			gluCylinder(obj,18,14,65,20,20);
		}
	glPopMatrix();	

	glTranslatef(0.0f, -37.5f, 0.0f);

//-->
//<--	  Perna + Articulação
	glRotatef(movimentacao[PERNA+MVNT+Lado+Z], 0.0f, 0.0f, 1.0f);
	glRotatef(movimentacao[PERNA+MVNT+Lado+Y], 0.0f, 1.0f, 0.0f);
	glRotatef(movimentacao[PERNA+MVNT+Lado+X], 1.0f, 0.0f, 0.0f);
	glPushMatrix();
		//Articulação
		if (Wireframe) 
			glutWireSphere(15, 10, 10);
		else
			glutSolidSphere(15, 10, 10);
	glPopMatrix();
	glTranslatef(0.0f, -37.5f, 0.0f);

	glPushMatrix();
		//Perna
		if (Wireframe) 
		{	
			glScalef(20.0f, 50.0f, 20.0f);
			glutWireCube(1.0);
		}
		else
		{
			obj = gluNewQuadric();
			glTranslatef(0.0f, 30.0f, 0.0f);
			glRotatef(90,1,0,0);
			gluCylinder(obj,15,12,65,20,20);
		}
	glPopMatrix();

	glTranslatef(0.0f, -35.0f, 0.0f);
//-->

//<--	  Pe + Articulação
	glRotatef(movimentacao[PE+MVNT+Lado+Z], 0.0f, 0.0f, 1.0f);
	glRotatef(movimentacao[PE+MVNT+Lado+Y], 0.0f, 1.0f, 0.0f);
	glRotatef(movimentacao[PE+MVNT+Lado+X], 1.0f, 0.0f, 0.0f);

	glPushMatrix();
		//Articulação
		if (Wireframe) 
			glutWireSphere(12, 10, 10);
		else
			glutSolidSphere(12, 10, 10);
	glPopMatrix();
	glTranslatef(0.0f, -30.0f, 0.0f);

	glPushMatrix();
		//Pé
		if (Wireframe) 
		{	
			glScalef(15.0f, 40.0f, 20.0f);
			glutWireCube(1.0);
		}
		else
		{
			obj = gluNewQuadric();
			glTranslatef(0.0f, 30.0f, 0.0f);
			glRotatef(90,1,0,0);
			glScalef(0.8f, 0.99f, 1.0f);
			gluCylinder(obj,12,15,55,20,20);
		}
	glPopMatrix();

	glTranslatef(0.0f, -30.0f, 0.0f);
//-->

//<--	  Dedos + Garras + Articulação
	glRotatef(movimentacao[DEDOS+MVNT+Lado+Z], 0.0f, 0.0f, 1.0f);
	glRotatef(movimentacao[DEDOS+MVNT+Lado+Y], 0.0f, 1.0f, 0.0f);
	glRotatef(movimentacao[DEDOS+MVNT+Lado+X], 1.0f, 0.0f, 0.0f);
	glPushMatrix();
		//Articulação
		if (Wireframe) 
			glutWireSphere(12, 10, 10);
		else
			glutSolidSphere(12, 10, 10);
	glPopMatrix();
	glTranslatef(0.0f, -19.5f, 0.0f);

	glPushMatrix();
		//Dedos
		if (Wireframe) 
		{	
			glScalef(10, 15.0f, 20.0f);
			glutWireCube(1.0);
		}
		else
		{
			glTranslatef(5.0f,0.0f, 0.0f);
			glPushMatrix();
				obj = gluNewQuadric();
				glTranslatef(0.0f,15.0f, 0.0f);
				glRotatef(90,1,0,0);
				glScalef(0.4f, 1.0f, 1.0f);
				gluCylinder(obj,15,12,15,20,20);
			glPopMatrix();
			glScalef(10, 15.0f, 20.0f);
		}
		glRotatef(90,1,0,0);
		//Garras dos pés
		glPushMatrix();
			glRotatef(25, 1.0, 0.0 , 0.0);
			if (Wireframe) 
				glutWireCone(0.5,2.5,10,10);
			else
				glutSolidCone(0.5,2.5,10,10);		
		glPopMatrix();
			if (Wireframe) 
				glutWireCone(0.5,2.5,10,10);
			else
				glutSolidCone(0.5,2.5,10,10);
		glPushMatrix();
			glRotatef(-25, 1.0, 0.0 , 0.0);
			if (Wireframe) 
				glutWireCone(0.5,2.5,10,10);
			else
				glutSolidCone(0.5,2.5,10,10);
		glPopMatrix();
	glPopMatrix();
//-->
}

void desenhaRabo()
{
	GLUquadricObj *obj;
	float raio = 15;
	float x = 25;
	float y = 30;
	float z = 25;

	glRotatef(90, 0.0f, 0.0f, 1.0f);
	glTranslatef(0.0f, -25, 0.0f);
	glRotatef(10, 0.0f, 0.0f, 1.0f);

	for (int i=0; i<SEGMENTOS-1; i++)
	{
		glRotatef(movimentacao[RABO+MVNT+i], 0.0f, 0.0f, 1.0f);
	    glRotatef(movimentacao[RABO+MVNT+6+i], 0.0f, 1.0f, 0.0f);
		glRotatef(movimentacao[RABO+MVNT+12+i], 1.0f, 0.0f, 0.0f);
		glPushMatrix();
			//articulação
		if (Wireframe) 
			glutWireSphere(raio, 15, 15);
		else
			glutSolidSphere(raio, 15, 15);
		glPopMatrix();

		glTranslatef(0.0f, -(raio+(y/2)), 0.0f);

		glPushMatrix();
			//Segmento i
			
			if (Wireframe) 
			{	
				glScalef(x,y,z);
				glutWireCube(1.0);
			}
			else
			{
				obj = gluNewQuadric();
				glTranslatef(0.0f, (raio+(y/2))-5, 0.0f);
				glRotatef(90,1,0,0);
				gluCylinder(obj,raio,raio-2,2*y,20,20);
			}
		glPopMatrix();

		glTranslatef(0.0f, -(raio+(y/2)), 0.0f);

		raio = raio - (raio/10);
		x = x-(x/10);
		y = y-(y/10);
		z = z-(z/10);
	}
	//Ultimo Segmento
	glRotatef(movimentacao[RABO+MVNT+SEGMENTOS-1], 0.0f, 0.0f, 1.0f);
	glRotatef(movimentacao[RABO+MVNT+6+SEGMENTOS-1], 0.0f, 1.0f, 0.0f);
	glRotatef(movimentacao[RABO+MVNT+12+SEGMENTOS-1], 1.0f, 0.0f, 0.0f);
	glPushMatrix();
		//articulação
		if (Wireframe) 
			glutWireSphere(raio, 15, 15);
		else
			glutSolidSphere(raio, 15, 15);
	glPopMatrix();

	glTranslatef(0.0f, -(raio/4+(y/2)), 0.0f);
	glRotatef(90,1.0,0.0,0.0);	//alinhar Z com Y do resto do rabo

	glPushMatrix();
	//Último Segmento
		
		
		if (Wireframe) 
		{
			glScalef(x,y,z);
			glutWireCone(0.5, 2, 10, 10);
		}	
		else
		{
				obj = gluNewQuadric();
				glTranslatef(0.0f,0,  (raio/4+(y/2))-20);
				gluCylinder(obj,raio,0,2*y,20,20);
		}
	glPopMatrix();
}

void desenhaTronco()
{
	GLUquadricObj *obj;

	glRotatef(-90, 0.0f, 0.0f, 1.0f);
	glTranslatef(0.0f, -30.5, 0.0f);
	glRotatef(-33, 0.0f, 0.0f, 1.0f);

	glRotatef(movimentacao[ABDOMEN+MVNT+X], 1.0f, 0.0f, 0.0f);
	glRotatef(movimentacao[ABDOMEN+MVNT+Y], 0.0f, 1.0f, 0.0f);
	glRotatef(movimentacao[ABDOMEN+MVNT+Z], 0.0f, 0.0f, 1.0f);

	glPushMatrix();
		//articulação tronco
	if (Wireframe) 
		glutWireSphere(20, 15, 15);
	else
		glutSolidSphere(20, 15, 15);
	glPopMatrix();

	glTranslatef(00.0f, -30.0, 0.0f);
	glPushMatrix();
		//Abdomen
		if (Wireframe) 
		{	
			glTranslatef(10.0f, 0.0, 0.0f);
			glScalef(30.0,30.0,40.0);
			glutWireCube(1.0);
		}
		else
		{
			obj = gluNewQuadric();
			glTranslatef(0.0f, 30, 0.0f);
			glRotatef(5,0,0,1);
			glRotatef(90,1,0,0);
			gluCylinder(obj,20,25,40,20,20);
		}
	glPopMatrix();

	glRotatef(movimentacao[PEITO+MVNT+X], 1.0f, 0.0f, 0.0f);
	glRotatef(movimentacao[PEITO+MVNT+Y], 0.0f, 1.0f, 0.0f);
	glRotatef(movimentacao[PEITO+MVNT+Z], 0.0f, 0.0f, 1.0f);

	glTranslatef(0.0f, -(10/cos(20)), 0.0f);
	glRotatef(-15, 0.0f, 0.0f, 1.0f);
	glPushMatrix();
		//Peito

		if (Wireframe) 
		{	
			glScalef(40.0,25.0,50.0);
			glutWireCube(1.0);
		}
		else
		{
			obj = gluNewQuadric();
			glTranslatef(0.0f, 30, 0.0f);
			glRotatef(5,0,0,1);
			glRotatef(90,1,0,0);
			glScalef(0.8,1.0,1.0);
			gluCylinder(obj,25,35,40,20,20);
		}
	glPopMatrix();

	glRotatef(movimentacao[PESCOCO+MVNT+X], 1.0f, 0.0f, 0.0f);
	glRotatef(movimentacao[PESCOCO+MVNT+Y], 0.0f, 1.0f, 0.0f);
	glRotatef(movimentacao[PESCOCO+MVNT+Z], 0.0f, 0.0f, 1.0f);


	glPushMatrix();

		glTranslatef(0.0f, -25.0f, 0.0f);
		glPushMatrix();
		//pescoço
		if (Wireframe) 
		{	
			glutWireSphere(15, 15, 15);
		}
		else
		{
			obj = gluNewQuadric();
			gluQuadricDrawStyle(obj, GLU_FILL);
			glTranslatef(0.0f, 30, 0.0f);
			if (MVNT==CORRIDA)
			{
				glRotatef(15,0,0,1);
			}
			if (MVNT==CAMINHADA)
			{
				glRotatef(25,0,0,1);
			}
			glRotatef(90,1,0,0);
			//glScalef(0.8,1.0,1.0);
			gluCylinder(obj,17,13,55,20,20);
		}
		glPopMatrix();

		glRotatef(movimentacao[CABECA+MVNT+X], 1.0f, 0.0f, 0.0f);
		glRotatef(movimentacao[CABECA+MVNT+Y], 0.0f, 1.0f, 0.0f);
		glRotatef(movimentacao[CABECA+MVNT+Z], 0.0f, 0.0f, 1.0f);

		glRotatef(50, 0.0f, 0.0f, 1.0f);
		glTranslatef(0.0f, -25.0f, 0.0f);
			//crânio - traz
		glPushMatrix();
		glScalef(1,1,0.90);
		if (Wireframe) 
			glutWireSphere(20, 15, 15);
		else
			glutSolidSphere(20, 15, 15);
		glPopMatrix();

		glRotatef(60, 0.0f, 0.0f, 1.0f);
		glTranslatef(5.0f, -17.5f, 0.0f);
		glPushMatrix();
			//crânio - frente
			glScalef(2.5,4.0,2);
			if (Wireframe) 
				glutWireCube(10.0);
			else
	  			glutSolidCube(10.0);

		glPopMatrix();

	glPopMatrix();

	glPushMatrix();
        desenhaBracoInteiro(ESQUERDA);	 
	glPopMatrix();
	glPushMatrix();
        desenhaBracoInteiro(DIREITA); 
	glPopMatrix();

	
}


void desenhaQuadril()
{
	GLUquadricObj	*obj;
	//Deslocamento Vertical
	glTranslatef(0.0f, movimentacao[DV+MVNT], 0.0f);		
	//Deslocamento Horizontal do Quadril
	glTranslatef(0.0f, 0.0f, sin(movimentacao[QUADRIL+MVNT+X]));

	//Rotaciona o Quadril de acordo com os ângulos em X, Y e Z para o Frame atual
	glRotatef(movimentacao[QUADRIL+MVNT+Z], 0.0f, 0.0f, 1.0f);
	glRotatef(movimentacao[QUADRIL+MVNT+X], 1.0f, 0.0f, 0.0f);
	glRotatef(movimentacao[QUADRIL+MVNT+Y], 0.0f, 1.0f, 0.0f);
	
	
	glPushMatrix();
		//Quadril
		if (Wireframe) 
		{	
			glScalef(25.0f, 25.0f, 50.0f);
			glutWireCube(1.0);
		}
		else
		{
			obj = gluNewQuadric();
			gluQuadricDrawStyle(obj, GLU_FILL);
			glTranslatef(-30.0f, -5, 0.0f);
			glRotatef(90,0,1,0);
			glScalef(1.0,0.8,1.0);
			gluCylinder(obj,23,23,50,20,20);
		}
	glPopMatrix();
	glPushMatrix();
		glTranslatef(0.0f, -25.0f, 0.0f);
		glPushMatrix();
			desenhaPerna(ESQUERDA);
		glPopMatrix();	
	
		glPushMatrix();
			desenhaPerna(DIREITA);
		glPopMatrix();
	glPopMatrix();

}
void desenhaGodzila()
{
	desenhaQuadril();	
	//Apartir da posição do quadril que é desenhado o resto do corpo
	glPushMatrix();
		desenhaRabo();
	glPopMatrix();	

	glPushMatrix();
		desenhaTronco();
	glPopMatrix();	

}
void projecao(int Width, int Height)
{
	if (ortogonal)
	{ 
		glOrtho(-320, 320, -190, 300, -100,+1000);	
	}
	else
	{
		gluPerspective(45.0f,(GLfloat)Width/(GLfloat)Height,0.5f,10000);
	}
}



void InitGL(int Width, int Height)	        
{
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);	
	glClearDepth(5.0);		
	glDepthFunc(GL_LEQUAL);	
	glEnable(GL_DEPTH_TEST);		
	glShadeModel(GL_SMOOTH);			

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();				
	projecao(Width,Height);	
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
	  
	glMatrixMode(GL_MODELVIEW);
}
void desenhaChao()
{//Desenha um Quadrado no plano XZ
	
	glColor3f(0.8f,0.4f,0.0f);
	glTranslatef(0,-190, -550);
	glRotatef(90, 1.0, 0.0,0.0);

	glRectf(-10000, -10000, 10000, 10000);	

	
}
void calculaMovimentacao(int seg, int fa, int pf)
{
	GLfloat div = (GLfloat) seg/segmentos;
	for(int i=0; i<180; i++)
	{
		movimentacao[i] = (angulos_movimentacao[i][pf]-angulos_movimentacao[i][fa])*div;
		movimentacao[i] = movimentacao[i] + angulos_movimentacao[i][fa];

	}
	//printf("\n%f = (%f-%f)*%f| %i|%i",movimentacao[5],angulos_movimentacao[5][pf],angulos_movimentacao[5][fa],div,fa,pf);
	
}
void calculaDeslocamento(int desloc)
{
	x_ant =  cos(angulo_objeto)*desloc;
	z_ant =  sin(angulo_objeto)*desloc;
	y_ant = 0;
}
void redesenhaMundo(void) 
{
	int desloc;
	int fa = frame_atual;
	int pf = prox_frame;
	for (int i=0; i<segmentos; i++)
	{
		desloc = (GLfloat) deslocamento/segmentos;
		glClearColor(0.0, 0.0, 0.6, 0.0);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glLightModeli(GL_LIGHT_MODEL_TWO_SIDE, GL_TRUE);
		glEnable(GL_LIGHTING);
		if (Wireframe)
		{
			glLightfv(GL_LIGHT0, GL_AMBIENT, emissiveLight);
			glLightfv(GL_LIGHT0, GL_DIFFUSE, emissiveLight);
			glLightfv(GL_LIGHT0, GL_EMISSION, emissiveLight);
			glLightfv(GL_LIGHT0, GL_POSITION, lightPos);
		}else
		{
			glLightfv(GL_LIGHT0, GL_AMBIENT, ambientLight);
			glLightfv(GL_LIGHT0, GL_SPECULAR, diffuseLight);
			glLightfv(GL_LIGHT0, GL_POSITION, lightPos);
			glMaterialfv(GL_FRONT, GL_SPECULAR, mat_spec );
			glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diff );
			glMaterialfv(GL_FRONT, GL_SHININESS, mat_shin);
		}
	
		glPushMatrix();
			desenhaChao();
		glPopMatrix();
	
		glColor3f(0.7f,0.2f,0.0f);
			
		glEnable(GL_LIGHT0);
		glEnable(GL_COLOR_MATERIAL);
			glTranslatef(0,0,-550);
				calculaMovimentacao(i,fa,pf);
				calculaDeslocamento(desloc);	
				glTranslatef(x_ant, y_ant, z_ant);
				glRotatef(angulo_objeto, 0.0f, 1.0f, 0.0f);
				angulo_objeto = 0;

				glPushMatrix();
					desenhaGodzila();
				glPopMatrix();		
				
			glTranslatef(0,0,550);
		glutSwapBuffers();
	}
	desloc = 0;
	deslocamento = 0;
	frame_atual = prox_frame;
}

void mostraMundo(void)
{
	redesenhaMundo();

}

void redimensionaJanela(int width, int height)
{
    Width  = width;
    Height = height;
	glPushMatrix();
	glViewport(0, 0, width, height);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

	projecao(Width,Height);
    glMatrixMode(GL_MODELVIEW);

	glLoadIdentity();
	glPopMatrix();	
}
void tecla(unsigned char tecla, int x, int y) 
{
  switch ( tecla ) {
    case 27:			
		glutDestroyWindow(window); 
		exit(0); 
		break;
    case 'c':			
		MVNT = CORRIDA;
		frames = FRAMES_CORRIDA;
		segmentos = SEG_CORRIDA;
		qtd_deslocamento = DESLOC_CORRIDA;
		break;
    case 'a':			
		MVNT = CAMINHADA;
		frames = FRAMES_CAMINHADA;
		segmentos = SEG_CAMINHADA;
		qtd_deslocamento = DESLOC_CAMINHADA;
		break;
  }
}


void teclas_especiais ( int tecla, int x, int y )  
{
  switch ( tecla ) {
    case GLUT_KEY_F6:	
      glutFullScreen ( );	
      break;
    case GLUT_KEY_F8:		
      glutReshapeWindow ( 640, 480 );
      break;
	case GLUT_KEY_F4:
		// Mudar Modo de Projecao
		ortogonal = !ortogonal;
		redimensionaJanela(Width,Height);
	   break;
	case GLUT_KEY_PAGE_DOWN: 
		angle--;
		break;
	case GLUT_KEY_PAGE_UP :
		angle++;
		break;
	case GLUT_KEY_END: 
		prox_frame--;
		if (prox_frame<0) prox_frame= frames;
		break;
	case GLUT_KEY_HOME :
		prox_frame++;
		if (prox_frame>frames) prox_frame= 0;
		break;
	case GLUT_KEY_F3 :
		// Mudar tipo de renderização
		Wireframe = !Wireframe;
		break;
	case GLUT_KEY_UP:
		//Deslocamento para frente
		deslocamento-=qtd_deslocamento;
		prox_frame++;
		if (prox_frame>frames) prox_frame= 0;
		break;
	case GLUT_KEY_DOWN :
		//Deslocamento para traz
		deslocamento+=qtd_deslocamento;
		prox_frame--;
		if (prox_frame<0) prox_frame= frames;
		break;
	case GLUT_KEY_LEFT :
		//Rotaciona o objeto no sentido anti-horário
		angulo_objeto+=5;
		break;
	case GLUT_KEY_RIGHT :
		//Rotaciona o objeto no sentido horário
		angulo_objeto-=5;
		break;
    default:
      break;
  }
}

int main(int  argc, char *argv[]) 
    {
    glutInit(&argc, argv);

    glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);

    glutInitWindowSize(640, 480);
	glutInitWindowPosition(100,100);  

    window = glutCreateWindow("INE5341 Computação Gráfica UFSC - Godzila");

    /*	Registro de Funções */
	glutReshapeFunc(redimensionaJanela);
    glutDisplayFunc(redesenhaMundo);
	glutKeyboardFunc(tecla);
	glutSpecialFunc(teclas_especiais);
	glutIdleFunc(mostraMundo);
	InitGL( 640, 480);

	glutMainLoop();
    return (0);
    }