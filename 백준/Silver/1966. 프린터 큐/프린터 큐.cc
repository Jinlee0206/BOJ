#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t_case, n, m, ipt;
	cin >> t_case;

	for (int i = 0; i < t_case; i++)
	{
		int cnt = 0;
		cin >> n >> m;

		queue<pair<int, int>> q;
		priority_queue<int> pq;

		for (int j = 0; j < n; j++)	
		{
			cin >> ipt;

			q.push({ j, ipt });
			pq.push(ipt);
		}

		while (!q.empty())
		{
			int idx = q.front().first;
			int val = q.front().second;
			q.pop();

			if (pq.top() == val)
			{
				pq.pop();
				++cnt;
				if (idx == m)
				{
					cout << cnt << "\n";
					break;
				}
			}
			else q.push({ idx, val });
		}
		
	}
	
	return 0;
}