#include <bits/stdc++.h>

using namespace std;

int a[15004];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, cnt = 0;
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    sort(a, a + n);

    int p1, p2;
    p1 = 0;
    p2 = n-1;

    while (p1 < p2)
    {
        if (a[p1] + a[p2] > m) p2--;
        else if (a[p1] + a[p2] == m)
        {
            cnt++;
            p1++;
            p2--;
        }
        else p1++;
    }

    cout << cnt << '\n';

    return 0;
}