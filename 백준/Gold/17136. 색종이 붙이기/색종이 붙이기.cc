// BOJ - 17136 : 색종이 붙이기
#include <bits/stdc++.h>
using namespace std;
const int INF = 2147000000;
int n = 10, a[20][20], res = INF;
map<int, int> mp;

bool check(int y, int x, int cnt)
{
	if (y + cnt > n || x + cnt > n) return false;
	for (int i = y; i < y + cnt; i++)
	{
		for (int j = x; j < x + cnt; j++)
		{
			if (a[i][j] == 0) return false;
		}
	}
	return true;
}

void draw(int y, int x, int cnt, int val)
{
	for (int i = y; i < y + cnt; i++)
	{
		for (int j = x; j < x + cnt; j++)
		{
			a[i][j] = val;
		}
	}
}

void dfs(int y, int x, int cnt)
{
	if (cnt >= res) return; // 최소값 찾기

	if (x == n)
	{
		dfs(y + 1, 0, cnt);
		return;
	}

	if (y == n)
	{
		res = min(res, cnt);
		return;
	}

	if (a[y][x] == 0)
	{
		dfs(y, x + 1, cnt);
		return;
	}

	for (int _size = 5; _size >= 1; _size--)
	{
		if (mp[_size] == 5) continue;
		if (check(y, x, _size))
		{
			mp[_size]++;
			draw(y, x, _size, 0);
			dfs(y, x + _size, cnt + 1);
			draw(y, x, _size, 1);
			mp[_size]--;
		}
	}
	return;

}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> a[i][j];
		}
	}

	dfs(0, 0, 0);

	if (res == INF) cout << -1 << '\n';
	else cout << res << '\n';

	return 0;
}