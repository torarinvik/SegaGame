#include "Collision.h"

Bool detect_collision_between_balls(Ball* ball1, Ball* ball2) {
    Vector distance = subtr(ball1->pos, ball2->pos);
    return (ball1->r + ball2->r >= mag(distance));
}

void prevent_overlap_between_balls(Ball* ball1, Ball* ball2) {
    Vector distance = subtr(ball1->pos, ball2->pos);
    Vector distanceUnit = unit(distance);
    double penetration_depth = ball1->r + ball2->r - mag(distance);
    Vector penetration_resolution = mult(distanceUnit, penetration_depth / (ball1->inv_mass + ball2->inv_mass));
    ball1->pos = add(ball1->pos, mult(penetration_resolution, ball1->inv_mass));
    ball2->pos = add(ball2->pos, mult(penetration_resolution, -ball2->inv_mass));
}

void resolve_collision_between_balls(Ball* ball1, Ball* ball2) {
    Vector normal = unit(subtr(ball1->pos, ball2->pos));
    Vector relative_velocity = subtr(ball1->vel, ball2->vel);
    double separation_velocity = dot(relative_velocity, normal);
    double new_separation_velocity = -separation_velocity * floatMin(ball1->elasticity, ball2->elasticity);
    double velocity_difference = new_separation_velocity - separation_velocity;
    Vector impulse = mult(normal, velocity_difference / (ball1->inv_mass + ball2->inv_mass));
    ball1->vel = add(ball1->vel, mult(impulse, ball1->inv_mass));
    ball2->vel = add(ball2->vel, mult(impulse, -ball2->inv_mass));
}

Vector closest_point_on_wall(Ball* ball, Wall* wall) {
    Vector ball_to_wall_start = subtr(wall->start, ball->pos);
    if (dot(wall_unit(wall), ball_to_wall_start) > 0) {
        return wall->start;
    }
    Vector wall_end_to_ball = subtr(ball->pos, wall->end);
    if (dot(wall_unit(wall), wall_end_to_ball) > 0) {
        return wall->end;
    }
    double closest_distance = dot(wall_unit(wall), ball_to_wall_start);
    Vector closest_vector = mult(wall_unit(wall), closest_distance);
    return subtr(wall->start, closest_vector);
}

Bool detect_collision_between_ball_and_wall(Ball* ball, Wall* wall) {
    Vector ball_to_closest = subtr(ball->pos, closest_point_on_wall(ball, wall));
    return (mag(ball_to_closest) <= ball->r);
}

void prevent_overlap_between_ball_and_wall(Ball* ball, Wall* wall) {
    Vector penetration_vector = subtr(ball->pos, closest_point_on_wall(ball, wall));
    ball->pos = add(ball->pos, mult(unit(penetration_vector), ball->r - mag(penetration_vector)));
}

void resolve_collision_between_ball_and_wall(Ball* ball, Wall* wall) {
    Vector normal = unit(subtr(ball->pos, closest_point_on_wall(ball, wall)));
    double separation_velocity = dot(ball->vel, normal);
    double new_separation_velocity = -separation_velocity * ball->elasticity;
    double velocity_difference = separation_velocity - new_separation_velocity;
    ball->vel = add(ball->vel, mult(normal, -velocity_difference));
}



void resolve_penetration_between_ball_and_wall(Ball* ball, Wall* wall) {
    Vector closest_point = closest_point_on_wall(ball, wall);
    Vector pen_vect = subtr(ball->pos, closest_point);
    Vector pen_vect_unit = unit(pen_vect);
    Vector new_pos = add(ball->pos, mult(pen_vect_unit, ball->r - mag(pen_vect)));
    ball->pos = new_pos;
}

