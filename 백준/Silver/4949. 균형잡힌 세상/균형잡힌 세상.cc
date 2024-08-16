// BOJ - 4949 : 균형잡힌 세상
#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	while (true)
	{
		string str;
		getline(cin, str);

		if (str == ".") break;

		stack<char> stk;
		bool flag = true;

		for (int i = 0; i < str.size(); i++)
		{
			if (str[i] == '(' || str[i] == '[') stk.push(str[i]);
			else if (str[i] == ')')
			{
				if (stk.empty() || stk.top() == '[')
				{
					flag = false;
					break;
				}
				else
				{
					stk.pop();
				}
			}
			else if (str[i] == ']')
			{
				if (stk.empty() || stk.top() == '(')
				{
					flag = false;
					break;
				}
				else stk.pop();
			}
		}
		if (stk.empty() && flag) cout << "yes" << '\n';
		else cout << "no" << '\n';
	}
	
	return 0;
}

