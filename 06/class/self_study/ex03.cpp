#include <iostream>
#include <vector>

using namespace std;

int	Knapsack(vector<int> w, vector<int> v, int n, int W)
{
	vector<vector<int>> dp(n + 1, vector<int>(W + 9));
	
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j <= W + 3; j++)
		{
			dp[i][j] = dp[i - 1][j];
			if (j - w[i - 1] >= 0 && dp[i][j - w[i - 1]])
				dp[i][j] = max(dp[i][j], dp[i][j - w[i - 1]] + v[i - 1]);
		}
	}
	int tmp = -1;
	for (int i = 0; i <= W; i++)
		tmp = max(tmp, dp[n][i]);
	return (tmp);
}
