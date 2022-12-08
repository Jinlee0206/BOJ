#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int r, c, t, a[55][55], tmp[55][55], res;

int dy1[] = { 0, -1, 0, 1 };
int dx1[] = { 1, 0, -1, 0 };
int dy2[] = { 0, 1, 0, -1 };
int dx2[] = { 1, 0, -1 ,0 };

vector<pair<int, int>> v1, v2;

void _diffusion(int dy[], int dx[])
{
	fill(&tmp[0][0], &tmp[0][0] + 55 * 55, 0);

	queue<pair<int, int>> q;

	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			if (a[i][j] != -1 && a[i][j]) q.push({ i,j });
		}
	}

	while (q.size())
	{
		pair<int, int> tmpPos = q.front();
		q.pop();

		int y = tmpPos.first;
		int x = tmpPos.second;
		int spread = a[y][x] / 5;

		for (int i = 0; i < 4; i++)
		{
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (ny < 0 || nx < 0 || ny >= r || nx >= c || a[ny][nx] == -1) continue;
			tmp[ny][nx] += spread;
			a[y][x] -= spread;
		}
	}

	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			a[i][j] += tmp[i][j];
		}
	}
	return;
}	

vector<pair<int, int>> _clean(int sy, int sx, int dy[], int dx[])
{
	vector<pair<int, int>> v;

	int cnt = 0;
	int y = sy;
	int x = sx;

	while (true)
	{
		int ny = y + dy[cnt];
		int nx = x + dx[cnt];
		if (ny == sy && nx == sx) break;
		if (ny < 0 || nx < 0 || ny >= r || nx >= c)
		{
			cnt++;
			ny = y + dy[cnt];
			nx = x + dx[cnt];
		}
		/*if (ny == sy && nx == sx) break;*/
		y = ny; x = nx;
		v.push_back({ ny,nx });
	}
	return v;
}

void go(vector<pair<int, int>> &v)
{
	for (int i = v.size() - 1; i > 0; i--)
	{
		a[v[i].first][v[i].second] = a[v[i - 1].first][v[i - 1].second];
	}
	a[v[0].first][v[0].second] = 0;
	return;
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> r >> c >> t;

	bool flag = true;
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			cin >> a[i][j];
			if (a[i][j] == -1)
			{
				if (flag)
				{
					v1 = _clean(i, j, dy1, dx1);
					flag = false;
				} else v2 = _clean(i, j, dy2, dx2);
			}
		}
	}

	while (t--)
	{
		_diffusion(dy1, dx1);
		go(v1);
		go(v2);
	}

	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			if(a[i][j] != -1) res += a[i][j];
		}
	}

	cout << res << '\n';

	return 0;
}