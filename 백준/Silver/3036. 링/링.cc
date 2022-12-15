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

	for (int i = 1; i < n; i++)
	{
		int gcd = GCD(v[0], v[i]);
		cout << v[0] / gcd << '/' << v[i] / gcd << '\n';
	}

	return 0;
}