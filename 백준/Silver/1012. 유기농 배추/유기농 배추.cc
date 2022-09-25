#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int t, n, m, k, cnt = 0;

int m_map[51][51];
int visited[51][51];

const int dy[4] = { -1, 0, 1, 0 };
const int dx[4] = { 0, -1, 0, 1 };

// conected component 찾는 문제
// DFS를 통해 visited 행렬 찾고 counting
void DFS(int y, int x)
{
	visited[y][x] = 1;
	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
		
		if (m_map[ny][nx] == 1 && !visited[ny][nx])
			DFS(ny, nx);
	}
	return;
}

int main()
{	
	cin >> t;

	while (t--)
	{
		cnt = 0;

		for (int i = 0; i < 51; i++)
		{
			for (int j = 0; j < 51; j++)
			{
				m_map[i][j] = 0;
				visited[i][j] = 0;
			}
		}

		cin >> n >> m >> k;

		for (int i = 0; i < k; i++)
		{
			int a, b;
			cin >> a >> b;

			m_map[a][b] = 1;
		}
		
		/*for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				cout << m_map[i][j] << " ";
			}
			cout << "\n";
		}*/

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (m_map[i][j] == 1 && !visited[i][j])
				{
					cnt++;
					DFS(i, j);
				}
			}
		}

		cout << cnt << "\n";
	}

	return 0;
}