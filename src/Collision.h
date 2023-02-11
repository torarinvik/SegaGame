#ifndef COLLISION_H
#define COLLISION_H
#include "Ball.h"
#include "Wall.h"

#include "Vector.h"
#include "Basic.h"


//Bool detect_collision_between_balls(Ball* ball1, Ball* ball2);
Bool collisionDectectionBetweenBalls(Ball* ball1,Ball* ball2);
void penetrationResolutionBetweenBallAndWall(Ball* ball, Wall* wall);


void prevent_overlap_between_balls(Ball* ball1, Ball* ball2);
void resolve_collision_between_balls(Ball* ball1, Ball* ball2);




//Vector closest_point_on_wall(Ball* ball, Wall* wall);
Vector closestPointBetweenBallAndWall(Ball* ball, Wall* wall);


Bool collisionDectectionBetweenBallAndWall(Ball* ball, Wall* wall);
//Bool detect_collision_between_ball_and_wall(Ball* ball, Wall* wall);
void resolve_penetration_between_ball_and_wall(Ball* ball, Wall* wall); 
void resolve_collision_between_ball_and_wall(Ball* ball, Wall* wall);


 

#endif