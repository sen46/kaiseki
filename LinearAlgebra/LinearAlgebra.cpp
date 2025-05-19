#include "LinearAlgebra.hpp"
#include <cmath>

void	PrintVector(vector<double> vec)
{
	for (int i = 0; i < (int)vec.size(); i++)
		printf("%.2e\t", vec[i]);
	printf("\n");
}

void	PrintMatrix(vector<vector<double>> vec)
{
	for (int i = 0; i < (int)vec.size(); i++)
	{
		for (int j = 0; j < (int)vec[i].size(); j++)
			printf("%.2e\t", vec[i][j]);
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
		Ax[i] -= b[i]; return (Ax);
}

vector<double>	MatrixVector(vector<vector<double>> A, vector<double> x)
{
	unsigned long	n;
	vector<double>	res;

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
		norm = max(norm, vec[i]);
	return (norm);
}

double	MatrixNorm1(vector<vector<double>> vec)
{
	double	norm;
	double	x;
	size_t	n;

	norm = 0;
	n = vec.size();
	for (int i = 0; i < n; i++)
	{
		x = 0;
		for (int j = 0; j < n; j++)
			x += vec[j][i];
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
