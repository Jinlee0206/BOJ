#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int n, m, m_y1, m_x1, m_y2, m_x2, cnt = 0;
char m_map[301][301];
int visited[301][301];

const int dy[4] = { -1, 0 ,1 ,0 };
const int dx[4] = { 0, -1, 0, 1 };

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m >> m_y1 >> m_x1 >> m_y2 >> m_x2;
	m_x1--, m_y1--, m_x2--, m_y2--;

	for (int i = 0; i < n; i++)
	{
		string str;
		cin >> str;
		for (int j = 0; j < str.size(); j++)
		{
			m_map[i][j] = str[j];
		}
	}
	
	queue<pair<int, int>> q;
	q.push({ m_y1, m_x1 });
	visited[m_y1][m_x1] = 1;

	while (m_map[m_y2][m_x2] != '0')
	{
		cnt++;
		queue<pair<int, int>> tq;

		while (q.size())
		{
			pair<int, int> tmp = q.front();
			q.pop();

			for (int i = 0; i < 4; i++) {
				int ny = tmp.first + dy[i];
				int nx = tmp.second + dx[i];

				if (ny < 0 || nx < 0 || ny >= n || nx >= m || visited[ny][nx]) continue;

				visited[ny][nx] = cnt;
				if (m_map[ny][nx] != '0')
				{
					m_map[ny][nx] = '0';
					tq.push({ ny,nx });
				}
				else q.push({ ny,nx });
			}
		}
		q = tq;
	}

	cout << visited[m_y2][m_x2] << "\n";

	return 0;
}