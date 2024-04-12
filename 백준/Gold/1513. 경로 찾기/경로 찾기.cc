// BOJ - 1513 : 경로 찾기
#include <bits/stdc++.h>
using namespace std;
const int mod = 1000007;
int n, m, c, y, x, a[51][51], dp[51][51][51][51];

int go(int y, int x, int cnt, int prev)
{
	if (y > n || x > m) return 0;
	if (y == n && x == m)
	{
		if (cnt == 0 && a[y][x] == 0) return 1;
		if (cnt == 1 && a[y][x] > prev) return 1; // 도착지점이 오락실이고 prev보다 a[y][x]가 클 때 (가능)
		return 0;
	}

	int& res = dp[y][x][cnt][prev];
	if (res != -1) return res;
	res = 0;

	if (a[y][x] == 0)
	{
		res = (go(y + 1, x, cnt, prev) + go(y, x + 1, cnt, prev)) % mod;
	}
	else if (a[y][x] > prev && cnt >= 1)
	{
		res = (go(y + 1, x, cnt - 1, a[y][x]) + go(y, x + 1, cnt - 1, a[y][x])) % mod;
	}
	return res;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	memset(dp, -1, sizeof(dp));
	cin >> n >> m >> c;

	for (int i = 1; i <= c; i++)
	{
		cin >> y >> x;
		a[y][x] = i;
	}

	for (int i = 0; i <= c; i++)
	{
		cout << go(1, 1, i, 0) << ' ';
	}


	return 0;
}