#include<bits/stdc++.h>
using namespace std;

int n, m;
vector<int> a;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;

	for (int i = 1; i <= n; i++) a.push_back(i);

	for (int s = 0; s < m; s++)
	{
		int i, j;
		cin >> i >> j;
		i--;

		reverse(a.begin() + i, a.begin() + j);
	}

	for(int i = 0; i < n; i++) cout << a[i] << " ";

	return 0;
}