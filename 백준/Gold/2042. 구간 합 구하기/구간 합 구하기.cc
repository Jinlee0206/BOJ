// BOJ - 2042 : 구간 합 구하기 (팬윅트리)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, m, k, t1, t2, t3;
ll t4;

ll sum(vector<ll>& tree, int i)
{
	ll ans = 0;
	while (i > 0)
	{
		ans += tree[i];
		i -= (i & -i);
	}
	return ans;
}

void update(vector<ll>& tree, int idx, ll diff)
{
	while (idx < tree.size())
	{
		tree[idx] += diff;
		idx += (idx & -idx);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m >> k;
	vector<ll> a(n + 1);
	vector<ll> tree(n + 1);
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		update(tree, i, a[i]);
	}
	m += k;
	while (m--)
	{
		cin >> t1;
		if (t1 == 1)
		{
			cin >> t2 >> t4;
			ll diff = t4 - a[t2];
			a[t2] = t4;
			update(tree, t2, diff);
		}
		else
		{
			int t2, t3;
			cin >> t2 >> t3;
			cout << sum(tree, t3) - sum(tree, t2 - 1) << '\n';
		}
	}

	return 0;
}