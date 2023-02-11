#ifndef VECTOR_H
#define VECTOR_H

#include "Basic.h"
typedef struct Vector {
    double x;
    double y;
} Vector;

Vector add(Vector self, Vector vec);

Vector subtr(Vector self, Vector vec);
    
double mag(Vector self);

Vector mult(Vector self, double n);

Vector normal(Vector self);

Vector unit(Vector self);

double dot(Vector vec1, Vector vec2);

Vector newVector(double x, double y);

#endif
