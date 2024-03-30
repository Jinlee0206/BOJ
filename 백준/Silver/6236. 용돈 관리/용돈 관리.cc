#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, m, mx, l = 1, h, mid, rets = 1e18;
ll a[100004];

bool go() {
    if (mx > mid)
        return false;
    int num = 0, sum = mid;
    for (int i = 0; i < n; i++) {
        if (sum - a[i] < 0) {
            num++;
            sum = mid;
        }
        sum -= a[i];
    }
    if (sum != mid)num++;
    return num <= m;
}

int main() {
    cin >> n >> m;
    int sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i]; mx = max(mx, a[i]);
    }
    l = 1, h = sum;
    while (l <= h) {
        mid = (h + l) / 2;
        if (go()) {
            h = mid - 1;
            rets = min(rets, mid);
        }
        else l = mid + 1;
    }
    cout << rets << "\n";

    return 0;
}
