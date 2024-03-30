// BOJ - 7795 : 먹을 것인가 먹힐 것인가
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int t, n, m, res;
vector<int> v1, v2;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> t;
    while (t--)
    {
        res = 0;
        v1.clear();
        v2.clear();

        cin >> n >> m;

        for (int i = 0; i < n; i++)
        {
            int a;
            cin >> a;
            v1.push_back(a);
        }

        for (int i = 0; i < m; i++)
        {
            int a;
            cin >> a;
            v2.push_back(a);
        }

        sort(v1.begin(), v1.end());
        sort(v2.begin(), v2.end());

        for (int i = 0; i < v1.size(); i++)
        {
            res += (int)(lower_bound(v2.begin(), v2.end(), v1[i]) - v2.begin());
        }

        cout << res << '\n';
    }

    return 0;
}
