// BOJ-9935 : 문자열 폭발
#include<bits/stdc++.h>
using namespace std;

string a, b, res;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> a >> b;

	stack<char> stk;

	for (char ch : a)
	{
		stk.push(ch);
		if (stk.size() >= b.size() && stk.top() == b[b.size() - 1])
		{
			string ss = "";
			for (char i : b)
			{
				ss += stk.top();
				stk.pop();
			}
			reverse(ss.begin(), ss.end());

			if (b != ss)
			{
				for (char i : ss)
				{
					stk.push(i);
				}
			}
		}
	}

	if (stk.empty()) cout << "FRULA\n";
	else {
		while (stk.size())
		{
			res += stk.top();
			stk.pop();
		}
		reverse(res.begin(), res.end());
		cout << res << "\n";
	}

	return 0;
}
