
/* Scale */
#define SCALE 2.0
int rotateAngle = 90;
int maxStep = 8;
int frame = 0;
int framesperstep = 10;
double posicao = 0;

/* Movement */
double movement  = 0;

/* Wire/Solid */
int WIRED = 1;
int SMOOTH = 1;

/* Walking/Running */

int WALKING = 1;

int fly = 0 ;

/*defs*/
#define LEFT_FRONT_UPPER_LEG_JOINT 0
#define RIGHT_FRONT_UPPER_LEG_JOINT 1

#define LEFT_BACK_UPPER_LEG_JOINT 2
#define RIGHT_BACK_UPPER_LEG_JOINT 3

#define LEFT_FRONT_LOWER_LEG_JOINT 4
#define RIGHT_FRONT_LOWER_LEG_JOINT 5

#define LEFT_BACK_LOWER_LEG_JOINT 6
#define RIGHT_BACK_LOWER_LEG_JOINT 7

#define LEFT_FRONT_HOOF_JOINT 8
#define RIGHT_FRONT_HOOF_JOINT 9

#define LEFT_BACK_HOOF_JOINT 10
#define RIGHT_BACK_HOOF_JOINT 11

#define TAIL_JOINT 12
#define TRUNK 13
#define HEAD 14

/* Leg Sides */
#define LEFT_FRONT 0
#define RIGHT_FRONT 1
#define LEFT_BACK 2
#define RIGHT_BACK 3

/* Trunk */
#define TRUNK_HEIGHT 0.7 / SCALE
#define TRUNK_WIDTH 0.7 / SCALE
#define TRUNK_LENGTH 1.3 / SCALE


/* Tail */
#define TAIL_HEIGHT 0.05 / SCALE
#define TAIL_WIDTH 0.05 / SCALE
#define TAIL_LENGTH 0.5 / SCALE


/* Head */
#define HEAD_HEIGHT 0.2 / SCALE
#define HEAD_WIDTH 0.2 / SCALE
#define HEAD_LENGTH 0.3 / SCALE

/* Upper Leg */
#define UPPER_LEG_HEIGHT 0.4 / SCALE
#define UPPER_LEG_WIDTH 0.2 / SCALE
#define UPPER_LEG_LENGTH 0.4 / SCALE

/* Lower Leg */
#define LOWER_LEG_HEIGHT 0.4 / SCALE
#define LOWER_LEG_WIDTH 0.05 / SCALE
#define LOWER_LEG_LENGTH 0.3 / SCALE

/* Hoof */
#define HOOF_HEIGHT 0.05 / SCALE
#define HOOF_WIDTH 0.05 / SCALE
#define HOOF_LENGTH 0.05/ SCALE

/* Joints */ 
#define JOINT_HEIGHT 0.1 / SCALE
#define JOINT_WIDTH 0.1 / SCALE
#define JOINT_LENGTH 0.1 / SCALE


double sprint_angles[15][8] = {
		// 90 significa que a perna está a 90 graus relativo ao corpo.
		/* LEFT FRONT UPPER LEG JOINT 	*/{90+60,90+30 ,90-40,90-20 ,90+30,90+60 ,90+70,90+70},
		/* RIGHT FRONT UPPER LEG JOINT 	*/{90-40,90-20 ,90+30 ,90+60 ,90+70,90+70 ,90+60,90+30},
		/* LEFT BACK UPPER LEG JOINT 	*/{90-30 ,90+40,90+20 ,90-30 ,90-60 ,90-70 ,90-70 ,90-60},
		/* RIGHT BACK UPPER LEG JOINT 	*/{90+20 ,90-30 ,90-60 ,90-70 ,90-70 ,90-60 ,90-30 ,90+40},

		/* LEFT FRONT LOWER LEG JOINT 	*/{-40 ,-60, -80 ,-100,-80 ,-60,0 ,-20},
		/* RIGHT FRONT LOWER LEG JOINT 	*/{-80 ,-100,-80 ,-60,0 ,-20 ,-40 ,-60},
		/* LEFT BACK LOWER LEG JOINT 	*/{80 ,60,0 ,20 ,40 ,60 ,80 ,100},
		/* RIGHT BACK LOWER LEG JOINT 	*/{0 ,20 ,40 ,60 ,80 ,100 ,80 ,60},
 
		/* LEFT FRONT HOOF JOINT 	*/{-40 ,-60,-80 ,-60,-40 ,-20,0 ,-20},
		/* RIGHT FRONT HOOF JOINT 	*/{-80 ,-60,-40 ,-20,0 ,-20 ,-40 ,-60},
		/* LEFT BACK HOOF JOINT 		*/{-40 ,-20,0 ,-20 ,-40 ,-60 ,-80 ,-60},
		/* RIGHT BACK HOOF JOINT 	*/{0 ,-20 ,-40 ,-60 ,-80 ,-60 ,-40 ,-20},

		/* TAIL				*/{ 55,65,65,65,55,65,65,65 },
		/* TRUNK 			*/{ -3,-3,-3,3,3,3,3,0 },
		/* HEAD 			*/{ 0,10,0,-5,-10,-20,-30,-20 }
};

double walk_angles[15][8] = {
		// 90 significa que a perna está a 90 graus relativo ao corpo.
		/* LEFT FRONT UPPER LEG JOINT 	*/{90+40 ,90+20 ,90 ,90-20 ,90 ,90+20 ,90+40 ,90+60},
		/* RIGHT FRONT UPPER LEG JOINT 	*/{90 ,90+20 ,90+40 ,90+60 ,90+40 ,90+20 ,90 ,90-20},
		/* LEFT BACK UPPER LEG JOINT 	*/{90-60,90-40,90-20,90,90+20,90,90-20,90-40},
		/* RIGHT BACK UPPER LEG JOINT 	*/{90+20,90,90-20,90-40,90-60,90-40,90-20,90},

		/* LEFT FRONT LOWER LEG JOINT 	*/{ -20,0,0,0,-20,-40,-60,-40 },
		/* RIGHT FRONT LOWER LEG JOINT 	*/{ -20,-40,-60,-40,-20,0,0,0 },
		/* LEFT BACK LOWER LEG JOINT 	*/{ 60,80,60,30,0,0,0,30},
		/* RIGHT BACK LOWER LEG JOINT 	*/{ 0,0,0,30,60,80,60,30 },

		/* LEFT FRONT HOOF JOINT 	*/{ -20,0,0,0,-20,-40,-60,-40 },
		/* RIGHT FRONT HOOF JOINT 	*/{ -20,-40,-60,-40,-20,0,0,0 },
		/* LEFT BACK HOOF JOINT 	*/{-60,-80,-60,-30,0,0,0,-30},
		/* RIGHT BACK HOOF JOINT 	*/{ 0,0,0,-30,-60,-80,-60,-30 },

		/* TAIL				*/{ 55,65,65,65,55,65,65,65 },
		/* TRUNK 			*/{ 0,0,0,0,0,0,0,0 },
		/* HEAD 			*/{ 0,0,0,0,0,0,0,0 }
};


