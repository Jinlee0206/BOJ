#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

int main()
{
	int n;
	cin >> n;

	stack<char>s;

	bool isCorrect = true;

	for (int i = 0; i < n; i++)
	{
		string str;
		cin >> str;
		isCorrect = true;

		for (int j = 0; j < str.size(); j++)
		{
			if (str[j] == '(') s.push(str[i]);
			else 
			{
				if (s.empty())
				{
					cout << "NO" << "\n";
					isCorrect = false;
					break;
				}
				else s.pop();
			}
		}
		
		if (s.empty() && isCorrect == true) cout << "YES" << "\n";
		else if (!s.empty() && isCorrect == true) cout << "NO" << "\n";

		while (!s.empty()) s.pop();
	}

	return 0;
}