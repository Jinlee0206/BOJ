#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
int const _min = 2147000000;

const int dy[4] = { -1, 0, 1, 0 };
const int dx[4] = { 0, -1, 0, 1 };

int n, res = _min;
int flower[20][20], cost[20][20];

int setFlower(int y, int x)
{
	flower[y][x] = 1;
	int s = cost[y][x];
	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];
		flower[ny][nx] = 1;
		s += cost[ny][nx];
	}
	return s;
}

bool check(int y, int x)
{
	if (flower[y][x]) return false;

	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];
		
		if (ny < 0 || nx < 0 || ny >= n || nx >= n || flower[ny][nx]) return false;
	}
	return true;
}

void eraseFlower(int y, int x)
{
	flower[y][x] = 0;
	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];
		flower[ny][nx] = 0;
	}
	return;
}

void dfs(int sum, int cnt)
{
	if (cnt == 3)
	{
		res = min(res, sum);
		return;
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (check(i, j))
			{
				dfs(sum + setFlower(i, j), cnt + 1);
				eraseFlower(i, j);
			}
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
			cin >> cost[i][j];
		}
	}

	dfs(0, 0);

	cout << res << "\n";

	return 0;
}