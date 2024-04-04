// BOJ - 14002 : 가장 긴 증가하는 부분수열 4
#include <bits/stdc++.h>
using namespace std;

int n, lis[1004], len;
pair<int, int> a[1004];
stack<int> stk;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int num;
		cin >> num;
		auto lowerPos = lower_bound(lis, lis + len, num);
		if (*lowerPos == 0) len++;
		*lowerPos = num;
		a[i].first = (int)(lowerPos - lis);
		a[i].second = num;
	}
	cout << len << '\n';

	for (int i = n - 1; i >= 0; i--)
	{
		if (a[i].first == len - 1)
		{
			stk.push(a[i].second);
			len--;
		}
	}

	while (stk.size())
	{
		cout << stk.top() << ' ';
		stk.pop();
	}

	return 0;
}