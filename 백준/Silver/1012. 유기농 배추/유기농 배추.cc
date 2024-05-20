// BOJ - 1012 : 유기농 배추
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

const int dy[] = { -1,0,1,0 };
const int dx[] = { 0, 1, 0,-1 };
int t, n, m, k, a[54][54], visited[54][54], cnt;

void dfs(int y, int x)
{
	visited[y][x] = 1;
	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || nx < 0 || ny >= n || nx >= m || a[ny][nx] == 0) continue;
		if (visited[ny][nx]) continue;
		visited[ny][nx] = 1;
		dfs(ny, nx);
	}
	return;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> t;
	while (t--)
	{
		fill(&visited[0][0], &visited[0][0] + 54 * 54, 0);
		fill(&a[0][0], &a[0][0] + 54 * 54, 0);
		cnt = 0;

		cin >> m >> n >> k;
		for (int i = 0; i < k; i++)
		{
			int x, y;
			cin >> x >> y;
			a[y][x] = 1;
		}

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (a[i][j] == 1 && !visited[i][j])
				{
					dfs(i, j);
					cnt++;
				}
			}
		}
		cout << cnt << '\n';
	}
	return 0;
}