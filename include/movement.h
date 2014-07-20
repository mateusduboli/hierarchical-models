#ifndef __MOVEMENT__
#define __MOVEMENT__

#include <math.h>

#include "sizes.h"

typedef enum {
    HIPS,
    KNEE,
    SHOULDER,
    ELBOW,
    WRIST,
    TRUNK,
    TAIL
} BodyPart;

typedef enum {
    RIGHT,
    LEFT
} Side;

static const int FRAMES = 4;
static const int DISPLAY_FRAMES = 80;
static const int FRAME_INTERVAL = 20;
static const int BODY_PARTS = 7;
static const int SIDES = 2;

static double ANGLES[BODY_PARTS][SIDES][FRAMES] = {
    { //Hips
        {20,  0, -20, 0}, //Right
        {-20, 0, 20, 0}  //Left
    },
    { // Knee
        {0, 0, 0, -20},
        {0, -20, 0, 0}
    },
    { // Shoulder
        {15, 0, -15, 0},
        {-15, 0, 15, 0}
    },
    { // Elbow
        {0, 0, 0, -30},
        {0, -30, 0, 0}
    },
    { // Wrist
        {0, 0, 0, -90},
        {0,-90, 0, 0}
    },
    {   //Trunk
        {0, 10, 0, -10}, // First
        {10, 0, -10, 0}  // Second
    },
    {   //Tail
        {0, -10, 0, 10},
        {0, 0, 0, 0} //Not used
    }
};

double movement(BodyPart part, Side side, int frame);
double displacement(BodyPart part, int index, int frame);

//   for(int i = 0; i < BODY_PARTS; i++)
//       for(int j = 0; j < SIDES; j++)
//           for(int k = 0; k < FRAMES; k++)
//               printf("A(%d,%d,%d) = %f\n", i, j, k, ANGLES[i][j][k]);
//printf("part : %d, side: %d\n", HIPS, side);
//printf("side: %d, index: %d, angle: %f\n", side, index, angle);
//printf("s_index: %d, t_index: %d\n", start_index, target_index);
//printf("start: %f, target: %f\n", start, target);
#endif // __MOVEMENT__
