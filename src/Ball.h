#ifndef BALL_H
#define BALL_H

#include "Vector.h"
#include <genesis.h>
typedef struct Ball {
    Vector pos;
    Vector vel;
    double radius;
    double elasticity;
    Sprite* sprite;
} Ball;

Ball newBall(Vector pos, Vector vel, double radius, double elasticity, const SpriteDefinition* image);

void updateBall(Ball *ball, double dt);

Bool checkBallCollision(Ball *ball1, Ball *ball2);
void handleBallCollision(Ball *ball1, Ball *ball2);

Bool checkAndHandleWallCollision(Ball *ball, double width, double height);



#endif /* BALL_H */
