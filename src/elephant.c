#include "elephant.h"

void elephant(int wired, int frame, double param)
{
    if(wired)
        wire_elephant(frame, param);
    else
        solid_elephant(frame, param);

}
