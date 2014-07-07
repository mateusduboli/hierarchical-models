#ifndef __MOVEMENT__
#define __MOVEMENT__

#define FRONT_RIGHT 0
#define BACK_RIGHT 1
#define FRONT_LEFT 2
#define BACK_LEFT 3

extern const int FRAMES;

typedef enum {
    SHOULDER,
    THIGHTS
} BodyPart;

double movementAngle(BodyPart part, int index, int frame);
double displacement(BodyPart part, int index, int frame);
#endif // __MOVEMENT__
