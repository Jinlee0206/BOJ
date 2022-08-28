#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Data
{
	int weight;
	int value;

	Data(int a, int b)
	{
		weight = a;
		value = b;
	}
};

// 1차원 배열 냅색
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, k;
	cin >> n >> k;

	vector<Data> vec;
	vector<int> dp(k + 1, 0);

	for (int i = 0; i < n; i++)
	{
		int w, v;
		cin >> w >> v;
		vec.push_back(Data(w,v));
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = k; j >= 1; j--)
		{
			if(vec[i].weight <= j)	dp[j] = max(dp[j], dp[j - vec[i].weight] + vec[i].value);
		}
	}

	cout << dp[k] << "\n";

	return 0;
}

// 2차원 배열 냅색

/*
int dp[101][100001];
int w[101];
int v[101];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, k;
	cin >> n >> k;

	for (int i = 1; i <= n; i++)
	{
		cin >> w[i] >> v[i];
	}
	
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= k; j++)
		{
			if (w[i] <= j) dp[i][j] = max(dp[i - 1][j - w[i]] + v[i], dp[i - 1][j]);
			else dp[i][j] = dp[i - 1][j];
		}
	}

	cout << dp[n][k] << "\n";

	return 0;
}
*/