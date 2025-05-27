#include "./LinearAlgebra/LinearAlgebra.hpp"

vector<vector<double>>	A_init()
{
	int n = 7;

	vector<vector<double>> A(n, vector<double>(n));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i == j)
				A[i][j] = 8;
			else if (abs(i - j) <= 2)
				A[i][j] = 1;
			else
				A[i][j] = 0;
		}
	}
	return (A);
}

vector<double>	b_init()
{
	int n = 7;
	vector<double> b(n);
	for (int i = 0; i < n; i++)
	{
		b[i] = 1;
	}
	return (b);
}

int main()
{
	vector<vector<double>> A = A_init();
	vector<double> b = b_init();

	// (1)
	double norm1 = MatrixNorm1(A);
	double norm2 = MatrixNormInfinity(A);
	printf("||A||_1 = %.3e, ||A||_(inf) = %.3e\n\n", norm1, norm2);

	// (2), (3)
	vector<double> x = GaussianElimination(A, b);
	printf("x=");
	PrintVector(x);

	// (4)
	vector<double> error = ResidualError(A, x, b);
	double vec_norm1 = VectorNorm1(error);
	double vec_norm2 = VectorNorm2(error);
	double vec_norm_inf = VectorNormInfinity(error);
	printf("\nnorm1 = %.3e, norm2 = %.3e, norm_inf = %.3e\n", vec_norm1, vec_norm2, vec_norm_inf);
	return (0);
}
