#include "LinearAlgebra.hpp"

void	PrintVector(vector<double> vec)
{
	for (int i = 0; i < (int)vec.size(); i++)
		printf("%10.2e\t", vec[i]);
	printf("\n");
}

void	PrintMatrix(vector<vector<double>> vec)
{
	for (int i = 0; i < (int)vec.size(); i++)
	{
		for (int j = 0; j < (int)vec[i].size(); j++)
			printf("%10.2e\t", vec[i][j]);
		printf("\n");
	}
	printf("\n");
}

vector<double>	VectorSubstract(vector<double> vec1, vector<double> vec2)
{
	for (int i = 0; i < (int)vec1.size(); i++)
		vec1[i] -= vec2[i];
	return (vec1);
}

vector<double>	ResidualError(vector<vector<double>> A, vector<double> x, vector<double> b)
{
	vector<double>	Ax;

	Ax = MatrixVector(A, x);
	for (int i = 0; i < (int)Ax.size(); i++)
		Ax[i] -= b[i];
	return (Ax);
}

vector<double>	MatrixVector(vector<vector<double>> A, vector<double> x)
{
	int				n;
	vector<double>	res((int)x.size());

	n = A.size();
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < (int)A[i].size(); j++)
			res[i] += A[i][j] * x[j];
	}
	return (res);
}

double	VectorNorm1(vector<double> vec)
{
	double	norm;

	norm = 0;
	for (int i = 0; i < (int)vec.size(); i++)
		norm += fabs(vec[i]);
	return (norm);
}

double	VectorNorm2(vector<double> vec)
{
	double	norm;

	norm = 0;
	for (int i = 0; i < (int)vec.size(); i++)
		norm += vec[i] * vec[i];
	norm = sqrtf(norm);
	return (norm);
}


double	VectorNormInfinity(vector<double> vec)
{
	double	norm;

	norm = 0;
	for (int i = 0; i < (int)vec.size(); i++)
		norm = max(norm, fabs(vec[i]));
	return (norm);
}

double	MatrixNorm1(vector<vector<double>> vec)
{
	double	norm;
	double	x;
	int		n;

	norm = 0;
	n = vec.size();
	for (int i = 0; i < n; i++)
	{
		x = 0;
		for (int j = 0; j < n; j++)
			x += fabs(vec[j][i]);
		norm = max(norm, x);
	}
	return (norm);
}

double	MatrixNormInfinity(vector<vector<double>> vec)
{
	double	norm;
	double	x;

	norm = 0;
	for (int i = 0; i < (int)vec.size(); i++)
	{
		x = 0;
		for (int j = 0; j < (int)vec[i].size(); j++)
			x += fabs(vec[i][j]);
		norm = max(norm, x);
	}
	return (norm);
}

vector<double>	BackwardSubstitution(vector<vector<double>> A, vector<double> b)
{
	int				N = (int)b.size();
	vector<double>	x(N);

	for (int i = N - 1; i >= 0; i--)
	{
		x[i] = b[i];
		double tmp = 0;
		for (int j = N - 1; j >= i + 1; j--)
			tmp += A[i][j] * x[j];
		x[i] -= tmp;
		x[i] = x[i] / A[i][i];
	}
	return (x);
}

vector<double>	GaussianElimination(vector<vector<double>> Matrix, vector<double> Vec)
{
	int						n = Vec.size();
	vector<vector<double>>	A = Matrix;
	vector<double>			b = Vec;

	double alpha = 0;

	for (int k = 0; k < n - 1; k++)
	{
		for (int i = k + 1; i < n; i++)
		{
			alpha = A[i][k] / A[k][k];
			for (int j = k; j < n; j++)
				A[i][j] -= alpha * A[k][j];
			b[i] -= alpha * b[k];
		}
	}

	printf("前進消去\nA=");
	PrintMatrix(A);
	printf("b=");
	PrintVector(b);

	printf("後退代入\n");
	vector<double> x(n);
	x = BackwardSubstitution(A, b);
	return (x);
}

