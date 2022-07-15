#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int n, m;

	while (true)
	{
		cin >> n >> m;

		if ((m == 0) && (n == 0)) break;
		else if (m % n == 0)	cout << "factor" << "\n";
		else if (n % m == 0) cout << "multiple" << "\n";
		else cout << "neither" << "\n";
	}

	return 0;
}