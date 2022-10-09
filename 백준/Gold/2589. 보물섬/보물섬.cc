#include<iostream>
#include<vector>
#include<algorithm>
#include <string>
#include <queue>
#include <cstring>

using namespace std;

int n, m, ans = 0;
string str;
int m_map[51][51];
int visited[51][51];
vector<pair<int, int> > isLand;

const int dy[4] = { -1, 0, 1, 0 };
const int dx[4] = { 0, -1, 0, 1 };

int main()
{
	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		cin >> str;

		for (int j = 0; j < str.size(); j++)
		{
			m_map[i][j] = str[j];
			if (str[j] == 'L') isLand.push_back({ i,j });
		}
	}

	for (int i = 0; i < isLand.size(); i++)
	{
		int res = 0;
		memset(visited, 0, sizeof(visited));

		queue<pair<int, int>> q;
		q.push(isLand[i]);
		visited[isLand[i].first][isLand[i].second] = 1;

		while (q.size())
		{
			pair<int, int> tmp = q.front();
			q.pop();

			for (int j = 0; j < 4; j++)
			{
				int ny = tmp.first + dy[j];
				int nx = tmp.second + dx[j];

				if (ny < 0 || nx < 0 || ny >= n || nx >= m || m_map[ny][nx] == 'W') continue;

				if (visited[ny][nx]) continue;

				visited[ny][nx] = visited[tmp.first][tmp.second] + 1;

				q.push({ ny,nx });
				res = max(res, visited[ny][nx]);
			}
			
		}
		ans = max(res, ans);
	}

	cout << ans - 1 << "\n";
	
	return 0;

}