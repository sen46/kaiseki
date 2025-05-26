#include <iostream>
#include <vector>

using namespace std;
void	rec(vector<int> v, int end)
{
	int n = v.size();
	if (n == end)
	{
		for (auto x : v)
			cout << x + 1 << '\t';
		cout << endl;
		return ;
	}
	for (int i = 0; i <= n; i++)
	{
		int k = 0;
		vector<int> next_vec(n + 1);
		for (int j = 0; j <= n; j++)
		{
			if (i == j)
				next_vec[j] = n;
			else
				next_vec[j] = v[k++];
		}
		rec(next_vec, end);
	}
}
void	my_permutation(int n)
{
	rec({}, n);
}

int main()
{
	my_permutation(5);
}
