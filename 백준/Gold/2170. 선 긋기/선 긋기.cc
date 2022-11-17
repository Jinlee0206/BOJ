#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>

using namespace std;

pair<int, int> L[1000004];
int n, from, to, l, r, res;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> from >> to;
		L[i] = pair<int, int>(from, to);
	}

	sort(L, L + n);

	l = L[0].first;
	r = L[0].second;

	for (int i = 1; i < n; i++)
	{
		if (r < L[i].first)
		{
			res += (r - l);
			l = L[i].first;
			r = L[i].second;
		}
		else if (L[i].first <= r && L[i].second >= r)
		{
			r = L[i].second;
		}
	}
	res += r - l;
	cout << res << '\n';

	return 0;
}