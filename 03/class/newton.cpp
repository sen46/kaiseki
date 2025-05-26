#include <cstdio>
#include <cmath>

// Newton公式
// x_(k+1) = x_k - f(x_k) / f'(x_k)
double f(double x)
{
	return (2 * x * x * x - 3 * x - exp(x));
}

double df(double x)
{
	return (6 * x * x - 3 - exp(x));
}

void NewtonMethod(double x0)
{
	int M = 50;
	// double x0 = 1;
	double x_n[M + 1];
	x_n[0] = x0;
	double epsilon = 1e-12;

	for (int i = 0; i < M; i++)
	{
		x_n[i + 1] = x_n[i] - f(x_n[i]) / df(x_n[i]);
		if (f(x_n[i + 1]) < epsilon && -epsilon < f(x_n[i + 1]))
		{
			printf("x_n[0] = %.2fのとき、x_[%d] = %.12e\n", x0, i + 1, x_n[i + 1]);
			return ;
		}
	}
	printf("収束しない\n");
}

int main()
{
	NewtonMethod(4.0);
	NewtonMethod(1.0);
	return (0);
}
