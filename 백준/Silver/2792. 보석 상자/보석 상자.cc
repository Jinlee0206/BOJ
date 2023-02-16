#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int INF = 2147000000;
ll n, m, a[300001], res = INF;

bool check(ll mid)
{
    ll num = 0;
    for (int i = 0; i < m; i++)
    {
        num += a[i] / mid;
        if (a[i] % mid) num++;
    }
    return n >= num;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    ll lo = 1, hi = 0, mid;
    for (int i = 0; i < m; i++) cin >> a[i], hi = max(hi, a[i]);

    while (lo <= hi)
    {
        mid = (lo + hi) / 2;
        if (check(mid))
        {
            res = min(res, mid);
            hi = mid - 1;
        }
        else lo = mid + 1;
    }

    cout << res << '\n';
    return 0;
}