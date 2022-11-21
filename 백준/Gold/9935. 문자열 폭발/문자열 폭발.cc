#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>

using namespace std;

string a, b, res;

int main()
{
	cin >> a >> b;

	// 1. pivot 알고리즘
	// idx 기반 알고리즘
	/*
	for (char ch : a)
	{
		res += ch;
		if (res.size() >= b.size() && res.substr(res.size() - b.size(), b.size()) == b)
		{
			res.erase(res.end() - b.size(), res.end());
		}
	}

	if (!res.size()) cout << "FRULA" << '\n';
	else cout << res << '\n';

	*/

	// 2. stack 사용

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
				for (int i : ss)
				{
					stk.push(i);
				}
			}
		}
	}

	if (stk.empty()) cout << "FRULA\n";
	else
	{
		while (stk.size())
		{
			res += stk.top(); stk.pop();
		}
		reverse(res.begin(), res.end());
		cout << res << '\n';
	}

	return 0;
}