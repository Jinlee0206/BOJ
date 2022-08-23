#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int tri[501][501];
int dp[501][501];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, res = 0;
	cin >> n;


	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < i+1; j++)
		{
			cin >> tri[i][j];
		}
	}

	/*for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << tri[i][j] << " ";
		}
		cout << "\n";
	}*/

	dp[0][0] = tri[0][0];

	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j < i+1; j++)
		{
			if (j == 0) dp[i][j] = dp[i-1][j] + tri[i][j];
			else if (j == i) dp[i][j] = dp[i - 1][j - 1] + tri[i][j];
			else dp[i][j] = max(dp[i - 1][j - 1], dp[i-1][j]) + tri[i][j];
		}
	}

	for (int i = 0; i < n; i++)
	{
		if (res < dp[n - 1][i]) res = dp[n - 1][i];
	}

	cout << res << "\n";

	return 0;
}