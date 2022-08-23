#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, res = 0;
	cin >> n;

	vector<int> vec(n+1);
	vector<int> dp(n + 1);

	for (int i = 1; i <= n; i++)
	{
		cin >> vec[i];
	}

	dp[1] = vec[1];
	dp[2] = vec[1] + vec[2];
	dp[3] = max(vec[1], vec[2]) + vec[3];

	for (int i = 4; i <= n; i++)
	{
		// 두 계단을 오른 후 한 계단을 오르거나
		// 두 계단을 올랐을 때 바로 n번째 계단에 도착
		dp[i] = max(dp[i-3] + vec[i-1], dp[i-2]) + vec[i];
	}

	cout << dp[n];

	return 0;
}