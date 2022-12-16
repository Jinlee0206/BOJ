#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	
	vector<int> v(n);

	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}

	sort(v.begin(), v.end());

	int sum = v[0];
	for (int i = 1; i < n; i++)
	{
		v[i] += v[i - 1];
		sum += v[i];
	}

	cout << sum << '\n';

	return 0;
}