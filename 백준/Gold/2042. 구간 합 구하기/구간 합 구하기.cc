// BOJ - 2042 : 구간 합 구하기
#include <bits/stdc++.h>
using namespace std;
const int INF = 2147000000;
typedef long long ll;

int n, m, k, t1, t2, t3;
ll t4;

ll sum(vector<ll>& tree, int idx)
{
	ll ans = 0;
	while (idx > 0)
	{
		ans += tree[idx];
		idx -= (idx & -idx);
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
		/*for (int j = 1; j < tree.size(); j++)
		{
			cout << tree[j] << ' ';
		}
		cout << "\n";
		*/
		///
		/// i = 1 : 1 1 0 1 0
		/// i = 2 : 1 3 0 3 0 
		/// i = 3 : 1 3 3 6 0
		/// i = 4 : 1 3 3 10 0
		/// i = 5 : 1 3 3 10 5
		/// 
	}
	m += k;
	while (m--)
	{
		cin >> t1;
		if (t1 == 1)
		{
			cin >> t2 >> t4;
			ll diff = t4 - a[t2]; // 변경 될 값과 원래 값과의 차이를 계산
			a[t2] = t4; // 값 원본배열에 갱신
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