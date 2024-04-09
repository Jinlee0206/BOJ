// BOJ - 2098 : 외판원 순회
#include<bits/stdc++.h>
using namespace std;
#define max_n 16
const int INF = 214700000;

int n, w[max_n][max_n], dp[max_n][1 << max_n];

int tsp(int here, int visited)
{
    if (visited == (1 << n) - 1)
    {
        return w[here][0] ? w[here][0] : INF;
    }

    int& res = dp[here][visited];
    if (res != -1) return res;
    res = INF;

    for (int i = 0; i < n; i++)
    {
        if (visited & (1 << i)) continue;
        if (w[here][i] == 0) continue;
        res = min(res, tsp(i, visited | (1 << i)) + w[here][i]);
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++) {
            cin >> w[i][j];
        }
    }

    memset(dp, -1, sizeof(dp));
    cout << tsp(0, 1) << '\n';

    return 0;
}