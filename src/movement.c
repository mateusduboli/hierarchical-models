#include "movement.h"

const int FRAMES = 60;

double shoulderAngle(int index, int frame)
{
    int SECTION_SIZE = FRAMES/2;
    double MAX_ANGLE = 30;
    double FRAME_STEP = 2*MAX_ANGLE/SECTION_SIZE;

    int i = frame;
    if (index == FRONT_LEFT || index == BACK_RIGHT)
        i += SECTION_SIZE;

    i %= FRAMES;

    if (i < SECTION_SIZE) // Moving forward
        return i*FRAME_STEP - MAX_ANGLE;
    else             // Moving back
        return (FRAMES - i) * FRAME_STEP - MAX_ANGLE;
}

double thigthsAngle(int index, int frame)
{
    int SECTION_SIZE = FRAMES/4;
    double MAX_ANGLE = 30;
    double FRAME_STEP = MAX_ANGLE/SECTION_SIZE;

    int i = frame;
    if (index == FRONT_LEFT || index == BACK_RIGHT)
        i += FRAMES/2;

    i %= FRAMES;

    if (i < SECTION_SIZE) // First half of moving forward
        return - (i * FRAME_STEP);
    else if (i < 2*SECTION_SIZE) // Second half of moving forward
        return - (MAX_ANGLE - (i - SECTION_SIZE) * FRAME_STEP);
    else
        return 0.0;
}
double bodyDisplacement(int index, int frame)
{
    return 0.0;
}

double movementAngle(BodyPart part, int index, int frame)
{
    double _angle = 0.0;
    switch(part) {
        case SHOULDER:
            _angle = shoulderAngle(index, frame);
            break;
        case THIGHTS:
            _angle = thigthsAngle(index, frame);
            break;
    }
    return _angle;
}
