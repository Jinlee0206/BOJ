// BOJ - 1509 : 팰린드롬 분할
#include <bits/stdc++.h>
using namespace std;
const int INF = 2147000000;
int dp[2504][2504]; // 시작지점과 팰린드롬의 사이즈를 상태값으로 가짐
int dp2[2504];		// 분할의 최소개수를 찾기위한 dp배열
string str;

int go(int here)
{
	if (here == str.size()) return 0;
	if (dp2[here] != INF) return dp2[here];
	int& res = dp2[here];
	for (int i = 1; i + here <= str.size(); i++)
	{
		if (dp[here][i]) res = min(res, go(here + i) + 1);
	}
	// cout << here << " : " << res << '\n';
	return res;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> str;

	for (int i = 0; i < str.size(); i++) dp[i][1] = 1;
	for (int i = 0; i < str.size() - 1; i++)
	{
		if (str[i] == str[i + 1]) dp[i][2] = 1;
	}

	for (int _size = 3; _size <= str.size(); _size++)
	{
		for (int j = 0; j + _size <= str.size(); j++)
		{
			if (str[j] == str[j + _size - 1] && dp[j + 1][_size - 2]) dp[j][_size] = 1;
		}
	}
	fill(dp2, dp2 + 2504, INF);
	cout << go(0) << '\n';

	return 0;
}