#include "Ball.h"



Ball new_ball(double mass, double radius, char* color, double x, double y, double vx, double vy) {
    Ball ball;
    ball.mass = mass;
    ball.inv_mass = mass == 0 ? 0 : 1 / mass;
    ball.r = radius;
    ball.pos = new_vector(x, y);
    ball.originalpos = ball.pos;
    ball.vel = new_vector(vx, vy);
    ball.originalvel = ball.vel;
    ball.acc = new_vector(0, 0);
    ball.acc_mult = 1;
    ball.elasticity = 0.8;
    ball.color = color;
    if (balls_count < MAX_BALLS) {
        balls[balls_count++] = ball;
    }
    return ball;
}

#define friction 0.01

void reposition_ball(Ball* ball) {
    ball->acc = normal(ball->acc);
    scale(ball->acc, ball->acc_mult);
    add(ball->vel, ball->acc);
    scale(ball->vel, 1 - friction);
    add(ball->pos, ball->vel);
}

void reset_ball(Ball* ball) {
    ball->pos = ball->originalpos;
    ball->vel = ball->originalvel;
}
