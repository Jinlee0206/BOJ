#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>

using namespace std;

int n, m, res, t;
int m_map[101][101];
bool visited[101][101];

const int dy[4] = { -1, 0, 1, 0 };
const int dx[4] = { 0, -1, 0, 1 };

bool bfs()
{
	int cnt = 0;

	queue<pair<int, int>> q;
	q.push({ 0,0 });
	visited[0][0] = true;
	t++;

	while (q.size())
	{
		pair<int, int> tmp = q.front();
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int ny = tmp.first + dy[i];
			int nx = tmp.second + dx[i];

			if (ny < 0 || nx < 0 || ny >= n || nx >= m || visited[ny][nx]) continue;

			if (m_map[ny][nx] == 0) q.push({ ny,nx });
			else
			{
				m_map[ny][nx] = 0;
				cnt++;
			}
			visited[ny][nx] = 1;
			
		}
	}

	if (cnt == 0)
	{
		cout << --t << "\n" << res << "\n";
		return true;
	}
	else
	{
		res = cnt;
		return false;
	}

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

	while (true)
	{
		if (bfs()) break;
		
		memset(visited, 0, sizeof(visited));
	}

	return 0;
}