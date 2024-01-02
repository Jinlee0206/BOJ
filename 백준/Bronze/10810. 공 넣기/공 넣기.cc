#include<bits/stdc++.h>
using namespace std;

int n, m, a[101];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;

	for (int s = 0; s < m; s++)
	{
		int i, j, k;
		cin >> i >> j >> k;

		for (int l = i; l <= j; l++)
		{
			a[l] = k;
		}
	}

	for (int i = 1; i <= n; i++) cout << a[i] << " ";
	return 0;
}