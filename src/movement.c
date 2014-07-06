#include "movement.h"

const int FRAMES = 10;

double movementShoulder(int index, int frame)
{
    double MAX_ANGLE = 30;
    double FRAME_STEP = 4*MAX_ANGLE/FRAMES;

    int i = frame;
    if(index == FRONT_LEFT || index == BACK_RIGHT)
        i += FRAMES/2;

    i %= FRAMES;

    if(i < FRAMES/2)
        return i*FRAME_STEP - MAX_ANGLE;
    else 
        return (FRAMES - i) * FRAME_STEP - MAX_ANGLE;
}

double movementAngle(BodyPart part, int index, int frame)
{
    double _angle = 0.0;
    switch(part) {
        case SHOULDER:
            _angle = movementShoulder(index, frame);
    }
    return _angle;
}
