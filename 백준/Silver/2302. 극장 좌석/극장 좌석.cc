// BOJ - 2302 : 극장 좌석
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, m, tmp, cnt[41], dp[41];

int go(int pos)
{
	if (pos >= n - 1) return 1;
	if (cnt[pos]) return go(pos + 1);
	int& res = dp[pos];
	if (res != -1) return dp[pos];
	res = 0;
	if (!cnt[pos + 1]) res += (go(pos + 2) + go(pos + 1)); // 다음 좌석이 vip 좌석이 아니라면 앞의 두 좌석을 변경
	else res += go(pos + 1); // 변경하지 않고 idx만 증가
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
		cnt[tmp - 1] = 1; // 바꿀수 없는 vip 좌석 cnt 배열
	}
	memset(dp, -1, sizeof(dp));
	cout << go(0) << '\n';

	return 0;
}