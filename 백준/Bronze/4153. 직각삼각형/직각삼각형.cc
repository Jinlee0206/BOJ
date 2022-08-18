#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	while (true)
	{
		int a, b, c;
		cin >> a >> b >> c;

		if (a == 0 && b == 0 && c == 0) break;

		if (pow(a, 2) + pow(b, 2) == pow(c, 2)) cout << "right" << "\n";
		else if (pow(b, 2) + pow(c, 2) == pow(a, 2)) cout << "right" << "\n";
		else if (pow(c, 2) + pow(a, 2) == pow(b, 2)) cout << "right" << "\n";
		else cout << "wrong" << "\n";
	}


	return 0;
}