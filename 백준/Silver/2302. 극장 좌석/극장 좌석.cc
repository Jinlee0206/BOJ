// BOJ - 2302 :	극장 좌석
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

int n, m, tmp, dp[54], cnt[54];

int go(int pos)
{
	if (pos >= n - 1) return 1;
	if (cnt[pos]) return go(pos + 1); // vip 좌석 변경 불가
	int& res = dp[pos];
	if (res != -1) return res;
	res = 0;
	if (!cnt[pos + 1]) res += (go(pos + 2) + go(pos + 1));
	else res += go(pos + 1);
	return res;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> tmp;
		cnt[tmp - 1] = 1;
	}
	memset(dp, -1, sizeof(dp));
	cout << go(0) << '\n';

	return 0;
}