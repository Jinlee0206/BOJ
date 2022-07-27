#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n, idx = 1;
	cin >> n;

	vector<int> vec(n+1);
	vector<char> ch;
	stack<int> stk;

	for (int i = 1; i <= n; i++)
	{
		int a;
		cin >> a;
		vec[i] = a;
	}

	for (int i = 1; i <= n; i++)
	{
		stk.push(i);
		ch.push_back('+');

		while (1)
		{
			if (stk.empty()) break;

			if (stk.top() == vec[idx])
			{
				stk.pop();
				ch.push_back('-');
				idx++;
			}
			else break;
		}
	}

	if (!stk.empty()) cout << "NO" << "\n";
	else
	{
		for (int i = 0; i < ch.size(); i++)
		{
			cout << ch[i] << "\n";
		}
	}
 
	return 0;
}