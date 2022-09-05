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

	int n, cnt = 0;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		string str;
		cin >> str;
		
		stack<char> stk;

		for (int j = 0; j < str.length(); j++)
		{
			if (!stk.empty() && stk.top() == str[j])
			{
				stk.pop();
				continue;
			}
			stk.push(str[j]);
		}

		if (stk.empty()) cnt++;
	}

	cout << cnt << "\n";

	return 0;
}