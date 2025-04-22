#include <stdio.h>
#include <cmath>

double f1(int n);
double f2(int n);

int main()
{
    int n;

    printf("(1)の答え\n");
    n = 20;
    printf("n = %dのときπ = %.16e\n", n, f1(n));
    n = 30;
    printf("n = %dのときπ = %.16e\n", n, f1(n));
    n = 40;
    printf("n = %dのときπ = %.16e\n", n, f1(n));

    printf("(2)の答え\n");
    n = 20;
    printf("n = %dのときπ = %.16e\n", n, f2(n));
    // n = 30;
    // printf("n = %dのときπ = %.16e\n", n, f2(n));
    n = 40;
    printf("n = %dのときπ = %.16e\n", n, f2(n));
}

double f1(int n)
{
    double r = 0;
    double sig = 1;
    double pw = 1;

    for (int i = 0; i <= n; i++)
    {
        r += sig / (pw * (2 * i + 1));
        sig = -sig;
        pw = pw * 3;
    }
    return (r * sqrt(12));
}

double f2(int n)
{
    double r = 0;
    double sig = 1;
    double pw = 1;

    for (int i = 0; i < n; i++)
    {
        pw *= 3;
    }

    for (int i = n; i >= 0; i--)
    {
        r += sig / (pw * (2 * i + 1));
        sig = -sig;
        pw = pw / 3;
    }
    return (r * sqrt(12));
}

