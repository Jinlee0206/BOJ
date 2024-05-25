// BOJ - 3986 :	좋은 단어
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

int n, cnt;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n;
	while (n--)
	{
		string str;
		cin >> str;

		stack<char> stk;

		for (int i = 0; i < str.size(); i++)
		{
			if (stk.size() && stk.top() == str[i]) stk.pop();
			else stk.push(str[i]);
		}
		if (stk.empty()) cnt++;
	}
	cout << cnt << '\n';

	return 0;
}