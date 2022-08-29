#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, p1 = 0, p2 = 0, tmp = 2147000000, res_p1 = 0, res_p2 = 0;
	cin >> n;

	p2 = n - 1;

	vector<int> vec;

	for (int i = 0; i < n; i++)
	{
		int a;
		cin >> a;
		vec.push_back(a);
	}

	sort(vec.begin(), vec.end());

	while (p1 < p2)
	{
		int sum = vec[p1] + vec[p2];

		if (tmp > abs(sum))
		{
			res_p1 = vec[p1];
			res_p2 = vec[p2];
			tmp = abs(sum);
			if (sum == 0) break;
		}
		else if (sum < 0) p1++;
		else p2--;
	}

	cout << res_p1 << " " << res_p2 << "\n";

	return 0;
}