// BOJ-12869 : 뮤탈리스크
#include<bits/stdc++.h>
using namespace std;

int _a[6][3] = {
	{9,3,1},
	{9,1,3},
	{3,1,9},
	{3,9,1},
	{1,3,9},
	{1,9,3}
};

int n, a[3];
int visited[61][61][61];

struct A { int a; int b; int c; };
queue<A> q;

int go(int x, int y, int z)
{
	visited[x][y][z] = 1;
	q.push({ x,y,z });

	while (q.size())
	{
		int a = q.front().a;
		int b = q.front().b;
		int c = q.front().c;
		q.pop();

		for (int i = 0; i < 6; i++)
		{
			int na = max(0, a - _a[i][0]);
			int nb = max(0, b - _a[i][1]);
			int nc = max(0, c - _a[i][2]);

			if (visited[na][nb][nc]) continue;
			visited[na][nb][nc] = visited[a][b][c] + 1;
			q.push({ na,nb,nc });
		}
	}
	return visited[0][0][0] - 1;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];

	cout << go(a[0], a[1], a[2]) << '\n';

	return 0;
}