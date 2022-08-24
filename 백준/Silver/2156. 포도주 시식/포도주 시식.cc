#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	vector<int> vec(n + 1);
	vector<int> dp(n + 1, 0);

	for (int i = 1; i <= n; i++)
	{
		cin >> vec[i];
	}

	dp[1] = vec[1];
	dp[2] = vec[1] + vec[2];

	for (int i = 3; i <= n; i++)
	{
		dp[i] = max(dp[i - 1], max(dp[i - 2] + vec[i], dp[i - 3] + vec[i - 1] + vec[i]));
	}

	cout << dp[n] << "\n";

	return 0;
}