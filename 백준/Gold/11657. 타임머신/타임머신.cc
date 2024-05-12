// BOJ - 11657 : 타임머신
#include <bits/stdc++.h>
using namespace std;
const int INF = 987654321;
typedef long long ll;

ll n, m, a, b, c, dist[1004];
vector<pair<int, int>> adj[1004];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;
	fill(dist, dist + n + 1, INF);
	for (int i = 0; i < m; i++)
	{
		cin >> a >> b >> c;
		adj[a - 1].push_back({ b - 1, c });
	}
	dist[0] = 0;
	queue<int> q;

	for (int i = 0; i < n; i++)
	{
		for (int here = 0; here < n; here++)
		{
			for (auto there : adj[here])
			{
				int cost = there.second;
				int to = there.first;
				if (dist[here] != INF && dist[here] + cost < dist[to])
				{
					if (i == n - 1) q.push(to);
					dist[to] = dist[here] + cost;
				}
			}
		}
	}

	if (q.size()) cout << -1 << '\n';
	else 
		for (int i = 1; i < n; i++) 
			cout << (dist[i] == INF ? -1 : dist[i]) << "\n";

	return 0;
}