#include "Ball.h"



Ball newBall(Vector pos, Vector vel, double radius, const SpriteDefinition* image) {
    Ball ball = {pos, vel, radius};
    ball.sprite = SPR_addSprite(image,ball.pos.x, ball.pos.y,TILE_ATTR(PAL1,0, FALSE, FALSE));
    return ball;
}

void updateBall(Ball *ball, double dt) {
    ball->pos = add(ball->pos, mult(ball->vel, dt));
    SPR_setPosition(ball->sprite, ball->pos.x -4, ball->pos.y -9);
}




Bool checkAndHandleWallCollision(Ball *ball, double width, double height){
    if (ball->pos.x - ball->radius < 0) {
        ball->pos.x = ball->radius;
        ball->vel.x = -ball->vel.x;
    }
    if (ball->pos.x + ball->radius > width) {
        ball->pos.x = width - ball->radius;
        ball->vel.x = -ball->vel.x;
    }
    if (ball->pos.y - ball->radius < 0) {
        ball->pos.y = ball->radius;
        ball->vel.y = -ball->vel.y;
    }
    if (ball->pos.y + ball->radius > height) {
        ball->pos.y = height - ball->radius;
        ball->vel.y = -ball->vel.y;
    }
}

 
// Function to check if two balls are colliding
int checkBallCollision(Ball *ball1, Ball *ball2) {
    // Find the vector pointing from ball2 to ball1
    Vector delta = subtr(ball1->pos, ball2->pos);
    // Calculate the distance between ball1 and ball2
    double distance = mag(delta);
    // If the distance is less than the sum of their radii, they are colliding
    if (distance < ball1->radius + ball2->radius) {
        return 1;
    }
    // If the distance is not less than the sum of their radii, they are not colliding
    return 0;
}

// Function to handle the collision between two balls
void handleBallCollision(Ball *ball1, Ball *ball2) {
    // Find the vector pointing from ball2 to ball1
    Vector delta = subtr(ball1->pos, ball2->pos);
    // Normalize the delta vector to get the normal vector
    Vector normal_ = normal(delta);
    // Get the unit normal vector
    Vector unit_normal = unit(normal_);
    // Get the unit tangent vector
    Vector unit_tangent = newVector(-unit_normal.y, unit_normal.x);

    // Calculate the dot product of each ball's velocity with the unit normal and unit tangent vectors
    double v1_n = dot(ball1->vel, unit_normal);
    double v2_n = dot(ball2->vel, unit_normal);
    double v1_t = dot(ball1->vel, unit_tangent);
    double v2_t = dot(ball2->vel, unit_tangent);

    // Use the dot products and the masses of the balls to calculate their new normal velocities
    double u1_n = (v1_n * (ball1->radius - ball2->radius) + 2 * ball2->radius * v2_n) / (ball1->radius + ball2->radius);
    double u2_n = (v2_n * (ball2->radius - ball1->radius) + 2 * ball1->radius * v1_n) / (ball1->radius + ball2->radius);

    // Use the new normal and tangential velocities to find the new velocity vectors for each ball
    ball1->vel = add(mult(unit_tangent, v1_t), mult(unit_normal, u1_n));
    ball2->vel = add(mult(unit_tangent, v2_t), mult(unit_normal, u2_n));
}
