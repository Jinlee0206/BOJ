// BOJ-1325 효율적인 해킹
#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> adj[10001];
int visited[10001], dp[10001], mx;

// 해당 지점에 대한 최대 연결 값 구하기
int dfs(int here)
{
    visited[here] = 1;
    int res = 1;

    for (int there : adj[here])
    {
        if (visited[there]) continue;
        res += dfs(there);
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[b].push_back(a);
    }

    // 모든 정점에 대하여 탐색 진행
    for (int i = 1; i <= n; i++)
    {
        memset(visited, 0, sizeof(visited)); // 방문처리 배열은 초기화
        dp[i] = dfs(i); // 각 정점에 대한 값 dp배열에 저장
        mx = max(dp[i], mx); // 최대값 저장
    }
    
    for (int i = 1; i <= n; i++) if (mx == dp[i]) cout << i << ' ';

    return 0;
}