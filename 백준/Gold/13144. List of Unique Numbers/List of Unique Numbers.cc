#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

ll s, e, cnt[100001], n, a[100001], res;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}

	while (e < n)
	{
		if (!cnt[a[e]])
		{
			cnt[a[e]]++;
			e++;
		}
		else
		{
			res += (e - s);
			cnt[a[s]]--;
			s++;
		}
	}
	res += (long long)(e - s) * (e - s + 1) / 2;

	cout << res << '\n';

	return 0;
}