#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;

// 이진법 변환
int solve(int n)
{
	int res = 0;

	while (n > 0)
	{
		if (n % 2 == 1) res++;
		n /= 2;
	}
	return res;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;

	cout << solve(n) << "\n";

	return 0;
}