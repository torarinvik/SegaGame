#include "Wall.h"

Wall new_wall(double x1, double y1, double x2, double y2) {
    Wall wall;
    wall.start = new_vector(x1, y1);
    wall.end = new_vector(x2, y2);
    if (shared_data.walls_count < MAX_WALLS) {
        walls[shared_data.walls_count++] = wall;
    }
    return wall;
}

Vector wall_unit(Wall *wall) {
    Vector v = subtr(wall->end, wall->start);
    return unit(v);
}
