// BOJ - 1753 : 최단 경로
#include<bits/stdc++.h>
using namespace std;
const int INF = 2147000000;

int V, E, K, u, v, w;
vector<pair<int, int>> adj[20001];
int dist[20001];
bool visited[20001];
priority_queue < pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

int main() {
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
    dist[K] = 0; // 첫 시작지점의 거리값은 0으로 설정
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
            if (dist[_there] > dist[here] + _dist) // 내가 탐색하려는 정점이 다음 정점까지의 거리값과의 합보다 작은 경우 갱신
            {
                dist[_there] = dist[here] + _dist;
                pq.push({ dist[_there], _there });
            }
        }
    }

    for (int i = 1; i <= V; i++)
    {
        if (dist[i] == INF) cout << "INF\n";
        else cout << dist[i] << '\n';
    }

    return 0;
}