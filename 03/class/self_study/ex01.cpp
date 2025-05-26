#include <iostream>
using namespace std;

int my_gcd(int n, int m);
int my_lcm(int n, int m);

int main()
{
	cout << my_gcd(121, 77) << endl;
	cout << my_lcm(3, 5) << endl;
}

int my_gcd(int n, int m)
{
	int p, r;
	int ans;
	if (n < m)
	{
		n ^= m;
		m ^= n;
		n ^= m;
	}

	p = m;
	r = n % m;
	if (r == 0)
	{
		return (m);
	}
	else
	{
		ans = my_gcd(p, r);
	}
	return (ans);
}

int my_lcm(int n, int m)
{
	int g = my_gcd(n, m);
	return (n * m / g);
}
