// BOJ-1561 : 놀이 공원
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define max_n 60000000004
#define max_m 10004

ll n, m, a[max_m], l, r = max_n, res, mid, tmp;

bool check(ll mid)
{
	tmp = m;
	for (int i = 0; i < m; i++) tmp += mid / a[i];
	return tmp >= n;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < m; i++) cin >> a[i];
	if (n <= m)
	{
		cout << n;
		return 0;
	}

	while (l <= r)
	{
		mid = (l + r) / 2;
		if (check(mid))
		{
			res = mid;
			r = mid - 1;
		}
		else l = mid + 1;
	}
	tmp = m;
	for (int i = 0; i < m; i++) tmp += ((res - 1) / a[i]);

	for (int i = 0; i < m; i++)
	{
		if (res % a[i] == 0) tmp++;
		if (tmp == n)
		{
			cout << i + 1 << '\n';
			return 0;
		}
	}

	return 0;
}