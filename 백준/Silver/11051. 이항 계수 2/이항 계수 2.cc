#include<bits/stdc++.h>

using namespace std;
int n, k;
int dp[1001][1001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, k;
	cin >> n >> k;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j <= k; j++)
		{
			if (j == 0 || i == j) dp[i][j] = 1;
			else dp[i][j] = (dp[i - 1][j] + dp[i - 1][j - 1]) % 10007;
		}
	}

	cout << dp[n][k] << '\n';

	return 0;
}