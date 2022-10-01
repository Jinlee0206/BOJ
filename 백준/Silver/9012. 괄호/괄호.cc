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

	int n;
	cin >> n;

	stack<char> stk;

	bool flag;

	for (int i = 0; i < n; i++)
	{
		flag = true;
		string str;
		cin >> str;

		for (int j = 0; j < str.size(); j++)
		{
			if (str[j] == '(') stk.push(str[j]);
			else
			{
				if (stk.empty())
				{
					cout << "NO" << "\n";
					flag = false;
					break;
				}
				else stk.pop();
			}
		}

		if (stk.empty() && flag == true) cout << "YES" << "\n";
		else if (!stk.empty() && flag == true) cout << "NO" << "\n";

		while (!stk.empty()) stk.pop();
	}


	return 0;
}