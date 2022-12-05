#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, cnt, k;
int m_map[30][30], visited[30][30];
vector<int> v;

int dy[] = { -1,0,1,0 };
int dx[] = { 0,-1,0,1 };

int dfs(int y, int x, int k)
{
	int res = 1;
	visited[y][x] = k;

	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny < 0 || nx < 0 || ny >= n || nx >= n || m_map[ny][nx] == 0) continue;

		if (visited[ny][nx] == 0)
		{
			visited[ny][nx] = k;
			res += dfs(ny, nx, k);
		}
	}

	return res;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		string str;
		cin >> str;

		for (int j = 0; j < str.size(); j++)
		{
			m_map[i][j] = str[j] - '0';
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (m_map[i][j] != 0 && !visited[i][j])
			{
				k++;
				v.push_back(dfs(i, j, k));
			}
		}
	}

	sort(v.begin(), v.end());

	cout << k << '\n';

	for (auto a : v)
	{
		cout << a << '\n';
	}

	return 0;
}