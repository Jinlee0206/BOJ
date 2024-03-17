// BOJ-17144 : 미세먼지 안녕!
#include <bits/stdc++.h>
using namespace std;

const int INF = 2147000000;
int dy1[] = { 0,-1,0,1 };
int dx1[] = { 1,0,-1,0 };
int dy2[] = { 0,1,0,-1 };
int dx2[] = { 1,0,-1,0 };

int r, c, t, a[54][54], tmp[54][54], res;

vector<pair<int, int>> v1, v2; // 각각 위쪽 아래쪽 공기청정기 바람 경로 저장하는 배열

void diffusion(int dy[], int dx[])
{
	fill(&tmp[0][0], &tmp[0][0] + 54 * 54, 0);
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
		pair<int,int> tmpPos = q.front();
		q.pop();

		int y = tmpPos.first;
		int x = tmpPos.second;
		int spread = a[y][x] / 5;

		for (int i = 0; i < 4; i++)
		{
			int ny = y + dy1[i];
			int nx = x + dx1[i];
			
			if (ny < 0 || nx < 0 || ny >= r || nx >= c || a[ny][nx] == -1) continue;
			tmp[ny][nx] += spread;
			a[y][x] -= spread;
		}
	}

	// 확산 진행된 임시 배열을 본 배열에 더하기
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			a[i][j] += tmp[i][j];
		}
	}
	return;
}

vector<pair<int,int>> clean(int sy, int sx, int dy[], int dx[])
{
	vector<pair<int,int>> v;

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

			// 방향 전환 후 한번 더 실행해줘야지 무한루프에 빠지지 않음
			ny = y + dy[cnt];
			nx = x + dx[cnt];
		}
		y = ny;
		x = nx;
		v.push_back({ ny,nx });
	}
	return v;
}

void go(vector<pair<int, int>>& v) {
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

	bool flag = 1;
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			cin >> a[i][j];
			if (a[i][j] == -1) // 공기청정기 바람 방향에 있는 지점 벡터에 저장 
			{
				if (flag)
				{
					v1 = clean(i, j, dy1, dx1);
					flag = false;
				}
				else v2 = clean(i, j, dy2, dx2);
			}
		}
	}

	while (t--)
	{
		diffusion(dy1, dx2);
		go(v1);
		go(v2);
	}

	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			if (a[i][j] != -1) res += a[i][j];
		}
	}

	cout << res << '\n';

	return 0;
}