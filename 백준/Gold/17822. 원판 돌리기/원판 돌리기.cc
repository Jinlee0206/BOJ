// BOJ-17822 : 원판 돌리기
#include <bits/stdc++.h>
using namespace std;

const int dy[] = { 0,1,0,-1 };
const int dx[] = { 1,0,-1,0 };

int n, m, t, x, d, k, a[54][54], visited[54][54], res;
bool flag = 1;

void setAverage()
{
	int sum = 0;
	int cnt = 0;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (a[i][j] == 0) continue;
			sum += a[i][j];
			cnt++;
		}
	}

	double avg = (double)sum / (double)cnt;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (a[i][j] == 0) continue;
			if ((double)a[i][j] > avg) a[i][j]--;
			else if ((double)a[i][j] < avg) a[i][j]++;
		}
	}
	return;
}

void dfs(int y, int x)
{
	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = (x + dx[i] + m) % m;

		if (ny < 0 || ny >= n) continue;
		if (visited[ny][nx]) continue;
		if (a[y][x] == a[ny][nx])
		{
			visited[y][x] = visited[ny][nx] = 1;
			flag = 0;
			dfs(ny, nx);
		}
	}
	return;
}

bool findAdj()
{
	flag = 1;
	memset(visited, 0, sizeof(visited));

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (a[i][j] == 0) continue;
			if (visited[i][j]) continue;
			dfs(i, j);
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (visited[i][j]) a[i][j] = 0;
		}
	}
	return flag;
}

void _rotate(int y, int dir, int k)
{
	vector<int> v;

	for (int i = 0; i < m; i++) v.push_back(a[y][i]);

	if (dir == 1) rotate(v.begin(), v.begin() + k, v.end());
	else rotate(v.rbegin(), v.rbegin() + k, v.rend());

	for (int i = 0; i < m; i++) a[y][i] = v[i];
	return;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m >> t;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> a[i][j];
		}
	}

	for (int i = 0; i < t; i++)
	{
		cin >> x >> d >> k;
		for (int j = x - 1; j < n; j += x)
		{
			_rotate(j, d, k);
		}
		if (findAdj()) setAverage();
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			res += a[i][j];
		}
	}

	cout << res << '\n';

	return 0;
}