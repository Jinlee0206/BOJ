#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, s, sum = 0, p1 = 0, p2 = 0, minLen = 2147000000;

	cin >> n >> s;

	vector<int> vec;

	for (int i = 0; i < n; i++)
	{
		int a;
		cin >> a;
		vec.push_back(a);
	}

	while (p1 <= p2)
	{
		if (sum >= s)
		{
			minLen = min(minLen, p2 - p1);
			sum -= vec[p1++];
		}
		else if (p2 == n) break;
		else sum += vec[p2++];
	}

	if (minLen == 2147000000) cout << 0 << "\n";
	else cout << minLen << "\n";

	return 0;
}