#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

int main()
{
	int n;
	cin >> n;

	stack<int> s;

	for (int i = 0; i < n; i++)
	{
		string str;
		cin >> str;

		if (str == "push")
		{
			int a;
			cin >> a;
			s.push(a);
		}
		else if (str == "top")
		{
			if (!s.empty())
			{
				cout << s.top() << "\n";
			}
			else cout << -1 << "\n";
		}
		else if (str == "pop")
		{
			if (!s.empty())
			{
				cout << s.top() << "\n";
				s.pop();
			}
			else cout << -1 << "\n";
		}
		else if (str == "size") cout << s.size() << "\n";
		else if (str == "empty")
		{
			if (s.empty()) cout << 1 << "\n";
			else cout << 0 << "\n";
		}
	}

	return 0;
}