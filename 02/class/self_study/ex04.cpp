#include <cstdlib>
#include <iostream>
#include <cstdio>
#include <vector>
#include <time.h>

using namespace std;

vector<int>	generate_vector(void)
{
	srand(time(NULL));

	// 変数の宣言や初期化
	int d = rand() % 81 + 20; // 20~100のランダムの値をdに代入
	// 大きさがdの配列を宣言
	vector<int> v(d);

	// 配列の値をrandomで初期化
	for (int i = 0; i < d; i++)
		v[i] = rand() % 100;
	return(v);
}

void	print_vec(vector<int> v)
{
	for (auto x : v)
		cout << x << '\t';
	cout << endl;
}

void	my_sort(vector<int> &vec)
{
	int n = vec.size();

	// バブルソートを使用
	for (int i = n - 1; i >= 0; i--)
	{
		for (int j = 0; j < i ; j++)
		{
			if (vec[j] < vec[j + 1])
			{
				// vec[j] と vec[j+1]をswap
				vec[j] ^= vec[j + 1];
				vec[j + 1] ^= vec[j];
				vec[j] ^= vec[j + 1];
			}
		}
	}
}
int main()
{
	vector<int> vec = generate_vector();

	cout << "before" << std::endl;
	print_vec(vec);

	// sortを行う
	my_sort(vec);

	cout << "after" << std::endl;
	print_vec(vec);
return (0);
}
