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
    TAIL,
    TORSO,
    HEAD
} BodyPart;

typedef enum {
    RIGHT,
    LEFT
} Side;

static const int FRAMES = 4;
static const int DISPLAY_FRAMES = 80;
static const int FRAME_INTERVAL = 20;
static const int BODY_PARTS = 9;
static const int SIDES = 2;

static double RAISING[BODY_PARTS][SIDES][FRAMES] = {
    { //Hips
        {0, 0, 0, 0}, //Right
        {0, 0, 0, 0}  //Left
    },
    { // Knee
        {0, -15, -30, 0},
        {0, -15, -30, 0}
    },
    { // Shoulder
        {0, -10, -20, 0},
        {0, -10, -20, 0}
    },
    { // Elbow
        {0, 45, 90, 0},
        {0, 45, 90, 0}
    },
    { // Wrist
        {0, -27.5, -45, 0},
        {0, -27.5, -45, 0}
    },
    {   //Trunk
        {0, -15, 20, 0}, // First
        {0, -15, 30, 0}  // Second
    },
    {   //Tail
        {0, -15, -30, 0},
        {0, 0, 0, 0} //Not used
    },
    {   //Torso
        {0, 15, 30, 0},
        {0, 0, 0, 0} //Not used
    },
    {   //Head
        {0, -15, 30, 0},
        {0, 0, 0, 0} //Not used
    }
};

static double WALKING[BODY_PARTS][SIDES][FRAMES] = {
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
        {0, 0, 0, 45},
        {0, 45, 0, 0}
    },
    { // Wrist
        {0, 0, -90, -90},
        {-90,-90, 0, 0}
    },
    {   //Trunk
        {0, 10, 0, -10}, // First
        {10, 0, -10, 0}  // Second
    },
    {   //Tail
        {0, -10, 0, 10},
        {0, 0, 0, 0} //Not used
    },
    {   //Torso
        {0, 0, 0, 0},
        {0, 0, 0, 0} //Not used
    },
    {   //Head
        {0, 0, 0, 0},
        {0, 0, 0, 0} //Not used
    }
};

void walking();
void raising();
double movement(BodyPart part, Side side, int frame);
double displacement(BodyPart part, Side side, int frame);

#endif // __MOVEMENT__
