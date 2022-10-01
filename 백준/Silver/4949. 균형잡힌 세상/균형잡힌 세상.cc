#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	while (true)
	{
		string str;
		getline(cin, str);

		if (str == ".") break;

		stack<char> stk;
		bool flag = true;

		for (int i = 0; i < str.length(); i++)
		{
			if (str[i] == '(' || str[i] == '[') stk.push(str[i]);
			
			if (str[i] == ')')
			{
				if (stk.empty() || stk.top() == '[') flag = false;
				else stk.pop();
			}

			if (str[i] == ']')
			{
				if (stk.empty() || stk.top() == '(') flag = false;
				else stk.pop();
			}
		}
		if (flag && stk.empty()) cout << "yes" << "\n";
		else cout << "no\n";
	}

	return 0;
}