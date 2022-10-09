#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>

const int INF = 2147000000;
using namespace std;

const int dy[4] = { -1, 0, 1, 0 };
const int dx[4] = { 0, -1, 0, 1 };

int n, m, jy, jx, fy, fx, ans = -1;
char m_map[1005][1005];
int jvisited[1005][1005];
int fvisited[1005][1005];

queue<pair<int, int>> q;

void fbfs(int y, int x)
{

	while (q.size())
	{
		pair<int, int> tmp = q.front();
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int ny = tmp.first + dy[i];
			int nx = tmp.second + dx[i];

			if (ny < 0 || nx < 0 || ny >= n || nx >= m || m_map[ny][nx] == '#') continue;
			if (fvisited[ny][nx] != INF) continue;

			fvisited[ny][nx] = fvisited[tmp.first][tmp.second] + 1;
			q.push({ ny, nx });
		}
	}
	return;
}

void jbfs(int y, int x)
{
	q.push({ y, x });
	jvisited[y][x] = 1;

	while (q.size())
	{
		pair<int, int> tmp = q.front();
		q.pop();

		if (tmp.first == 0 || tmp.second == 0 || tmp.first == n - 1 || tmp.second == m - 1)
		{
			ans = jvisited[tmp.first][tmp.second];
			return;
		}

		for (int i = 0; i < 4; i++)
		{
			int ny = tmp.first + dy[i];
			int nx = tmp.second + dx[i];

			if (ny < 0 || nx < 0 || ny >= n || nx >= m || m_map[ny][nx] == '#') continue;
			if (jvisited[ny][nx]) continue;
			if (fvisited[ny][nx] <= jvisited[tmp.first][tmp.second] + 1) continue;

			jvisited[ny][nx] = jvisited[tmp.first][tmp.second] + 1;
			q.push({ ny, nx });
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;
	// 불이 아예 없을 때의 반례 체크
	fill(&fvisited[0][0], &fvisited[0][0] + 1005 * 1005, INF);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)	
		{
			cin >> m_map[i][j];

			// 불은 여러개 들어올 수 있다
			if (m_map[i][j] == 'F')
			{
				q.push({ i,j });
				fvisited[i][j] = 1;
			}
			else if (m_map[i][j] == 'J')
			{
				jy = i;
				jx = j;
			}
		}
	}

	fbfs(q.front().first, q.front().second);
	jbfs(jy, jx);

	if (ans != -1) cout << ans << "\n";
	else cout << "IMPOSSIBLE" << "\n";

	return 0;

}