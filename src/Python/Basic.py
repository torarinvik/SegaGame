def floatMin(x, y):
    return x if x < y else y
def sqrt2(x):
    approx = x
    prev_approx = None
    while prev_approx is None or abs(approx - prev_approx) > 1e-5:
        prev_approx = approx
        approx = 0.5 * (approx + x / approx)
    return approx