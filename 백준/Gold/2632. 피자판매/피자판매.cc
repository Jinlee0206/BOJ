// BOJ-2630 : 피자판매
#include <bits/stdc++.h>
using namespace std;

int k, n, m, res;
int a[1004], b[1004], psum_a[2008], psum_b[2008];
map<int, int> aCnt, bCnt;

void make(int n, int psum[], map<int, int>& mp)
{
	for (int interval = 1; interval <= n; interval++)
	{
		for (int start = interval; start <= n + interval - 1; start++)
		{
			int sum = psum[start] - psum[start - interval];
			mp[sum]++;
			if (interval == n) break;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> k >> n >> m;

	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		psum_a[i] = psum_a[i - 1] + a[i];
	}

	for (int i = n + 1; i <= n * 2; i++) psum_a[i] = psum_a[i - 1] + a[i - n];
	
	for (int i = 1; i <= m; i++)
	{
		cin >> b[i];
		psum_b[i] = psum_b[i - 1] + b[i];
	}

	for (int i = m + 1; i <= m * 2; i++) psum_b[i] = psum_b[i - 1] + b[i - m];

	make(n, psum_a, aCnt);
	make(m, psum_b, bCnt);

	res = (aCnt[k] + bCnt[k]); // a와 b 혼자서 k를 만드는 각각의 경우
	for (int i = 1; i < k; i++)
	{
		res += (aCnt[i] * bCnt[k - i]); // a와 b의 합이 k가 되는 경우
	}
	
	cout << res << '\n';

	return 0;
}