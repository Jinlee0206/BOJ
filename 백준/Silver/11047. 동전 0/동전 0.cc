#include <bits/stdc++.h>

using namespace std;

int n, k, res;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> k;
	vector<int> v(n);

	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}

	sort(v.begin(), v.end(), greater<>());

	int idx = 0;
	while (1)
	{
		if (k == 0) break;

		if (v[idx] > k)	idx++;
		else
		{
			res++;
			k -= v[idx];
		}
	}

	cout << res << '\n';

	return 0;
}