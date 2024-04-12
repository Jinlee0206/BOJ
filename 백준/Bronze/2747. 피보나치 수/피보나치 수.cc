// BOJ - 2747 : 피보나치 수
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, dp[50] = { 0, 1 };

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;

	dp[0] = 0;
	dp[1] = 1;

	for (int i = 2; i <= n; i++)
	{
		dp[i] = dp[i - 2] + dp[i - 1];
	}
	cout << dp[n] << '\n';

	return 0;
}