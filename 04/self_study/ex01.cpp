#include <iostream>
#include <vector>
using namespace std;

void	func(vector<int> &vec)
{
	for (auto x : vec)
	{
		if (x % 2 == 0)
			x /= 2;
		else
			x *= 2;
	}
}

void	func2(vector<int> &vec)
{
	double ave = 0;
	for (auto x : vec)
	{
		ave += x;
	}
	ave /= vec.size();

	int cnt = 0;
	for (auto x : vec)
	{
		if (x >= ave)
			cnt++;
	}
	cout << "平均より大きい個数は" << cnt << endl;
}

int	func3(int an, int xn)
{
	int a = an + xn;
	if (a % 10 == 0)
		return (1);
	else
		return (0);
}

int	func4(vector<int> &a)
{
	vector<int> x(10);
	for (auto val : a)
		x[val]++;
	
	int ans = -1, cnt = -1;
	for (int i = 0; i < 10; i++)
	{
		if (x[i] > cnt)
			ans = i;
	}
	return (ans);
}
