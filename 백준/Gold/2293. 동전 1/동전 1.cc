// BOJ - 2293 : 동전 1
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int INF = 2147000000;
int n, k, dp[10004], tmp;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> k;

	dp[0] = 1; // 아무것도 넣지않는 경우의 수 1
	for (int i = 0; i < n; i++)
	{
		cin >> tmp;
		for (int j = tmp; j <= k; j++)
		{
			dp[j] += dp[j - tmp];
		}

		/*for (int l = 0; l <= k; l++)
		{
			cout << dp[l] << " ";
		}
		cout << '\n';*/
		///
		/// dp  0 1 2 3 4 5 6 7 8 9 10
		///  1  1 1 1 1 1 1 1 1 1 1 1
		///  2  1 1 2 2 3 3 4 4 5 5 6
		///  5  1 1 2 2 3 4 5 6 7 8 10 
		///
	}

	cout << dp[k];
	return 0;
}