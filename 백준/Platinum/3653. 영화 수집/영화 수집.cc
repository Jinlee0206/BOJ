// BOJ - 3653 : 영화 수집
#include <bits/stdc++.h>
using namespace std;

int t, n, m, tree[200004], tmp;
map<int, int> mp;

void update(int idx, int value)
{
	while (idx <= 200004)
	{
		tree[idx] += value;
		idx += (idx & -idx);
	}
}

int sum(int idx)
{
	int res = 0;
	while (idx > 0)
	{
		res += tree[idx];
		idx -= (idx & -idx);
	}
	return res;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> t;
	while (t--)
	{
		cin >> n >> m;
		memset(tree, 0, sizeof(tree));
		mp.clear();
		int update_idx = 100001;
		for (int i = 1; i <= n; i++)
		{
			update(i + update_idx, 1);
			mp[i] = i + update_idx;
		}
		for (int i = 0; i < m; i++)
		{
			cin >> tmp;
			int idx = mp[tmp];
			cout << sum(idx) - 1 << " ";
			update(idx, -1);
			update(--update_idx, 1);
			mp[tmp] = update_idx;
		}
		cout << '\n';
	}
	return 0;
}