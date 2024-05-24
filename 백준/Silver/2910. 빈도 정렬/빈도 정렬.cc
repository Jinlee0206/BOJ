#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

map<int, int> order; // 순서

bool cmp(pair<int, int>& a, pair<int, int>& b)
{
	if (a.second == b.second) return order[a.first] < order[b.first]; // 갯수가 같으면 들어온 순서대로 정렬

	return a.second > b.second; // 많은 수대로 정렬
}


int main()
{
	int n, c;
	cin >> n >> c;

	map<int, int> list; //

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