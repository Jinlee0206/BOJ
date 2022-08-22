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

	vector<int> vec;
	vector<int> dp(n);

	for (int i = 0; i < n; i++)
	{
		int a;
		cin >> a;
		vec.push_back(a);
	}

	res = vec[0];

	for (int i = 0; i < n; i++)
	{
		dp[i] = vec[i];

		if (i == 0) continue;
		
		if (dp[i] < dp[i - 1] + vec[i]) dp[i] = dp[i - 1] + vec[i];

		if (dp[i] > res) res = dp[i];
	}

	cout << res << "\n";

	return 0;
}