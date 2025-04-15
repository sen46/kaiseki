#include <cstdio>
#include <stdio.h>
#include <math.h>
#include <vector>

int main()
{
    std::vector<double> a(30);
    a[0] = 1;

    for (int i = 1; i < 30; i++)
    {
        a[i] = 1 + ((double)2 / (1 + a[i - 1]));
    }

    // No1の答え
    for (int i = 24; i < 30; i++)
    {
        printf("a_%d = %.18e\n", i, a[i]);
    }

    // No3の答え
    for (int i = 24; i < 30; i++)
    {
        printf("|a_%d - a| = %.2e\n", i, abs(a[i] - sqrt(3)));
    }
}
