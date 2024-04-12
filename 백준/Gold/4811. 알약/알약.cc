// BOJ - 4811 : 알약
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;
ll dp[34][34];

ll go(int whole, int half)
{
	if (whole == 0 && half == 0) return 1;
	if (dp[whole][half]) return dp[whole][half];
	ll& res = dp[whole][half];
	if (whole > 0) res += go(whole - 1, half + 1);
	if (half > 0) res += go(whole, half - 1);
	return res;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	while (true)
	{
		memset(dp, 0, sizeof(dp));
		cin >> n;
		if (n == 0) return 0;

		cout << go(n, 0) << '\n';
	}
	return 0;
}