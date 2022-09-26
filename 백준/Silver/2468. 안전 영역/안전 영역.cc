#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, res = 1, cnt = 0, max_height = -2147000000;
int m_map[101][101];
int visited[101][101];

const int dy[4] = { -1, 0, 1, 0 };
const int dx[4] = { 0, -1, 0, 1 };

void DFS(int y, int x, int k)
{
	visited[y][x] = 1;

	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny < 0 || nx < 0 || ny >= n || nx >= n) continue;

		if (!visited[ny][nx] && m_map[ny][nx] > k)
		{
			DFS(ny, nx, k);
		}
	}
	return;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			int a;
			cin >> a;
			m_map[i][j] = a;
			max_height = max(max_height, a);
		}
	}

	for (int k = max_height; k > 0; k--)
	{
		// 변수 초기화
		cnt = 0;
		fill(&visited[0][0], &visited[0][0] + 101 * 101, 0);

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (m_map[i][j] - k > 0 && !visited[i][j])
				{
					DFS(i, j, k);
					cnt++;
				}
			}
		}
		res = max(res, cnt);
	}
	
	cout << res << "\n";

	return 0;
}