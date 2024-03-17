// BOJ-1700 : 멀티탭 스케쥴링
#include <bits/stdc++.h>
using namespace std;

const int INF = 2147000000;
int n, k, a[104], res, visited[104];
vector<int> v;

// Optimal Algorithm
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> k;

	for (int i = 0; i < k; i++) {
		cin >> a[i];
	}

	for (int i = 0; i < k; i++)
	{
		if (!visited[a[i]])
		{
			if (v.size() == n)
			{
				int last_idx = 0, pos = 0;

				for (int _a : v)
				{
					int here_pick = INF;

					for (int j = i + 1; j < k; j++)
					{
						if (_a == a[j])
						{
							here_pick = j;
							break;
						}
					}
			
					if (last_idx < here_pick)
					{
						last_idx = here_pick;
						pos = _a;
					}
				}
				visited[pos] = 0;
				res++;
				v.erase(find(v.begin(), v.end(), pos));
			}
			v.push_back(a[i]);
			visited[a[i]] = 1;
		}
	}

	cout << res << '\n';

	return 0;
}