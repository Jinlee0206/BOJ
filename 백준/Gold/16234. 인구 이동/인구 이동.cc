#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>

using namespace std;

const int dy[4] = { -1, 0, 1, 0 };
const int dx[4] = { 0, -1, 0, 1 };

int n, l, r, sum, cnt = 0;
int m_map[51][51];
int visited[51][51];

vector<pair<int, int>> v;

void dfs(int y, int x, vector<pair<int,int>> &v)
{
	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny < 0 || nx < 0 || ny >= n || nx >= n || visited[ny][nx]) continue;
	
		if (abs(m_map[ny][nx] - m_map[y][x]) >= l && abs(m_map[ny][nx] - m_map[y][x]) <= r)
		{
			visited[ny][nx] = 1;
			v.push_back({ ny, nx });
			sum += m_map[ny][nx];
			dfs(ny, nx, v);
		}
	}
	return;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> l >> r;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> m_map[i][j];
		}
	}

	while (true)
	{
		bool flag = 0;
		memset(visited, 0, sizeof(visited));

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (!visited[i][j])
				{
					// pair <int, int> 형 벡터 초기화
					v.clear();

					// 첫번째 인수 (0,0) 삽입
					visited[i][j] = 1;
					v.push_back({ i, j });
					sum = m_map[i][j];
					dfs(i, j, v);

					if (v.size() == 1) continue;
					for (pair<int, int> b : v)
					{
						m_map[b.first][b.second] = sum / v.size();
						flag = 1;
					}
				}
			}
		}

		if (!flag) break;
		cnt++;
	}
	
	cout << cnt << "\n";


	return 0;

}