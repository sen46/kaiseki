#include <iostream>

using namespace std;

int main()
{
	int	n;
	int	cnt = 0;;
	cout << "500以下の自然数を入力してください" << endl;
	cin >> n;
	for (int i = 1; i <=n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			int	k = n - i - j;
			if (k >= 1)
			{
				// printf ("(%d, %d, %d)\n", i, j, k);
				cnt++;
			}
		}
	}
	cout << cnt << endl;
}
