// page.7
#include <cmath>
#include <cstdio>

double f(double x)
{
	return (x * x * x + 2 * x - 5);
}

double g(double x)
{
	return (exp(x) - 2 * x);
}

int main()
{
	printf("f(0)=%.5e \n", f(0));
	printf("f(3)=%.5e \n", f(3));
	printf("g(0)=%.5e \n", g(0));
	printf("g(3)=%.5e \n", g(3));
}
