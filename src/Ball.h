#ifndef BALL_H
#define BALL_H
#include "Vector.h"


typedef struct Ball {
    double mass;
    double inv_mass;
    double r;
    Vector pos;
    Vector originalpos;
    Vector vel;
    Vector originalvel;
    Vector acc;
    double acc_mult;
    double elasticity;
    char* color;
} Ball;
#define MAX_BALLS 10
Ball balls[MAX_BALLS];
static int balls_count = 0;

#endif