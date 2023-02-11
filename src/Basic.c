

double sqrt2(double x) {
    int i = *(int*)&x;
    i = (i >> 1) + 0x1fc00000;
    return *(double*)&i;
}
