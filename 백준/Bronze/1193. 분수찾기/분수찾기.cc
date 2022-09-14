#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	int i = 1;
	while (n > i)
	{
		n -= i;
		i++;
	}

	if (i % 2 == 1) cout << i - n + 1 << "/" << n << "\n";
	else cout << n << "/" << i - n + 1 << "\n";

	return 0;
}