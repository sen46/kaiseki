#include <cstdio>
#include <cmath>
double f(double x)
{
	return ((x - 1) * (x - 1) - exp(-(x * x)));
}

double df(double x)
{
	return (2 * (x - 1) + 2 * x * exp(-(x * x)));
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
		// 以下の部分が黒塗りとして与えられている
		x_n[i + 1] = x_n[i] - f(x_n[i]) / df(x_n[i]);
		if (f(x_n[i + 1]) < epsilon && -epsilon < f(x_n[i + 1]))
		{
			printf("x_n[0] = %.2fのとき、x_[%d] = %.10e\n", x0, i + 1, x_n[i + 1]);
			printf("反復回数N - 3, 誤差|x_k - x_N = %.2e\n", -x_n[i] + x_n[i - 3]);
			printf("反復回数N - 2, 誤差|x_k - x_N = %.2e\n", -x_n[i] + x_n[i - 2]);
			printf("反復回数N - 1, 誤差|x_k - x_N = %.2e\n", -x_n[i] + x_n[i - 1]);
			return ;
		}
		// 黒塗りここまで
	}
	printf("収束しない\n");
}

int main()
{
	NewtonMethod(7.0);
	// NewtonMethod(1.0);
	return (0);
}
