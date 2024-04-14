// BOJ - 1535 : 안녕
#include <bits/stdc++.h>
using namespace std;
int n, dp[101], L[101], J[101];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;

	for (int i = 0; i < n; i++) cin >> L[i];
	for (int i = 0; i < n; i++) cin >> J[i];
	for (int i = 0; i < n; i++)
	{
		for (int j = 100; j > L[i]; j--)
		{
			dp[j] = max(dp[j], dp[j - L[i]] + J[i]);
		}

		/*
		for (int l = 0; l < 100; l++)
		{
			cout << dp[l] << ' ';
		}
		cout << '\n';
		*/
	}
	cout << dp[100] << '\n';

	return 0;
}