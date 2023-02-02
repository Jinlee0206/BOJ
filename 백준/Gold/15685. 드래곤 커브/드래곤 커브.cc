#include<bits/stdc++.h>

using namespace std;

int n, cnt, ch[104][104];

const int dy[] = { 0, -1 , 0 , 1};
const int dx[] = { 1, 0 , -1, 0 };

vector<int> dragon[4][11];

void go(int x, int y, int d, int g)
{
	int _x = x;
	int _y = y;
	ch[_x][_y] = 1;

	for (int i = 0; i <= g; i++)
	{
		for (int dir : dragon[d][i])
		{
			_x += dx[dir];
			_y += dy[dir];
			ch[_x][_y] = 1;
		}
	}
	return;
}

void chSqr()
{
	for (int i = 0; i <= 103; i++)
	{
		for (int j = 0; j <= 103; j++)
		{
			if (ch[i][j] && ch[i + 1][j] && ch[i][j + 1] && ch[i + 1][j + 1]) cnt++;
		}
	}
}

void makeDragon()
{
	for (int i = 0; i < 4; i++)
	{
		dragon[i][0].push_back(i);
		dragon[i][1].push_back((i + 1) % 4);
		for (int j = 2; j <= 10; j++)
		{
			int _n = dragon[i][j - 1].size();
			for (int k = _n - 1; k >= 0; k--) dragon[i][j].push_back((dragon[i][j - 1][k] + 1) % 4);
			for (int k = 0; k < _n; k++) dragon[i][j].push_back(dragon[i][j - 1][k]);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	makeDragon();
	for (int i = 0; i < n; i++)
	{
		int x, y, d, g;
		cin >> x >> y >> d >> g;
		go(x, y, d, g);
	}

	chSqr();

	cout << cnt << '\n';

	return 0;
}