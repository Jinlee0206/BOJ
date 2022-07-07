#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

int main()
{
	int n, sum = 0;
	cin >> n;

	stack<int> s;

	for (int i = 0; i < n; i++)
	{
		int a;
		cin >> a;

		if(a != 0) s.push(a);
		else s.pop();
	}

	while (!s.empty())
	{
		int tmp;
		tmp = s.top();
		s.pop();
		sum += tmp;
	}

	cout << sum << "\n";
	return 0;
}