// ライブラリの使用方法
#include "LinearAlgebra.hpp"

using vd=vector<double>;
using vvd=vector<vd>;

// 前進消去法、後退代入が正しいかどうかの検証
int main()
{
	int n = 3;
	vd b(n);
	vvd a(n, vd(n));

	for (int i = 0; i < n; i++)
	{
		b[i] = 1;
		for (int j = 0; j < n; j++)
		{
			a[i][j] = -1;
			if (i == j)
				a[i][j] = 3;
		}
	}

	printf("A=");
	PrintMatrix(a);
	printf("b=");
	PrintVector(b);
	vd x(n);
	x = GaussianElimination(a, b);
	printf("x=");
	PrintVector(x);
}
