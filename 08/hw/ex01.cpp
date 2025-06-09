#include "../../LinearAlgebra/LinearAlgebra.hpp"
#include <iostream>

using namespace std;

using vd = vector<double>;
using vvd = vector<vector<double>>;

const int n = 30;
vvd	A_init(int a)
{
	vvd	m(n, vd(n));

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i == j)
				m[i][j] = a;
			else if (abs(i - j) <= 2)
				m[i][j] = 1;
			else
				m[i][j] = 0;
		}
	}
	return (m);
}

vd	b_init()
{
	vd b(n, 1);

	return (b);
}

int main()
{
	int a;
	cin >> a;

	vvd A = A_init(a);
	vd b = b_init();

	vd	xj = JacobiMethod(A, b);
	vd	xg = GaussSeidelMethod(A, b);
	printf("\n\n\nJacobi法 x[0] = %.2e", xj[0]);
	printf(", Gauss-Sidel法 x[0] = %.2e\n", xg[0]);
	return (0);
}
