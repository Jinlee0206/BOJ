#include <bits/stdc++.h>

using namespace std;

// LIS (prev_list 활용)

int n, a[1001], res = 1, cnt[1001], idx;
int prev_list[1001];
vector<int> v;

void go(int idx)
{
    if (idx == -1) return;
    v.push_back(a[idx]);
    go(prev_list[idx]);
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    fill(cnt, cnt + 1001, 1);
    fill(prev_list, prev_list + 1001, -1);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (a[j] < a[i] && cnt[i] < cnt[j] + 1)
            {
                cnt[i] = cnt[j] + 1;
                prev_list[i] = j;
                if (res < cnt[i])
                {
                    res = cnt[i];
                    idx = i;
                }
            }
        }
    }

    cout << res << '\n';
    go(idx);
    for (int i = v.size() - 1; i >= 0; i--) cout << v[i] << " ";
    //cout << '\n';
    //for (int i = 0; i < n; i++) cout << prev_list[i] << " ";

    return 0;
}