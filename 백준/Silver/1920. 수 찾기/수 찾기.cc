#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> v;

void binarySearch(int target)
{
	int start = 0;
	int end = v.size()-1;
	int mid;

	while (start <= end)
	{
		mid = (start + end) / 2;

		if (v[mid] == target)
		{
			cout << '1' << "\n";
			return;
		}
		else if (v[mid] < target) start = mid + 1;
		else end = mid - 1;
	} 

	cout << '0' << "\n";
	return;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int a;
		cin >> a;
		v.push_back(a);
	}

	sort(v.begin(), v.end());

	int m;
	cin >> m;
	
	for (int i = 0; i < m; i++)
	{
		int b;
		cin >> b;
		binarySearch(b);
		/*if (binary_search(v.begin(), v.end(), b)) cout << "1\n";
		else cout << "0\n";*/
	}

	return 0;
}