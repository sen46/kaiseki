#include "LinearAlgebra/LinearAlgebra.hpp"

void	solve(void)
{
	vector<vector<vector<double>>> a(101, vector<vector<double>>(2, vector<double>(2)));
	a[0][0][0] = 1;
	a[0][0][1] = 1;
	a[0][1][0] = 1;
	a[0][1][1] = 0;

	for (int i = 1; i <= 100; i++)
	{
		a[i] = MatrixMultiplication(a[i - 1], a[i - 1]);
	}
	for (int i = 0; i <= 100; i++)
	{
		printf("i = %d\n", i);
		// i >= 10でinfになる
		PrintMatrix(a[i]);
	}
}

int main()
{
	solve();
}
