// BOJ - 1535 : 안녕
#include<bits/stdc++.h>
using namespace std;
const int INF = 2147000000;

int n, a, dp[101], cost[101], happy[101];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    for (int i = 0; i < n; i++) cin >> cost[i];
    for (int i = 0; i < n; i++) cin >> happy[i];

    for (int i = 0; i < n; i++)
    {
        for (int j = 100; j > cost[i]; j--)
        {
            dp[j] = max(dp[j], dp[j - cost[i]] + happy[i]);
        }
    }
    cout << dp[100] << '\n';

    return 0;
}