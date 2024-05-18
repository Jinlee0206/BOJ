// BOJ - 9375 : 패션왕 신해빈
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;
const int INF = 2147000000;

int t, n, res = 1;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> t;
	while (t--)
	{
		cin >> n;
		map<string, int> mp;
		res = 1;

		for (int i = 0; i < n; i++)
		{
			string a, b;
			cin >> a >> b;
			mp[b]++;
		}

		for (auto i : mp)
		{
			res *= (i.second + 1);
		}
		res -= 1;
		cout << res << '\n';
		

	}

	return 0;
}