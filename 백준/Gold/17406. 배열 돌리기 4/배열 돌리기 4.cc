#include<bits/stdc++.h>

using namespace std;

const int INF = 2147000000;
int n, m, k, r, c, s, res = INF, sy, sx, ey, ex, dir;
int a[54][54], b[54][54], visited[54][54];

vector<int> v_idx;
struct A
{
	int y, x, cnt;
};
vector<A> v;
vector<pair<int, int>> vv;

const int dy[] = { 0, 1, 0, -1 };
const int dx[] = { 1, 0, -1, 0 };

void go(int y, int x, int first)
{
	if (!first && y == sy && x == sx) dir++;
	if (!first && y == sy && x == ex) dir++;
	if (!first && y == ey && x == ex) dir++;
	if (!first && y == ey && x == sx) dir++;
	int ny = y + dy[dir];
	int nx = x + dx[dir];
	if (visited[ny][nx]) return;
	visited[ny][nx] = 1;
	vv.push_back({ ny,nx });
	go(ny, nx, 0);
}

void rotateAll(int y, int x, int cnt)
{
	for (int i = 1; i <= cnt; i++)
	{
		sy = y - 1 * i;
		sx = x - 1 * i;
		ey = y + 1 * i;
		ex = x + 1 * i;
		vv.clear();
		dir = 0;
		memset(visited, 0, sizeof(visited));
		visited[sy][sx] = 1;
		vv.push_back({ sy,sx });
		go(sy, sx, 1);
		vector<int> vvv;
		for (pair<int, int> c : vv) vvv.push_back(b[c.first][c.second]);
		rotate(vvv.begin(), vvv.begin() + vvv.size() - 1, vvv.end());
		for (int i = 0; i < vv.size(); i++) b[vv[i].first][vv[i].second] = vvv[i];
	}
}

int solve()
{
	for (int i : v_idx) rotateAll(v[i].y, v[i].x, v[i].cnt);
	int _res = INF;
	for (int i = 0; i < n; i++)
	{
		int cnt = 0;
		for (int j = 0; j < m; j++) cnt += b[i][j];
		_res = min(_res, cnt);
	}
	return _res;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m >> k;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> a[i][j];
		}
	}
	for (int i = 0; i < k; i++)
	{
		cin >> r >> c >> s; r--; c--;
		v.push_back({ r,c,s });
		v_idx.push_back(i);
	}

	do {
		memcpy(b, a, sizeof(b));
		res = min(res, solve());
	} while (next_permutation(v_idx.begin(), v_idx.end()));

	cout << res << '\n';
	return 0;
}