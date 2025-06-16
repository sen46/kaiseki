#include "LinearAlgebra.hpp"

using vd = vector<double>;
using vvd = vector<vector<double>>;

int main()
{
	vvd a = {
		{1, 1, 0},
		{1, 2, 1},
		{2, 5, 3},
	};
	vd b = {1, 1, 1};
	PowerMethod(a, b);
	RayleighQuotient(a, b);
	return (0);
}
