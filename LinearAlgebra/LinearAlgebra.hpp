#ifndef LinearAlgebra_hpp
# define LinearAlgebra_hpp

#include <stdio.h>
#include <vector>
#include <cmath>

using namespace std;

//
void			PrintVector(vector<double> vec);
//
void			PrintMatrix(vector<vector<double>> vec);
//
vector<double>	VectorSubstract(vector<double> vec1, vector<double> vec2);
//
vector<double>	MatrixVector(vector<vector<double>> A, vector<double> x);
//
vector<double>	ResidualError(vector<vector<double>> A, vector<double> x, vector<double> b);
//
double			vectorNorm1(vector<double> vec);
//
double			VectorNorm2(vector<double> vec);
//
double			VectorNormInfinity(vector<double> vec);
//
double			MatrixNorm1(vector<vector<double>> vec);
//
double			MatrixNormInfinity(vector<vector<double>> vec);

#endif
