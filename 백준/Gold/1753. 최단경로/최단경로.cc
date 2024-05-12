// BOJ - 11404 : 플로이드
#include <bits/stdc++.h>
using namespace std;

const int INF = 2147000000;
int V, E, K, u, v, w;
vector<pair<int, int>> adj[20001];
int dist[20001];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> V >> E >> K;
	fill(dist, dist + 20001, INF);
	for (int i = 0; i < E; i++)
	{
		cin >> u >> v >> w;
		adj[u].push_back({ w,v });
	}

	pq.push({ 0,K });
	dist[K] = 0;
	while (pq.size())
	{
		int here = pq.top().second;
		int here_dist = pq.top().first;
		pq.pop();
		if (dist[here] != here_dist) continue;
		for (pair<int, int> there : adj[here])
		{
			int _dist = there.first;
			int _there = there.second;
			if (dist[_there] > dist[here] + _dist)
			{
				dist[_there] = dist[here] + _dist;
				pq.push({ dist[_there], _there });
			}
		}
	}

	for (int i = 1; i <= V; i++)
	{
		if (dist[i] == INF) cout << "INF\n";
		else cout << dist[i] << "\n";
	}

	return 0;
}