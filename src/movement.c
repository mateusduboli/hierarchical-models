#include "movement.h"
#include <stdio.h>

double (*angles)[SIDES][FRAMES] = WALKING;

void walking()
{
    angles = WALKING;
}
void raising()
{
    angles = RAISING;
}

double displacement(BodyPart part, Side side, int frame)
{
    double disp = 0.0;
    double height = 0.0;
    switch(part) {
        case SHOULDER:
            height += JOINT_SIZE * 4;
            height += HAND_HEIGHT;
            height += ELBOW_HEIGHT;
            height += SHOULDER_HEIGHT;
            break;
        default:
            disp = 0.0;
            break;
    }
    return disp;
}

double movement(BodyPart part, Side side, int frame)
{
    int index = frame % DISPLAY_FRAMES;

    int start_index = index/FRAME_INTERVAL % FRAMES;
    int target_index = (index/FRAME_INTERVAL + 1) % FRAMES;
    int step_index = index % FRAME_INTERVAL;

    double start = angles[part][side][start_index];
    double target = angles[part][side][target_index];
    double step = (target - start)/FRAME_INTERVAL;

    double angle = start + step_index * step; // Linear interpolation

    return angle;
}
