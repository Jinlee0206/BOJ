// BOJ - 1450 : 냅색문제
#include <bits/stdc++.h>
using namespace std;

int n, c, a[34], res;
vector<int> v, v2;

void go(int here, int _n, vector<int>& v, int sum)
{
	if (sum > c) return;
	if (here > _n)
	{
		v.push_back(sum);
		return;
	}
	go(here + 1, _n, v, sum + a[here]);
	go(here + 1, _n, v, sum);
	return;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> c;

	for (int i = 0; i < n; i++) cin >> a[i];

	go(0, n / 2 - 1, v, 0);
	go(n / 2, n - 1, v2, 0);
	sort(v.begin(), v.end());
	sort(v2.begin(), v2.end());

	for (int b : v)
	{
		if (c - b >= 0)
		{
			res += (int)(upper_bound(v2.begin(), v2.end(), c - b) - v2.begin());
		}
	}

	cout << res << '\n';
	return 0;
}