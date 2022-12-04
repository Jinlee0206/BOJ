#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, k, cnt;
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

	cin >> k;

	sort(v.begin(), v.end());

	int p1, p2;
	p1 = 0, p2 = v.size() - 1;

	while (p1 < p2)
	{
		if (v[p1] + v[p2] == k)
		{
			p1++;
			p2--;
			cnt++;
		}
		else if (v[p1] + v[p2] > k) p2--;
		else if (v[p1] + v[p2] < k) p1++;
	}

	cout << cnt << '\n';

	return 0;
}