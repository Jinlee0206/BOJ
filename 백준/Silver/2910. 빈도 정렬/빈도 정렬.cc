#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

map<int, int> order; // index

bool cmp(pair<int, int>& a, pair<int, int>& b)
{
	if (a.second == b.second) return order[a.first] < order[b.first];

	return a.second > b.second;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	map<int, int> list; // count

	int n, c;

	cin >> n >> c;

	for (int i = 0; i < n; i++)
	{
		int a;
		cin >> a;
		list[a]++;

		if (order[a] == 0) order[a] = i + 1;
	}

	vector<pair<int, int>> vec(list.begin(), list.end());

	sort(vec.begin(), vec.end(), cmp);

	for (auto x : vec)
	{
		for (int i = 0; i < x.second; i++)
		{
			cout << x.first << " ";
		}
	}

	return 0;

}