#include <cmath>
#include <cstdio>
#include <vector>
using namespace std;

// secant 公式
// x_(k+1) = x_(k) - f(x_k) * (x_k - x_(k-1)) / (f(x_k) - f(x_(k-1)))
static double f(double x)
{
	double res = x * x * x + 6 * x + 4;
	return (res);
}

static double secantff(double x_k, double x_k_1)
{
	double res1 = x_k - x_k_1;
	double res2 = f(x_k) - f(x_k_1);
	return (res1 / res2);
}

void	Secant_method(double a0, double a1)
{
	int M = 50;
	vector<double> x(M + 1);
	x[0] = a0;
	x[1] = a1;

	double epsilon = 1e-12;
	for (int i = 0; i < M; i++)
	{
		x[i + 2] = x[i + 1] - f(x[i + 1]) * (secantff(x[i + 1], x[i]));
		if (f(x[i + 2]) < epsilon && f(x[i + 2]) > -epsilon)
		{
			printf("x[%d] = %.12e\n", i + 2, x[i + 2]);
			break;
		}
	}
}

int main()
{
	// 一つ目の引数が0項目(初期値)、2つ目の引数が1項目(初期値)
	Secant_method(0, 1);
}
