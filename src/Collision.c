#include "Collision.h"



// Define a function that can detect if two balls are colliding
int bingIs_colliding(Ball* b1, Ball* b2) {
  // Calculate the distance between the centers of the balls
  Vector d = subtr(b1->pos, b2->pos);
  double distance = mag(d);

  // Check if the distance is less than or equal to the sum of the radii
  if (distance <= b1->radius + b2->radius) {
    return 1; // collision detected
  } else {
    return 0; // no collision
  }
}



// Define a function that can handle the collision of two balls
void bingHandle_collision(Ball *b1, Ball *b2) {
  // Calculate the unit vector pointing from ball 1 to ball 2
  Vector d = subtr(b2->pos, b1->pos);
  double distance = mag(d);
  Vector unit_vector = normal(d);

  // Calculate the dot product of the velocity vectors and the unit vector
  double v1 = dot(b1->vel, unit_vector);
  double v2 = dot(b2->vel, unit_vector);

  // Calculate the new velocities based on the conservation of momentum and energy
  // Assume a perfectly elastic collision (coefficient of restitution = 1)
  double v1_new = v2;
  double v2_new = v1;

  // Update the velocity vectors by adding the difference between the new and old velocities
  Vector v1_difference = mult(unit_vector, (v1_new - v1));
  Vector v2_difference = mult(unit_vector, (v2_new - v2));

  b1->vel = add(b1->vel, v1_difference);
  b2->vel = add(b2->vel, v2_difference);
}

// // Define a function that can update the position and velocity of a ball
// void update_ball(Ball *b, double dt) {
//   // Update the position based on the velocity and the time step
//   Vector dp = mult(b->vel, dt);
//   b->pos = add(b->pos, dp);

// }
