#ifndef WALL_H
#define WALL_H
#include "Vector.h"

typedef struct Wall {
    Vector start;
    Vector end;
} Wall;

#define MAX_WALLS 4
Wall walls[MAX_WALLS];
static int walls_count = 0;


Wall new_wall(double x1, double y1, double x2, double y2);

Vector wall_unit(Wall *wall);




#endif