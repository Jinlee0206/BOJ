#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m, j, l, r, tmp, res= 0;

	cin >> n >> m >> j;

	l = 1;
	for (int i = 0; i < j; i++)
	{
		r = l + m - 1;
		cin >> tmp;

		if (tmp <= r && tmp >= l) continue;
		else
		{
			if (tmp > r)
			{
				l += tmp - r;
				res += tmp - r;
			}
			else
			{
				res += l - tmp;
				l = tmp;
			}
		}
	}

	cout << res << "\n";

	return 0;
}