#include <bits/stdc++.h>

using namespace std;

const int INF = 2147000000;
int psum[100001];
int n, k, tmp, sum = -INF;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> k;

    for (int i = 1; i <= n; i++)
    {
        cin >> tmp;
        psum[i] = psum[i - 1] + tmp; // 구간합
    }
    for (int i = k; i <= n; i++)
    {
        sum = max(sum, psum[i] - psum[i - k]);
    }
    cout << sum << '\n';

    return 0;
}