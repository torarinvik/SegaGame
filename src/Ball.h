#ifndef BALL_H
#define BALL_H
#include "Vector.h"
#include "Globals.h"
#include "genesis.h"
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
    Sprite* sprite;
} Ball;
#define MAX_BALLS 10

Ball new_ball(double mass, double radius, char* color, double x, double y, double vx, double vy,const SpriteDefinition* image);
void reposition_ball(Ball* ball);
void reset_ball(Ball* ball);

Ball balls[MAX_BALLS];


#endif