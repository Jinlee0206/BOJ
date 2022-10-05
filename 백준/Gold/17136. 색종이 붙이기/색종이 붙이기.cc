#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

const int INF = 2147000000;
int n = 10, res = INF;
int m_map[20][20];

map<int, int> mp;

bool check(int y, int x, int cnt)
{
	if (y + cnt > n || x + cnt > n) return false;
	for (int i = y; i < y + cnt; i++)
	{
		for (int j = x; j < x + cnt; j++)
		{
			if (m_map[i][j] == 0) return false;
		}
	}
	return true;
}

void draw(int y, int x, int cnt, int value)
{
	for (int i = y; i < y + cnt; i++)
	{
		for (int j = x; j < x + cnt; j++)
		{
			m_map[i][j] = value;
		}
	}
}

void dfs(int y, int x, int cnt)
{
	//cout << y << " " << x << " " << cnt << " " << "\n";

	// 백트래킹
	if (cnt >= res) return;
	
	// x 한줄씩
	if (x == n)
	{
		dfs(y + 1, 0, cnt);
		return;
	}

	// 기저 사례
	if (y == n)
	{
		res = min(res, cnt);
		return;
	}

	if (m_map[y][x] == 0)
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

void setMap()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> m_map[i][j];
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	setMap();

	dfs(0, 0, 0);

	if (res == INF) cout << "-1" << "\n";
	else cout << res << "\n";

	return 0;
}