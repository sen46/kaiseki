#include <cstdio>
#include <stdio.h>
#include <cmath>

int main()
{
    double x = 1e-7;
    double f = (1.0 - cos(x)) / (x * x);
    printf("f = %.16e\n", f);
    // 加法定理より 1 - cos(x) = 2 * sin(x / 2) * sin(x / 2);
    double g = (2 * sin(x / 2) * sin(x / 2)) / (x * x);
    printf("g = %.16e\n", g);
    return (0);
}
