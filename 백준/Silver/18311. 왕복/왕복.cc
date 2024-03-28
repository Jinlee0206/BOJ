// BOJ - 18311 : 왕복
#include <bits/stdc++.h>
using namespace std;

int n;
long long k;

vector<pair<int, int>> v;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> k;

	for (int i = 0; i < n; i++)
	{
		int a;
		cin >> a;
		v.push_back({ a , i + 1 });
	}

	long long cnt = 0;
	for (int i = 0; i < n; i++)
	{
		cnt += v[i].first;
		if (cnt > k)
		{
			cout << v[i].second;
			return 0;
		}
	}

	for (int i = n - 1; i >= 0; i--)
	{
		cnt += v[i].first;
		if (cnt > k)
		{
			cout << v[i].second;
			return 0;
		}
	}

	return 0;
}