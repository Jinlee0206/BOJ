#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int ch[500001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n;

	vector<int> a(n);
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}

	cin >> m;
	vector<int> b(m);
	for (int i = 0; i < m; i++)
	{
		cin >> b[i];
	}

	sort(a.begin(), a.end());

	for (int i = 0; i < m; i++)
	{
		int left = 0;
		int right = n - 1;

		while (left <= right)
		{
			int mid = (left + right) / 2;

			if (a[mid] == b[i])
			{
				ch[i] = 1;
				break;
			}
			else if (a[mid] > b[i]) right = mid - 1;
			else left = mid + 1;

		}
	}

	for (int i = 0; i < m; i++)
	{
		cout << ch[i] << " ";
	}
	
	return 0;
}