// 問1-1〜問1-3
#include <iostream>
#include <stdio.h>
#include <vector>
#include <time.h>
#include <cstdlib>

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

int	vec_sum(vector<int> v)
{
	int sum = 0;
	for (auto x : v)
		sum += x;
	return (sum);
}

double	vec_ave(vector<int> v)
{
	int n = v.size();
	int sum = vec_sum(v);
	double res = (double)sum / (double)n;
	return (res);
}

int main()
{
	vector<int> v = generate_vector();
	// 配列の和
	int sum = vec_sum(v);
	// 平均
	double ave = vec_ave(v);
	// 出力
	cout << "ランダムな自然数で生成れた配列は\n";
	for (auto x : v)
		cout << x << '\t';
	cout << '\n';
	printf("合計は%d、平均は%lf\n", sum, ave);
}
