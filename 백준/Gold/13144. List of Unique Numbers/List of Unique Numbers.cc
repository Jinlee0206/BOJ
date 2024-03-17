// BOJ-13144 : List of Unique Numbers 
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n, s, e, cnt[100004], a[100004];
ll res;

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
	res += (ll)(e - s) * (e - s + 1)/ 2;
	cout << res << '\n';
	
	return 0;
}
