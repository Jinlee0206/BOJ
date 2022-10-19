#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>

using namespace std;
int const _min = 2147000000;

const int dy[4] = { -1, 0, 1, 0 };
const int dx[4] = { 0, -1, 0, 1 };

int n, m, k, sy, sx, ey, ex;

char m_map[10][10];
int visited[10][10];

int dfs(int y, int x)
{
	if (y == ey && x == ex)
	{
		if (k == visited[y][x]) return 1;
		else return 0;
	}

	int cnt = 0;
	
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny < 0 || nx < 0 || ny >= n || nx >= m || visited[ny][nx]) continue;

		if (m_map[ny][nx] == 'T') continue;

		visited[ny][nx] = visited[y][x] + 1;
		cnt += dfs(ny, nx);
		visited[ny][nx] = 0;
	} 

	return cnt;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m >> k;

	for (int i = 0; i < n; i++)
	{
		string str;
		cin >> str;
		for (int j = 0; j < str.size(); j++)
		{
			m_map[i][j] = str[j];
		}
	}

	sy = n - 1;
	sx = 0;
	ey = 0;
	ex = m - 1;

	visited[sy][sx] = 1;

	cout << dfs(sy, sx) << "\n";

	return 0;
}