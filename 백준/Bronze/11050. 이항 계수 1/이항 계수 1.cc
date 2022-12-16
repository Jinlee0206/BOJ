#include <bits/stdc++.h>

using namespace std;

int n, k, res;

int fac(int a)
{
	if (a == 1 || a == 0) return 1;
	else return fac(a - 1) * a;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> k;

	cout << fac(n) / (fac(n-k) * fac(k)) << '\n';

	return 0;
}