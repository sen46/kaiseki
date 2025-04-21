#include <stdio.h>

int main()
{
    double a = 1.1;
    double b = 1.2;
    double c = 1.3;

    double l = (a + b) + c;
    double r = a + (b + c);

    printf("l = %.16e\nr = %.16e", l, r);
    // cout << "l = " << l << endl;
    // cout << "r = " << r << endl;
    return (0);
}
