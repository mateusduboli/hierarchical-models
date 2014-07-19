#include "elephant.h"

void elephant(int wired, int frame, double param)
{
    const GLfloat specular[] = {1, 1, 1, 1};
    const GLfloat emission[] = {0, 0, 0, 1};

    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, specular);
    glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION, emission);

    if(wired)
        wire_elephant(frame, param);
    else
        solid_elephant(frame, param);

}
