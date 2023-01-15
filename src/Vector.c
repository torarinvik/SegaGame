#include "Vector.h"


/* double fabs(double x) {
    return x < 0 ? -x : x;
} */






Vector add(Vector self, Vector vec) {
    Vector result;
    result.x = self.x + vec.x;
    result.y = self.y + vec.y;
    return result;
}

Vector subtr(Vector self, Vector vec) {
    Vector result;
    result.x = self.x - vec.x;
    result.y = self.y - vec.y;
    return result;
}

double mag(Vector self) {
    return sqrt2(self.x * self.x + self.y * self.y);
}

Vector mult(Vector self, double n) {
    Vector result;
    result.x = self.x * n;
    result.y = self.y * n;
    return result;
}

Vector normal(Vector self) {
    Vector result;
    result.x = -self.y;
    result.y = self.x;
    return result;
}

Vector unit(Vector self) {
    double mag_ = mag(self);
    Vector result;
    if (mag_ == 0) {
        result.x = 0;
        result.y = 0;
    } else {
        result.x = self.x / mag_;
        result.y = self.y / mag_;
    }
    return result;
}

double dot(Vector vec1, Vector vec2) {
    return vec1.x * vec2.x + vec1.y * vec2.y;
}

Vector new_vector(double x, double y) {
    Vector v;
    v.x = x;
    v.y = y;
    return v;
}