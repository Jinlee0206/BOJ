#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

typedef long long ll;
using namespace std;

int n, k;
ll res = 0;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> k;

    vector<pair<ll, ll>> v(n);
    vector<ll> vv(k);

    for (int i = 0; i < n; i++)
    {
        cin >> v[i].first >> v[i].second;
    }

    for (int i = 0; i < k; i++) cin >> vv[i];

    // 가장 적은 무게의 보석들로 정렬
    sort(v.begin(), v.end());
    // 가장 적은 무게를 담을 수 있는 가방을 기준으로 정렬
    sort(vv.begin(), vv.end());

    priority_queue <ll> pq;

    int j = 0;
    for (int i = 0; i < k; i++)
    {
        while (j < n && v[j].first <= vv[i]) pq.push(v[j++].second);
        if (pq.size())
        {
            res += pq.top();
            pq.pop();
        }
    }

    cout << res << '\n';

    return 0;
}