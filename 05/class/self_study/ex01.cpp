#include <iostream>
#include <vector>

using namespace std;

// めんどくさいからメイン関数書いてない

// (1) 平均より大きいものを出力
void	func1(vector<double> vec)
{
	double ave = 0;
	
	for (int i = 0; i < (int)vec.size(); i++)
		ave += vec[i];

	for (auto x : vec)
	{
		if (x > ave)
			cout << x << "\t";
	}
}

// (2)
void	func2(void)
{
	vector<int> x(101);
	x[0] = 1;
	x[1] = 1;

	for (int i = 1; i < 100; i++)
		x[i + 1] = x[i] * x[i] + x[i - 1] * x[i - 1];

	printf("x[%d] = %d", 100, x[100]);
}

// (3) 累積和
void	func3(vector<double> a)
{
	int sz = a.size();
	vector<double> b(sz);

	b[0] = a[0];
	for (int i = 1; i <= sz; i++)
		b[i] = b[i - 1] + a[i];

	for (auto x : b)
		cout << x << "\t";
}

// (4) 力不足でできませんでした
// void	func4()
