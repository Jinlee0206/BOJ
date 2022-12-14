#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b)
{
	if (a == 0) return b;
	return a = gcd(b % a, a);
}

int lcm(int a, int b)
{
	return a * b / gcd(a, b);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;

	while (t--)
	{
		int a, b;
		cin >> a >> b;
		cout << lcm(a, b) <<'\n';
	}

	return 0;
}