#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <cstring>

using namespace std;

int res[1000004];
int v[1000004];
stack<int> s;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	memset(res, -1, sizeof(res));
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
		while (!s.empty() && v[s.top()] < v[i])
		{
			res[s.top()] = v[i];
			s.pop();
		}
		s.push(i);
	}

	for (int i = 0; i < n; i++)
	{
		cout << res[i] << " ";
	}

	return 0;
}