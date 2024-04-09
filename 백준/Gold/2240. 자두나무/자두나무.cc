// BOJ - 2240 : 자두나무
#include<bits/stdc++.h>
using namespace std;
const int INF = 2147000000;

int n, m, dp[1004][2][34], b[1004];

int go(int idx, int tree, int cnt)
{
    if (cnt < 0) return -1e9;
    if (idx == n) return cnt == 0 ? 0 : -1e9;

    int& res = dp[idx][tree][cnt];
    if (res != -1) return res;

    return res = max(go(idx + 1, tree ^ 1, cnt - 1), go(idx + 1, tree, cnt)) + (tree == b[idx] - 1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    memset(dp, -1, sizeof(dp));

    cin >> n >> m;

    for (int i = 0; i < n; i++) cin >> b[i];
    cout << max(go(0, 1, m - 1), go(0, 0, m)) << '\n';

    return 0;
}