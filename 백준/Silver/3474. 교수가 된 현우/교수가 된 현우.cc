// BOJ - 3474 : 교수가 된 현우
#include<bits/stdc++.h>
using namespace std;
const int INF = 2147000000;

int t;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int res2 = 0, res5 = 0;

        // 10
        // 1 2 3 4 5 6 7 8 9 10
        //   1   1   1   1   1  => 5 (10/2)
        //       1       1      => 2 (10/4)
        //               1      => 1 (10/8) => 8
        for (int i = 2; i <= n; i *= 2)
        {
            res2 += n / i;
        }
        for (int i = 5; i <= n; i *= 5)
        {
            res5 += n / i;
        }
        cout << min(res2, res5) << '\n';
    }
    return 0;
}