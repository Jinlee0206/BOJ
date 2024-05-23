// BOJ - 1514 :	자물쇠
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;
const int INF = 987654321;
int n, a[104], b[104], dp[104][10][10][10][2];

int _mod(int x)
{
	return (x < 0) ? x + 10 : x % 10;
}

int f(int pos, int x, int y, int z, int flag)
{
	if (pos == n) return 0;
	int& res = dp[pos][x][y][z][flag];
	if (res != -1) return res;
	if (_mod(x + a[pos]) == _mod(b[pos])) return res = min(f(pos + 1, y, z, 0, 0), f(pos + 1, y, z, 0, 1));
	res = INF;
	int _flag = flag ? 1 : -1;
	for (int i = 1; i <= 3; i++)
	{
		res = min(res, 1 + f(pos, _mod(x + i * _flag), y, z, flag));
		res = min(res, 1 + f(pos, _mod(x + i * _flag), _mod(y + i * _flag), z, flag));
		res = min(res, 1 + f(pos, _mod(x + i * _flag), _mod(y + i * _flag), _mod(z + i * _flag), flag));
	}
	return res;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	memset(dp, -1, sizeof(dp));
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%1d", &a[i]);
	for (int i = 0; i < n; i++) scanf("%1d", &b[i]);
	cout << min(f(0, 0, 0, 0, 0), f(0, 0, 0, 0, 1)) << '\n';

	return 0;
}