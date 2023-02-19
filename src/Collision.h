#ifndef COLLISION_H
#define COLLISION_H
#include "Ball.h"
#include "Wall.h"

#include "Vector.h"
#include "Basic.h"






Bool bingIs_colliding(Ball *b1, Ball *b2);
void bingHandle_collision(Ball* b1, Ball *b2); 

#endif