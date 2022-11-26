#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

typedef long long ll;
using namespace std;

int n, k, m, v, c;
ll res;
vector<pair<ll, ll>> vec;
vector<ll> vec2;
priority_queue<ll> pq;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> k;

	for (int i = 0; i < n; i++)
	{
		cin >> m >> v;
		vec.push_back({ m,v });
	}

	for (int i = 0; i < k; i++)
	{
		int a; 
		cin >> a;
		vec2.push_back(a);
	}

	sort(vec.begin(), vec.end());
	sort(vec2.begin(), vec2.end());

	int j = 0;
	for (int i = 0; i < k; i++)
	{
		while (j < n && vec[j].first <= vec2[i]) pq.push(vec[j++].second);

		if (pq.size())
		{
			res += pq.top();
			pq.pop();
		}
	}

	cout << res << '\n';

	return 0;
}