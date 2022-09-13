#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 구간 합 구하기
// 투포인터 알고리즘
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;

	vector<int> dp(n+1);
	dp[0] = 0;
	for (int i = 1; i <= n; i++)
	{
		int a;
		cin >> a;
		dp[i] = dp[i - 1] + a;
	}

	for (int k = 0; k < m; k++)
	{
		int i, j, sum = 0;
		cin >> i >> j;

		cout << dp[j] - dp[i - 1] << "\n";
	}

	return 0;
}