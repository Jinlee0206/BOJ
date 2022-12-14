#include <bits/stdc++.h>

using namespace std;

int n, from, to, cnt = 1;
vector<pair<int, int>> v;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> from >> to;
		v.push_back({ to, from });
	}

	sort(v.begin(), v.end());

	to = v[0].first;
	from = v[0].second;

	for (int i = 1; i < n; i++)
	{
		if (v[i].second < to) continue;
		to = v[i].first;
		from = v[i].second;
		cnt++;
	}

	cout << cnt << '\n';

	return 0;
}