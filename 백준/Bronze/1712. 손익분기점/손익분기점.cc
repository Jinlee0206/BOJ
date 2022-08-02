#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int a, b, c, cnt = -1;
	cin >> a >> b >> c;

	int val = c - b;

	if (val <= 0) cnt = -1;
	else
	{
		cnt = a / val + 1;
	}

	cout << cnt << "\n";

	return 0;
}