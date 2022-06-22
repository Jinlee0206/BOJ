#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Counting Sort


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	int arr[10001] = { 0 , };


	for (int i = 1; i <= n; i++)
	{
		int a;
		cin >> a;
		arr[a]++;
	}

	for (int i = 1; i <= 10000; i++)
	{
		if (arr[i] != 0)
		{
			for (int j = 0; j < arr[i]; j++)
			{
				cout << i << "\n";
			}
		}
	}

	return 0;
}
