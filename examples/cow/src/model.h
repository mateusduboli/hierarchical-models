#include "Model_Draw.h"

double getAngle(int bodyPart){

	int NormFrame = frame % (framesperstep * maxStep);
	int currentStep = (NormFrame / framesperstep) % maxStep;
	int previousStep = currentStep -1;
	if(previousStep < 0){
		previousStep += maxStep;
}
   double fractionStep = (NormFrame - currentStep * framesperstep) / (1.0 * framesperstep);

   double angle;
   double previousAngle;

   if(WALKING){
	   angle = walk_angles[bodyPart][currentStep];
	   previousAngle = walk_angles[bodyPart][previousStep];
   }else{
	   angle = sprint_angles[bodyPart][currentStep];
	   previousAngle = sprint_angles[bodyPart][previousStep];
   }
	if(fly == 0){
		return angle  * fractionStep + previousAngle * (1.0 - fractionStep);
	}else{
		return fractionStep*(angle-previousAngle)/framesperstep;
	}
}

void hoof(int side){
	glPushMatrix();
		drawHoof(side);
	glPopMatrix();
}


void hoofJoint(int side){
	glPushMatrix();
		glTranslatef(0.0, 0.0, LOWER_LEG_LENGTH);

		if(side == LEFT_FRONT ){
			glRotatef(getAngle(LEFT_FRONT_HOOF_JOINT), 1.0, 0.0, 0.0);
		}else if( side == RIGHT_FRONT){
			glRotatef(getAngle(RIGHT_FRONT_HOOF_JOINT), 1.0, 0.0, 0.0);
		}else if( side == LEFT_BACK){
			glRotatef(getAngle(LEFT_BACK_HOOF_JOINT), 1.0, 0.0, 0.0);
		}else{
			glRotatef(getAngle(RIGHT_BACK_HOOF_JOINT), 1.0, 0.0, 0.0);
		}


		drawHoofJoint();
		hoof(side);
	glPopMatrix();
}


void lowerLeg(int side){
	glPushMatrix();
		drawLowerLeg();
		hoofJoint(side);
	glPopMatrix();
}


void lowerLegJoint(int side){
	glPushMatrix();
		glTranslatef(0.0, 0.0, UPPER_LEG_LENGTH);


		if(side == LEFT_FRONT ){
			glRotatef(getAngle(LEFT_FRONT_LOWER_LEG_JOINT), 1.0, 0.0, 0.0);
		}else if( side == RIGHT_FRONT){
			glRotatef(getAngle(RIGHT_FRONT_LOWER_LEG_JOINT), 1.0, 0.0, 0.0);
		}else if( side == LEFT_BACK){
			glRotatef(getAngle(LEFT_BACK_LOWER_LEG_JOINT), 1.0, 0.0, 0.0);
		}else{
			glRotatef(getAngle(RIGHT_BACK_LOWER_LEG_JOINT), 1.0, 0.0, 0.0);
		}

		drawLowerLegJoint();
		lowerLeg(side);
	glPopMatrix();
}


void upperLeg(int side){
	glPushMatrix();
		if(side == LEFT_FRONT  || side == LEFT_BACK){
			glTranslatef(JOINT_WIDTH, 0.0, -JOINT_WIDTH);
		}else{
			glTranslatef(-JOINT_WIDTH, 0.0, -JOINT_WIDTH);
		}

		drawUpperLeg();
		lowerLegJoint(side);
	glPopMatrix();
}

void upperLegJoint(int side){
	glPushMatrix();
		if(side == LEFT_FRONT ){
			glTranslatef(TRUNK_WIDTH/2.0, -JOINT_WIDTH/2, TRUNK_LENGTH/8.0);
			glRotatef(getAngle(LEFT_FRONT_UPPER_LEG_JOINT), 1.0, 0.0, 0.0);
		}else if( side == RIGHT_FRONT){
			glTranslatef(-TRUNK_WIDTH/2.0, -JOINT_WIDTH/2, TRUNK_LENGTH/8.0);
			glRotatef(getAngle(RIGHT_FRONT_UPPER_LEG_JOINT), 1.0, 0.0, 0.0);
		}else if( side == LEFT_BACK){
			glTranslatef(TRUNK_WIDTH/2.0, -JOINT_WIDTH/2, 7*TRUNK_LENGTH/9.0);
			glRotatef(getAngle(LEFT_BACK_UPPER_LEG_JOINT), 1.0, 0.0, 0.0);
		}else{
			glTranslatef(-TRUNK_WIDTH/2.0, -JOINT_WIDTH/2, 7*TRUNK_LENGTH/9.0);
			glRotatef(getAngle(RIGHT_BACK_UPPER_LEG_JOINT), 1.0, 0.0, 0.0);
		}

		drawUpperLegJoint();
		upperLeg(side);
	glPopMatrix();
}

void tail(){
	glPushMatrix();
		glTranslatef(0.0, 0.0, TAIL_LENGTH);
		glRotatef(180, 0.0, 1.0, 0.0);
		drawTail();
		drawEndTail();
	glPopMatrix();
}

void tailBase(){
	glPushMatrix();
		glTranslatef(0.0, TRUNK_WIDTH/2.0 -JOINT_HEIGHT , TRUNK_LENGTH );
		glRotatef(getAngle(TAIL_JOINT), 1.0, 0.0, 0.0);
		drawTailBase();
		tail();
	glPopMatrix();
}

void head(){
	glPushMatrix();
		glTranslatef(0.0, 0.0, -HEAD_LENGTH -JOINT_WIDTH/2.0 );
		drawHead();
		drawEars();
	glPopMatrix();
}

void neck(){
	glPushMatrix();
		glTranslatef(0.0, TRUNK_WIDTH/2.0 - JOINT_WIDTH/2.0, -JOINT_WIDTH/2.0);
		glRotatef(getAngle(HEAD), 1.0, 0.0, 0.0);
		drawNeck();
		head();
	glPopMatrix();
}

void trunk(){
	glPushMatrix();
		glTranslatef(posicao, 0.0, 0.0 );
		glRotatef(rotateAngle, 0.0, 1.0, 0.0);
		glRotatef(getAngle(TRUNK), 1.0, 0.0, 0.0);
		glTranslatef(0.0, 0.0, -TRUNK_LENGTH/2.0 );
		//glutSetColor(1,1.0, 0.1, 1.0);
		//glClearIndex(1.0);
		drawTrunk();
	glPopMatrix();
}

void Cow(){

	trunk();

}















