#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

// 경우의 수
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;

	while (t)
	{
		int n;
		cin >> n;

		map<string, int> list;

		for (int i = 0; i < n; i++)
		{
			string name, type;
			cin >> name >> type;

			list[type]++;
		}

		long long res = 1;
		
		for (auto c : list)
		{
			res *= ((long long)c.second + 1);
		}
		res--;
		
		cout << res << "\n";

		t--;
	}

	return 0;
}