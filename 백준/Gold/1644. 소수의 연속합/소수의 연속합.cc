#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<bool> isPrime;
vector<int> prime;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	isPrime.resize(n + 1, true);

	for (int i = 2; i * i <= n; i++)
	{

		for (int j = i * 2; j <= n; j += i)
		{
			isPrime[j] = false;
		}
	}

	for (int i = 2; i <= n; i++)
	{
		if (isPrime[i]) prime.push_back(i);
	}

	int p1 = 0, p2 = 0, sum = 0, cnt = 0;

	while (1)
	{
		if (sum >= n) sum -= prime[p1++];
		else if (p2 == prime.size()) break;
		else sum += prime[p2++];

		if (sum == n) cnt++;
	}

	cout << cnt << "\n";

	return 0;
}