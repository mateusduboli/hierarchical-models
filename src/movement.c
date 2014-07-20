#include "movement.h"
#include <stdio.h>

double displacement(BodyPart part, int index, int frame)
{
    return 0.0;
}

double movement(BodyPart part, Side side, int frame)
{
    int index = frame % DISPLAY_FRAMES;

    int start_index = index/FRAME_INTERVAL % FRAMES;
    int target_index = (index/FRAME_INTERVAL + 1) % FRAMES;
    int step_index = index % FRAME_INTERVAL;

    double start = ANGLES[part][side][start_index];
    double target = ANGLES[part][side][target_index];
    double step = (target - start)/FRAME_INTERVAL;

    double angle = start + step_index * step; // Linear interpolation

    return angle;
}
