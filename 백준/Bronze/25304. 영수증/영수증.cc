#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int x, n , a, b, sum = 0;

	cin >> x >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> a >> b;
		sum += a * b;
	}

	if (x == sum) cout << "Yes" << "\n";
	else cout << "No" << "\n";

	return 0;
}