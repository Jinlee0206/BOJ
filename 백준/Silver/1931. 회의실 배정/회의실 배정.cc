#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	vector<pair<int, int>> vec;

	int n, from, to, res = 1;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> from >> to;
		vec.push_back({ to, from });
	}

	sort(vec.begin(), vec.end());

	from = vec[0].second;
	to = vec[0].first;

	for (int i = 1; i < n; i++)
	{
		if (vec[i].second < to) continue;
		from = vec[i].second;
		to = vec[i].first;
		res++;
	}

	cout << res << '\n';

	return 0;
}