// BOJ - 5419 : 북서풍
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int t, n, x, y;
vector<int> tree, _y;
vector<pair<int, int>> a;

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

void update(int pos, int value)
{
	int idx = pos;
	while (idx <= n)
	{
		tree[idx] += value;
		idx += (idx & -idx);
	}
	return;
}

int find_idx(vector<int>& _y, int value)
{
	int lo = 0, hi = _y.size() - 1;
	while (lo <= hi)
	{
		int mid = (lo + hi) / 2;
		if (_y[mid] == value) return mid;
		if (_y[mid] < value) lo = mid + 1;
		else hi = mid - 1;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> t;
	while (t--)
	{
		cin >> n;
		a.clear(); _y.clear(); tree.clear();
		tree.resize(n + 1);

		for (int i = 0; i < n; i++)
		{
			cin >> x >> y;
			a.push_back({ x, y * -1 });
			_y.push_back(y * -1); // y값을 이분탐색을 위해 따로 배열에 저장 (-10^9 ~ 10^9 배열은 너무 크다)
		}

		sort(a.begin(), a.end());
		sort(_y.begin(), _y.end());
		ll res = 0;
		update(find_idx(_y, a[0].second) + 1, 1);
		for (int i = 1; i < n; i++)
		{
			int idx = find_idx(_y, a[i].second) + 1;
			res += 1LL * sum(idx);
			update(idx, 1);
		}
		cout << res << '\n';
	}
	return 0;
}