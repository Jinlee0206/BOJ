// BOJ - 1325 : 효율적인 해킹
#include <bits/stdc++.h>
using namespace std;

const int INF = 2147000000;

int n, m, visited[10004], dp[10004], mx = -INF;
vector<int> adj[10004];

int dfs(int here)
{
    int res = 1;
    visited[here] = 1;
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
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m;

    /*
    1 -> 3
    2 -> 3
    3 -> 4, 5
    4 
    5 
    */

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[b].push_back(a);
    }

    for (int i = 1; i <= n; i++)
    {
        memset(visited, 0, sizeof(visited));
        dp[i] = dfs(i);
        mx = max(mx, dp[i]);
    }

    for (int i = 1; i <= n; i++) if (mx == dp[i]) cout << i << ' ';

    return 0;
}