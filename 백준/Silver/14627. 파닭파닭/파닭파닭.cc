// BOJ-14627 : 파닭파닭
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF = 1e18;

ll s, c, k, a[1000004], res, l = 1, r, mid, sum;

bool check(ll mid)
{
	ll cnt = 0;
	for (int i = 0; i < s; i++) cnt += a[i] / mid;
	return cnt >= c;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> s >> c;

	for (int i = 0; i < s; i++)
	{
		cin >> a[i];
		sum += a[i];
	}

	l = 1, r = 1e9;
	while (l <= r)
	{
		mid = (l + r) / 2;
		if (check(mid))
		{
			res = mid;
			l = mid + 1; // 5개 이상으로 자를 수 있다면 파 길이 범위 늘리기
		}
		else r = mid - 1;
	}

	cout << sum - res * c << '\n';


	return 0;
}