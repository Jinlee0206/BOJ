#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	while (true)
	{
		string str;
		getline(cin, str);

		stack<char> stk;
		bool ans = true;

		if (str.length() == 1 && str == ".") break;

		for (int i = 0; i < str.size(); i++)
		{
			if (str[i] == '(' || str[i] == '[')
			{
				stk.push(str[i]);
			}

			if (str[i] == ')')
			{
				if (stk.empty() || stk.top() == '[') ans = false;
				else stk.pop();
			}

			if (str[i] == ']')
			{
				if (stk.empty() || stk.top() == '(') ans = false;
				else stk.pop();
			}
		}

		if (stk.empty() && ans) cout << "yes" << "\n";
		else cout << "no" << "\n";
	}

	return 0;
}