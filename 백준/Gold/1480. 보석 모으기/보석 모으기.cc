// BOJ - 1480 : 보석 모으기
#include <bits/stdc++.h>
using namespace std;
const int INF = 2147000000;

int n, m, c, w, a[14], dp[14][1 << 14][21];

int go(int idx, int jewel, int capacity)
{
	if (idx == m) return 0;
	int& res = dp[idx][jewel][capacity];
	if (res) return res;
	res = max(res, go(idx + 1, jewel, c)); // 안넣고 인덱스만 증가
	for (int i = 0; i < n; i++)
	{
		bool isBeforeJewel = (1 << i) & jewel;
		bool isJewelCan = (capacity - a[i]) >= 0;
		if (!isBeforeJewel && isJewelCan) res = max(res, go(idx, jewel | (1 << i), capacity - a[i]) + 1);
	}
	return res;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m >> c;

	for (int i = 0; i < n; i++) cin >> a[i];
	cout << go(0, 0, c) << '\n';

	return 0;
}