#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int m, n, k, cnt = 0;
int m_map[101][101];
int visited[101][101];

const int dy[4] = { -1, 0, 1, 0 };
const int dx[4] = { 0, -1, 0, 1 };

vector<int> vec;

int DFS(int y, int x)
{
	visited[y][x] = 1;

	int res = 1;

	for (int i = 0; i < 4; i++)
	{	
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;

		if (!visited[ny][nx] && m_map[ny][nx] != 1)
		{
			res += DFS(ny, nx);
		}
	}

	//cout << y << " : " << x << " " << res << "\n";

	return res;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> m >> n >> k;

	for (int l = 0; l < k; l++)
	{
		int sx, sy, ex, ey;
		cin >> sx >> sy >> ex >> ey;

		for (int i = sx; i < ex; i++)
		{
			for (int j = sy; j < ey; j++)
			{
				m_map[i][j] = 1;
			}
		}
	}

	// 디버깅
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
			if (m_map[i][j] != 1 && !visited[i][j])
			{
				vec.push_back(DFS(i, j));
			}
		}
	}

	cout << vec.size() << "\n";

	sort(vec.begin(), vec.end());

	for (auto i : vec) cout << i << " ";

	return 0;
}