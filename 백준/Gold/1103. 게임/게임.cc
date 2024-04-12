// BOJ - 1103 : 게임
#include <bits/stdc++.h>
using namespace std;

const int dy[] = { -1, 0, 1, 0 };
const int dx[] = { 0, 1, 0, -1 };
int n, m, a[54][54], visited[54][54], dp[54][54];

bool in(int aa, int bb)
{
	return (aa >= 0 && bb >= 0 && aa < n && bb < m);
}

int dfs(int y, int x)
{
	if (!in(y, x) || a[y][x] == -1) return 0;
	if (visited[y][x])
	{
		cout << -1 << '\n';
		exit(0);
	}

	int& res = dp[y][x];
	if (res) return res;

	visited[y][x] = 1;
	int value = a[y][x];
	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i] * value;
		int nx = x + dx[i] * value;
		res = max(res, dfs(ny, nx) + 1);
	}
	visited[y][x] = 0;
	return res;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{	
		string str;
		cin >> str;
		for (int j = 0; j < str.size(); j++)
		{
			if (str[j] == 'H') a[i][j] = -1;
			else a[i][j] = str[j] - '0';
		}
	}

	cout << dfs(0, 0) << '\n';

	return 0;
}