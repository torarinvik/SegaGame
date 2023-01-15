#ifndef COLLISION_H
#define COLLISION_H
#include "Wall.h"
#include "Ball.h"
#include "Vector.h"
#include "Basic.h"



bool detect_collision_between_balls(Ball* ball1, Ball* ball2);
void prevent_overlap_between_balls(Ball* ball1, Ball* ball2);

void resolve_collision_between_balls(Ball* ball1, Ball* ball2);

Vector closest_point_on_wall(Ball* ball, Wall* wall);
bool detect_collision_between_ball_and_wall(Ball* ball, Wall* wall);

#endif