// BOJ - 2342 : Dance Dance Revolution
#include <bits/stdc++.h>
using namespace std;
const int INF = 2147000000;
int n = 0, a[100004], dp[100004][5][5], res;

int check(int from, int to)
{
	// 처음에는 2
	if (from == 0) return 2;
	// 다시누르면 1
	if (from == to) return 1;
	// 반대일 경우
	if (abs(from - to) == 2) return 4;
	// 인접할 경우 
	return 3;
}

int go(int here, int l, int r)
{
	if (here == n) return 0;
	int& res = dp[here][l][r];
	if (res != -1) return res;
	
	int left = go(here + 1, a[here], r) + check(l, a[here]);
	int right = go(here + 1, l, a[here]) + check(r, a[here]);
	return dp[here][l][r] = min(left, right);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	for (int i = 0; ; i++)
	{
		cin >> a[i];
		if (a[i] == 0) break;
		n++;
	}
	memset(dp, -1, sizeof(dp));

	cout << go(0, 0, 0) << '\n';
	return 0;
}