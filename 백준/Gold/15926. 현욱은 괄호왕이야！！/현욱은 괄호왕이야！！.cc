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

	stk.push(-1);
	for (int i = 0; i < n; i++)
	{
		if (s[i] == '(') stk.push(i);
		if (s[i] == ')')
		{
			stk.pop();
			if (!stk.empty())
			{
				res = max(res, i - stk.top());
			}
			else stk.push(i);
		}
	}

	cout << res << "\n";

	return 0;
}