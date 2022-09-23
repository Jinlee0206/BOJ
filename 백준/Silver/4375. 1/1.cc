#include <iostream>
#include <algorithm>

using namespace std;

int func(int n)
{
	long long k = 1;
	int cnt = 1;

	while (true)
	{
		if (k % n == 0)
		{
			return cnt;
		}
		else
		{
			k = k * 10 + 1;
			// 숫자가 너무 커질 경우 나머지만 가져가도 된다.
			k %= n;
			cnt++;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;

	while (cin >> n)
	{

		if (n % 2 == 0 || n % 5 == 0) continue;

		cout << func(n) << "\n";
	}

	return 0;
}