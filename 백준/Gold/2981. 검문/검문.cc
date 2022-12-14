#include <bits/stdc++.h>

using namespace std;

int GCD(int a, int b)
{
	if (a == 0) return b;
	return GCD(b % a, a);
}

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

	int gcd = v[1] - v[0];

	for (int i = 2; i < n; i++)
	{
		gcd = GCD(gcd, v[i] - v[i - 1]);
	}

	vector<int> res;
	for (int i = 2; i * i <= gcd; i++)
	{
		if (gcd % i == 0)
		{
			res.push_back(i);
			res.push_back(gcd / i);
		}
	}
	res.push_back(gcd);

	sort(res.begin(), res.end());
	res.erase(unique(res.begin(), res.end()), res.end());

	for (int i = 0; i < res.size(); i++)
	{
		cout << res[i] << " ";
	}

	return 0;
}