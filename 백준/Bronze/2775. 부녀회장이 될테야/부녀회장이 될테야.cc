#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int t, k, n, res;

int func(int a, int b)
{
	if (b == 1) return 1;
	if (a == 0) return b;
	return func(a - 1, b) + func(a, b - 1);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> t;

	while (t--)
	{
		cin >> k >> n;

		res = func(k, n);

		cout << res << '\n';
	}

	return 0;
}