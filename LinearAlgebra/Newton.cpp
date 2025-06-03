#include <cstdio>
#include <cmath>

// Newton公式
// x_(k+1) = x_k - f(x_k) / f'(x_k)
static double f(double x)
{
	return (exp(-x) + sin(4 * x) - 6 * x);
}

static double df(double x)
{
	return (-exp(-x) + 4 * cos(4 * x) - 6);
}

void NewtonMethod(double x0)
{
	int M = 50;
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
	// 初期値が引数となる
	NewtonMethod(4.0);
	return (0);
}
