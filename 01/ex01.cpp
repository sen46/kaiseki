#include <stdio.h>
#include <math.h>

int main()
{
    double d = 1;

    for (double i = 0; i < 29; i++)
    {
        d = 1 + (2 / (1 + d));
        if (i >= 23)
        {
            printf("%.18e\n", d);
            // printf("%.2e\n", abs(d - sqrt(3)));
        }
    }
    return (0);
}
