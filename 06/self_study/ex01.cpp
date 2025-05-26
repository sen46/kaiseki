#include "../../LinearAlgebra/LinearAlgebra.hpp"
#include <algorithm>

int main()
{
	vector<int> a = {1, 2, 3, 4, 5};
	do
	{
		for (int i = 0; i < 5; i++)
			printf("%d\t", a[i]);
		printf("\n");
	} while (next_permutation(a.begin(), a.end()));
}
