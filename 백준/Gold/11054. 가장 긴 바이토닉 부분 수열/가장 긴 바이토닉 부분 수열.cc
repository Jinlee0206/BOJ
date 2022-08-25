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
	vector<int> l_dp(n + 1, 0);
	vector<int> r_dp(n + 1, 0);

	for (int i = 1; i <= n; i++)
	{
		cin >> vec[i];
	}

	// 정방향 LIS
	l_dp[1] = 1;

	for (int i = 2; i <= n; i++)
	{
		max = 0;
		for (int j = 1; j < i; j++)
		{
			if (vec[i] > vec[j] && l_dp[j] > max) max = l_dp[j];
		}
		l_dp[i] = max + 1;
	}

	// 역방향 LIS
	r_dp[n] = 1;
	
	for (int i = n - 1; i >= 1; i--)
	{
		max = 0;
		for (int j = n; j > i; j--)
		{
			if (vec[i] > vec[j] && r_dp[j] > max) max = r_dp[j];
		}
		r_dp[i] = max + 1;
	}

	for (int i = 1; i <= n; i++)
	{
		l_dp[i] += r_dp[i];

		if (res < l_dp[i]) res = l_dp[i];
	}

	// 중복 값 제거 -1
	cout << res - 1 << "\n";

	return 0;
}