// BOJ - 1315 : RPG
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

int n, q[54][3], dp[1004][1004];
bool visited[54];

// str, int를 상태값으로 설정
int cal(int a, int b)
{
	if (dp[a][b] != -1) return dp[a][b];
	int point = 0;
	dp[a][b] = 0;
	vector<int> check;
	for (int i = 0; i < n; i++)
	{
		if (q[i][0] <= a || q[i][1] <= b)
		{
			dp[a][b] += 1;
			if (visited[i]) continue;
			point += q[i][2];
			visited[i] = true;
			check.push_back(i);
		}
	}

	for (int i = 0; i <= point; i++)
	{
		dp[a][b] = max(dp[a][b], cal(min(1000, a + i), min(1000, b + point - i)));
	}

	for (int i = 0; i < check.size(); i++)
	{
		visited[check[i]] = false;
	}
	return dp[a][b];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	memset(dp, -1, sizeof(dp));
	for (int i = 0; i < n; i++)
	{
		cin >> q[i][0] >> q[i][1] >> q[i][2];
	}
	cout << cal(1, 1);

	return 0;
}