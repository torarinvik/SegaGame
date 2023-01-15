#define fabs(x) (x < 0 ? -x : x)

double sqrt2(double x) {
    double approx = x;
    double prev_approx;
    do {
        prev_approx = approx;
        approx = 0.5 * (approx + x / approx);
    } while (fabs(approx - prev_approx) > 0.00001);
    return approx;
}
double floatMin(double x, double y) {
    return x < y ? x : y;
}