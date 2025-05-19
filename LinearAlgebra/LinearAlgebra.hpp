#ifndef LinearAlgebra_hpp
# define LinearAlgebra_hpp

#include <stdio.h>
#include <vector>

using namespace std;

// ベクトルを出力
void			PrintVector(vector<double> vec);
// 行列を出力
void			PrintMatrix(vector<vector<double>> vec);
// ベクトルの差を出力
vector<double>	VectorSubstract(vector<double> vec1, vector<double> vec2);
// 行列 * ベクトル を出力
vector<double>	MatrixVector(vector<vector<double>> A, vector<double> x);
// Ax - b
vector<double>	ResidualError(vector<vector<double>> A, vector<double> x, vector<double> b);
// ベクトルの1ノルム
double			vectorNorm1(vector<double> vec);
// ベクトルの2ノルム
double			VectorNorm2(vector<double> vec);
// ベクトルの無限ノルム
double			VectorNormInfinity(vector<double> vec);
// 行列の1ノルム
double			MatrixNorm1(vector<vector<double>> vec);
// 行列の2ノルム
double			MatrixNormInfinity(vector<vector<double>> vec);

#endif
