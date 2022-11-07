#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int n, m, x;
string s;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> m;

	for (int i = 0; i < m; i++)
	{
		cin >> s;

		if (s[0] == 'a' && s[1] == 'd')
		{
			cin >> x;
			n |= (1 << x);
		}
		else if (s[0] == 'r')
		{
			cin >> x;
			n &= ~(1 << x);
		}
		else if (s[0] == 'c')
		{
			cin >> x;
			cout << ((n & (1 << x)) == 0 ? 0 : 1) << "\n";
		}
		else if (s[0] == 't')
		{
			cin >> x;
			n ^= (1 << x);
		}
		else if (s[0] == 'a' && s[1] == 'l') n = (1 << 21) - 1;
		else n = 0;
	}

	return 0;
}