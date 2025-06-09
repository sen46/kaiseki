#include "LinearAlgebra.hpp"

using vd = vector<double>;
using vvd = vector<vector<double>>;

int main()
{
	int n = 3;
	vd a(n);
	vvd A(n, vd(n));

	for (int i = 0; i < n; i++)
	{
		a[i] = 1;
		for (int j = 0; j < n; j++)
		{
			if (i == j)
				A[i][j] = 4;
			else
				A[i][j] = -1;
		}
	}
	printf("a= \n");
	PrintVector(a);
	printf("A= \n");
	PrintMatrix(A);
	JacobiMethod(A, a);
	GaussSeidelMethod(A, a);
	return (0);
}
