#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int INF = 2147000000;
ll n, m, res = INF, a[100001];

// 결정 알고리즘
// 답이 되는지 확인
int Count(ll size)
{
    ll sum = 0;
    int cnt = 1;

    for (int i = 0; i < n; i++)
    {
        if (sum + a[i] > size) {
            cnt++;
            sum = a[i];
        }
        else sum += a[i];
    }
    return cnt;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    ll l = 0, r = 0, mid, mmax = -INF;

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        r += a[i];
        mmax = max(mmax, a[i]);
    }

    while (l <= r)
    {
        mid = (l + r) / 2;
        if (mid >= mmax && Count(mid) <= m)
        {
            res = mid;
            r = mid - 1;
        }
        else l = mid + 1;
    }

    cout << res << '\n';

    return 0;
}