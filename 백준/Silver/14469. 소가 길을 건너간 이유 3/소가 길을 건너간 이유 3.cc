#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, arrived, cp, realTime;
vector<pair<int, int>> v;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> arrived >> cp;
		v.push_back({ arrived, cp });
	}

	sort(v.begin(), v.end());

	realTime = v[0].first + v[0].second;

	for (int i = 1; i < n; i++)
	{
		realTime = max(realTime, v[i].first);
		realTime += v[i].second;
	}

	cout << realTime << '\n';

	return 0;
}