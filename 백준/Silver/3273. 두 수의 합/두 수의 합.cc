// BOJ-3273 : 두 수의 합
#include <bits/stdc++.h>
using namespace std;

int n, a[100004], res, x;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}

	cin >> x;

	sort(a, a + n);

	int p1 = 0, p2 = n - 1;

	while (p1 < p2)
	{
		if (a[p1] + a[p2] < x) p1++;
		else if (a[p1] + a[p2] == x)
		{
			res++;
			p1++;
		}
		else p2--;
	}

	cout << res << '\n';
	return 0;
}
