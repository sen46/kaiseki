#include "../../LinearAlgebra/LinearAlgebra.hpp"

using vvd = vector<vector<double>>;
using vd = vector<double>;

const int n = 6;

vvd	A_init()
{
	vvd	a(n, vd(n));

	for (int i = 0; i < n; i++)
		a[0][i] = 9 - i;
	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i > j)
				a[i][j] = a[i - 1][j] - 1;
			else
				a[i][j] = a[i - 1][j];
		}
	}
	return (a);
}

vd	b_init()
{
	vd	b(n);

	for (int i = 0; i < n; i++)
		b[i] = 1;
	return (b);
}

int main()
{
	vvd a = A_init();
	vd  b = b_init();
	PrintMatrix(a);

	PowerMethod(a, b);
	RayleighQuotient(a, b);
	return (0);
}
