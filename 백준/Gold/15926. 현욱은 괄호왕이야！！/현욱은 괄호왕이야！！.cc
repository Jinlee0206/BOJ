#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>

using namespace std;

int n, d[200001], cnt, res;
string s;
stack<int> stk;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> s;

	for (int i = 0; i < n; i++)
	{
		if (s[i] == '(') stk.push(i);
		else if (stk.size())
		{
			d[i] = d[stk.top()] = 1;
			stk.pop();
		}
	}

	for (int i = 0; i < n; i++)
	{
		if (d[i])
		{
			cnt++;
			res = max(res, cnt);
		}
		else cnt = 0;
	}

	cout << res << "\n";

	return 0;
}