#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m, cnt =0;
	cin >> n >> m;

	vector<int> vec(n);

	for (int i = 0; i < n; i++)
	{
		cin >> vec[i];
	}

	sort(vec.begin(), vec.end(), greater<>());

	for (int i = 0; i < n; i++)
	{
		for (int j = i+1; j < n; j++)
		{
			if (vec[i] + vec[j] == m) cnt++;
		}
	}

	cout << cnt << "\n";

	return 0;
}