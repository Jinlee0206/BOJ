#include<bits/stdc++.h>
using namespace std;

int n, m, a[101];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;

	for (int i = 1; i <= n; i++) a[i] = i;

	for (int s = 0; s < m; s++)
	{
		int i, j, tmp;
		cin >> i >> j;

		/*
		tmp = a[i];
		a[i] = a[j];
		a[j] = tmp;
		*/
		swap(a[i], a[j]);
	}

	for (int i = 1; i <= n; i++) cout << a[i] << " ";

	return 0;
}