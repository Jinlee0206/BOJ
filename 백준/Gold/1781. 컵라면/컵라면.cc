#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>

using namespace std;

int n, dl, cnt, res;
priority_queue<int, vector<int>, greater<int>> pq;
vector<pair<int, int>> v;

int main()
{
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> dl >> cnt;
		v.push_back({ dl, cnt });
	}

	sort(v.begin(), v.end());

	for (int i = 0; i < n; i++)
	{
		pq.push(v[i].second);
		if (pq.size() > v[i].first) pq.pop();
	}

	while (pq.size())
	{
		res += pq.top();
		pq.pop();
	}

	cout << res << '\n';

	return 0;
}