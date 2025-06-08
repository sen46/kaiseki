#include "../LinearAlgebra/LinearAlgebra.hpp"

const int n = 6;

vector<vector<double>>	A_init()
{
	vector<vector<double>>	A(n, vector<double> (n));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			A[i][j] = 2 +  (n + j - i) % n;
		}
	}
	// printf("生成されたA=\n");
	// PrintMatrix(A);
	printf("\n");
	return (A);
}

vector<double>	b_init()
{
	vector<double> b(n);
	for (int i = 0; i < n; i++)
	{
		b[i] = i;
	}
	// printf("生成されたb=\n");
	// PrintVector(b);
	printf("\n");
	return (b);
}

int main()
{
	vector<vector<double>>	A = A_init();
	vector<double>			b = b_init();

	vector<double>			x = LUDecomposition(A, b);
	printf("x=\n");
	PrintVector(x);
	return (0);
}

