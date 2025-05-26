// page8
#include <cmath>
#include <cstdio>

double f(double x)
{
	return (x * x * x - exp(-x));
}

double g(double x)
{
	return (sin(2 * x) - 4 * x * x);
}

int main()
{
	printf("pi=%.4e \n", M_PI);
	printf("f(-2)=%.4e \n", f(-2));
	printf("f(pi)=%.4e \n", f(M_PI));
	printf("g(-2)=%.4e \n", g(-2));
	printf("g(pi)=%.4e \n", g(M_PI));
}
