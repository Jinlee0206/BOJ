// BOJ - 2583 :	영역 구하기
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

const int dy[] = { -1, 0 , 1, 0 };
const int dx[] = { 0, 1, 0, -1 };

int n, m, l, a[104][104], visited[104][104];
vector<int> v;

int dfs(int y, int x)
{
	int res = 1;
	visited[y][x] = 1;

	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
		if (a[ny][nx] != 1 && !visited[ny][nx])
		{
			res += dfs(ny, nx);
		}
	}
	return res;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> m >> n >> l;

	for (int i = 0; i < l; i++)
	{
		int sx, sy, ex, ey;
		cin >> sx >> sy >> ex >> ey;
		for (int j = sx; j < ex; j++)
		{
			for (int k = sy; k < ey; k++)
			{
				a[j][k] = 1;
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (a[i][j] != 1 && !visited[i][j])
			{
				v.push_back(dfs(i, j));
			}
		}
	}

	cout << v.size() << '\n';
	sort(v.begin(), v.end());
	for (auto i : v) cout << i << ' ';

	return 0;
}