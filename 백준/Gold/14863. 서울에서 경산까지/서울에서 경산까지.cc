// BOJ - 14863 : 서울에서 경산까지
#include <bits/stdc++.h>
using namespace std;

int n, k, a[104], dp[104][100004], res;
vector<pair<int,int>> v, v2;

int go(int here, int _time)
{
	if (here == n) return 0;
	int& res = dp[here][_time];
	if (res) return res;
	res = -1e6;

	if (_time - v[here].first >= 0) res = max(res, go(here + 1, _time - v[here].first) + v[here].second);
	if (_time - v2[here].first >= 0) res = max(res, go(here + 1, _time - v2[here].first) + v2[here].second);
	return res;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> k;

	for (int i = 0; i < n; i++)
	{
		int a1, a2, b1, b2;
		cin >> a1 >> a2 >> b1 >> b2;
		v.push_back({ a1, a2 });
		v2.push_back({ b1, b2 });
	}

	cout << go(0, k) << '\n';

	return 0;
}