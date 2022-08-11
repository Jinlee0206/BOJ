#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long a[200];

void DFS(int n)
{
	a[1] = 1;
	a[2] = 1;
	a[3] = 1;
	a[4] = 2;
	a[5] = 2;

	for (int i = 6; i <= n; i++)
	{
		a[i] = a[i - 5] + a[i - 1];
	}

	cout<< a[n] << "\n";
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int T, n;
	cin >> T;

	for (int i = 0; i < T; i++)
	{
		cin >> n;

		DFS(n);
	}
	return 0;
}