vector<vector<double>>	MatrixMultiplication(vector<vector<double>> a, vector<vector<double>> b)
{
	int	ar = a.size();
	int	ac = a[0].size();
	int	br = b.size();
	int	bc = b[0].size();
	if (ac != br)
	{
		printf("定義不能");
		exit(-1);
	}
	vector<vector<double>> res(ar, vector<double>(bc));
	for (int i = 0; i < ar; i++)
	{
		for (int j = 0; j < bc; j++)
		{
			double tmp = 0;
			for (int k = 0; k < ac; k++)
				tmp += a[i][k] * b[k][j];
			res[i][j] = tmp;
		}
	}
	return (res);
}

vector<double>	LUDecomposition(vector<vector<double>> Matrix, vector<double> Vec)
{
	int						N = (int)Vec.size();
	vector<vector<double>>	A = Matrix;
	vector<double>			b = Vec;

	double alpha = 0;
	for (int k = 0; k < N - 1; k++)
	{
		for (int i = k + 1; i < N; i++)
		{
			alpha = A[i][k] / A[k][k];
			A[i][k] = alpha;
			for (int j = k + 1; j < N; j++)
				A[i][j] = A[i][j] - alpha * A[k][j];
		}
	}

	printf("LU分解行列\nA=");
	PrintMatrix(A);

	// 前進代入
	vector<double> y(N);
	y[0] = b[0];
	for (int k = 1; k < N; k++)
	{
		y[k] = b[k];
		for (int j = 0; j < k; j++)
			y[k] -= A[k][j] * y[j];
	}
	return (BackwardSubstitution(A, y));
}

vector<double>	JacobiMethod(vector<vector<double>> Matrix, vector<double> Vec)
{
	int				N = (int)Matrix.size();
	int				M = 100;
	double			epsilon = 1e-8;
	double			error;
	vector<double>	X_now(N);
	vector<double>	X_pre(N);
	X_now = Vec;
	X_pre = Vec;

	for (int m = 0; m < M; m++)
	{
		for (int i = 0; i < N; i++)
		{
			X_now[i] = Vec[i];
			for (int j = 0; j < N; j++)
			{
				if (i != j)
					X_now[i] -= Matrix[i][j] * X_pre[j];
			}
			X_now[i] /= Matrix[i][i];
		}
		error = VectorNormInfinity(VectorSubstract(X_now, X_pre)) / VectorNormInfinity(X_now);
		if (error < epsilon)
		{
			printf("ヤコビ法の反復回数は%d回\n", m + 1);
			PrintVector(X_now);
			return (X_now);
		}
		else
			X_pre = X_now;
	}
	printf("収束しません");
	return (X_now);
}

vector<double>	GaussSeidelMethod(vector<vector<double>> Matrix, vector<double> Vec)
{
	int				N = (int)Matrix.size();
	int				M = 100;
	double			epsilon = 1e-8;
	double			error;
	vector<double>	X_now(N);
	vector<double>	X_pre(N);
	X_now = Vec;
	X_pre = Vec;

	for (int m = 0; m < M; m++)
	{
		for (int i = 0; i < N; i++)
		{
			X_now[i] = Vec[i];
			for (int j = 0; j < N; j++)
			{
				if (j < i)
					X_now[i] -= Matrix[i][j] * X_now[j];
				else if (j > i)
					X_now[i] -= Matrix[i][j] * X_pre[j];
			}
			X_now[i] /= Matrix[i][i];
		}
		error = VectorNormInfinity(VectorSubstract(X_now, X_pre)) / VectorNormInfinity(X_now);
		if (error < epsilon)
		{
			printf("GS法の反復回数は%d回\n", m + 1);
			PrintVector(X_now);
			return (X_now);
		}
		else
			X_pre = X_now;
	}
	printf("収束しません");
	return (X_now);
}
