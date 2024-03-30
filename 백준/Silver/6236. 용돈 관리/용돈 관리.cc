// BOJ - 6236 : 용돈 관리
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, m, mx, l = 1, r, mid, res = 1e18;
ll a[100004];

bool go() {
    if (mx > mid) return false;
    int num = 1;
    ll sum = mid;
    
    for (int i = 0; i < n; i++) {
        if (sum - a[i] < 0) {
            num++;
            sum = mid;
        }
        sum -= a[i];
    }
    return num <= m;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m;
    int sum = 0;
    
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
        mx = max(mx, a[i]);
    }
    
    l = 1, r = sum;
    
    while (l <= r) {
        mid = (r + l) / 2;
        if (go()) {
            r = mid - 1;
            res = min(res, mid);
        }
        else l = mid + 1;
    }
    cout << res << "\n";

    return 0;
}
