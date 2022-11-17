#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>

using namespace std;

int n, x, res;
vector<int> v;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int a;
		cin >> a;
		v.push_back(a);
	}

	sort(v.begin(), v.end());

	cin >> x;

	int p1 = 0;
	int p2 = n - 1;

	while (p1 < p2)
	{
		if (v[p1] + v[p2] == x)
		{
			res++;
			p2--;
		}
		else if (v[p1] + v[p2] > x)
		{
			p2--;
		}
		else
		{
			p1++;
		}
	}
	cout << res << '\n';

	return 0;
}