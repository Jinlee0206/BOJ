#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int n, m, ans = -2147000000;
char m_map[22][22];
int visited[26];
int alpha[26];

const int dy[4] = { -1, 0, 1, 0 };
const int dx[4] = { 0, -1, 0 ,1 };

void bfs(int y, int x, int res)
{
	ans = max(res, ans);

	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;

		int next = (int)(m_map[ny][nx] - 'A');

		if (visited[next] == 0)
		{
			visited[next] = 1;
			bfs(ny, nx, res + 1);
			visited[next] = 0;
		}
	}
	return;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> m_map[i][j];
		}
	}

	visited[(int)m_map[0][0] - 'A'] = 1;
	bfs(0, 0, 1);
	cout << ans << "\n";

	return 0;
}