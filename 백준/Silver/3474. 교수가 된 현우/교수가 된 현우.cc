#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

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

		int res2 = 0, res5 = 0;

		for (int j = 2; j <= a; j *= 2)
		{
			res2 += a / j;
		}

		for (int j = 5; j <= a; j *= 5)
		{
			res5 += a / j;
		}

		cout << min(res2, res5) << "\n";
	}
	
	return 0;
}