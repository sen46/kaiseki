#include <cstdio>
#include <cmath>
#include <vector>

using namespace std;

using vd = vector<double>;
double f(double x)
{
	double res = x * x * x * x * x - 4;
	return (res);
}

double df(double x)
{
	double res = 5 * x * x * x * x;
	return (res);
}
int main()
{
	int		M = 50;
	double	alpha = pow(4.0, 0.2);
	double	epsilon = 1e-12;
	vd		a(M + 1), b(M + 1);
	vd		ea(M), eb(M);

	// 初期値が0.35の処理
	a[0] = 0.35;
	for (int i = 0; i < M; i++)
	{
		a[i + 1] = a[i] - f(a[i]) / df(a[i]);
		if (f(a[i + 1]) > -epsilon && f(a[i + 1]) < epsilon)
		{
			printf("配列aは初期値が0.35\n");
			printf("反復回数が%d回でa[%d] = %.10e\n", i + 1, i + 1, a[i + 1]);

			// (2)
			for (int j = 0; j <= i + 2; j++)
				ea[j] = fabs(a[j] - alpha);

			for (int j = 2; j >= 0; j--)
			{
				double p = log10(ea[i + 1 - j]) / log10(ea[i + 1 - j - 1]);
				printf("k = N - %d, |e_k| = %.2e, p = %.2e\n", j, ea[i + 1 - j], p);
			}
			break;
		}
	}

	printf("\n\n");
	// 初期値が1.1の処理
	b[0] = 1.1;
	for (int i = 0; i < M; i++)
	{
		b[i + 1] = b[i] - f(b[i]) / df(b[i]);
		if (f(b[i + 1]) > -epsilon && f(b[i + 1]) < epsilon)
		{
			printf("配列bは初期値が1.1\n");
			printf("反復回数が%d回でb[%d] = %.10e\n", i + 1, i + 1, b[i + 1]);

			for (int j = 0; j <= i + 2; j++)
				eb[j] = fabs(b[j] - alpha);

			// (2)
			for (int j = 2; j >= 0; j--)
			{
				double p = log10(eb[i + 1 - j]) / log10(eb[i + 1 - j - 1]);
				printf("k = N - %d, |e_k| = %.2e, p = %.2e\n", j, eb[i + 1 - j], p);
			}
			break;
		}
	}

	return (0);
}
