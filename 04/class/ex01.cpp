// スライド8枚目くらいの問題
#include <cmath>
#include <cstdio>
#include <vector>
using namespace std;

double f(double x)
{
	double res = 2 * x * x * x - 3 * x - exp(x);
	return (res);
}

double secantff(double x_k, double x_k_1)
{
	double res1 = x_k - x_k_1;
	double res2 = f(x_k) - f(x_k_1);
	return (res1 / res2);
}

int main()
{
	int M = 50;
	vector<double> x(M + 1);
	x[0] = 4;
	x[1] = 3.5;
	
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
	return (0);
}
