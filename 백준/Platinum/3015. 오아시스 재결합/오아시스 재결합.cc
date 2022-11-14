#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>

typedef long long ll;

using namespace std;

int n, tmp;
ll res;
stack<pair<ll, ll>> stk;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> tmp;
		int cnt = 1;

		while (stk.size() && stk.top().first <= tmp)
		{
			res += stk.top().second;
			if (stk.top().first == tmp) cnt = stk.top().second + 1;
			else cnt = 1;
			stk.pop();
		}
		if (stk.size()) res++;
		stk.push({ tmp, cnt });
	}

	cout << res << "\n";

	return 0;
}