// BOJ - 1072 : 게임
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF = 1e18;
ll n, m, res = -1, z, l, r, mid;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    z = (m * 100) / n;

    l = 1;
    r = 1e9; // 10억
    
    while (l <= r)
    {
        mid = (l + r) / 2;
        if ((m + mid) * 100 / (n + mid) > z)
        {
            res = mid;
            r = mid - 1;
        }
        else l = mid + 1;
    }

    cout << res << '\n';

    return 0;
}
