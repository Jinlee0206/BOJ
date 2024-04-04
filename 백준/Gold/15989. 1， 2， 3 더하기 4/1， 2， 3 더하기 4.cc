// BOJ - 15989 : 1, 2, 3 더하기 4
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll t, n, dp[10001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> t;
	dp[0] = 1;

	// 1로 만드는 경우의 수 위에 2로 만드는 경우의 수, 3으로 만드는 경우의 수를 더해 나가기
	for (int i = 1; i <= 3; i++)
	{
		for (int j = 0; j <= 10000; j++)
		{
			if (j - i >= 0) dp[j] += dp[j - i];
		}
	}

	while (t--)
	{
		cin >> n;
		cout << dp[n] << '\n';
	}

	return 0;
}