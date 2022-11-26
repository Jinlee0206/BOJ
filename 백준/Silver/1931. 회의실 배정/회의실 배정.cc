#include <iostream>
#include <vector>
#include <algorithm>

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

	from = v[0].second;
	to = v[0].first;
	for (int i = 1; i < n; i++)
	{
		if (to > v[i].second) continue;
		to = v[i].first;
		from = v[i].second;
		cnt++;
	}

	cout << cnt << '\n';

	return 0;
}