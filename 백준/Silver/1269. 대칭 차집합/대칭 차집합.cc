#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n, m, cnt = 0;
	cin >> n >> m;

	map<int, bool> list;

	for (int i = 0; i < n; i++)
	{
		int n;
		cin >> n;
		list.insert({ n, true });
		cnt++;
	}

	for (int i = 0; i < m; i++)

	{
		int n;
		cin >> n;
		if (list[n])
		{
			list.insert({ n, false });
			cnt--;
		}
		else {
			list.insert({ n,true });
			cnt++;
		}
	}

	cout << cnt << '\n';

	return 0;
}