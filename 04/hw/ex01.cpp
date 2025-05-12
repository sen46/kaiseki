#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>

using namespace std;

double f(double x)
{
	double res = exp(x) - 7 * x;
	return (res);
}

double df(double x)
{
	double res = exp(x) - 7;
	return (res);
}

double secantff(double x, double y)
{
	double res1 = x - y;
	double res2 = f(x) - f(y);
	return (res1 / res2);
}

int main()
{
	double x0 = -2;
	double x1 = -1;

	int m = 50;
	double epsilon = 1e-12;
	vector<double> n(m), s(m);
	n[0] = x0;
	s[0] = x0;
	s[1] = x1;
	
	cout << "問1" << endl;
	for (int i = 1; i < m; i++)
	{
		n[i] = n[i - 1] - f(n[i - 1]) / df(n[i - 1]);
		if (f(n[i]) > -epsilon && f(n[i]) < epsilon)
		{
			printf("Newton n[%d] = %.12e\n", i, n[i]);
			break;
		}
	}

	for (int i = 2; i < m; i++)
	{
		s[i] = s[i - 1] - f(s[i - 1]) * secantff(s[i - 1], s[i - 2]);
		if (f(s[i]) > -epsilon && f(s[i]) < epsilon)
		{
			printf("Secant s[%d] = %.12e\n", i, s[i]);
			break;
		}
	}

	cout << "問2" << endl;
	printf("Newton\nN - 3 = %.12e\nN - 2 = %.12e\nN - 1 = %.12e\n", abs(n[1] - n[4]), abs(n[2] - n[4]), abs(n[3] - n[4]));
	printf("Secant\nN - 3 = %.12e\nN - 2 = %.12e\nN - 1 = %.12e\n", abs(s[1] - s[4]), abs(s[2] - s[4]), abs(s[3] - s[4]));

	return (0);
}
