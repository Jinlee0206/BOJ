#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, max = 0, res = 1;
	cin >> n;

	vector<int> vec(n + 1);
	vector<int> dp(n + 1, 0);

	for (int i = 1; i <= n; i++)
	{
		cin >> vec[i];
	}

	dp[1] = 1;

	for (int i = 2; i <= n; i++)
	{
		max = 0;
		for (int j = 1; j < i; j++)
		{
			if (vec[i] > vec[j] && dp[j] > max) max = dp[j];
		}
		dp[i] = max + 1;

		if (res < dp[i]) res = dp[i];
	}

	cout << res << "\n";

	return 0;
}