#include <bits/stdc++.h>

using namespace std;

int t, n, a, m, b;
vector<int> va;

int check(int b, vector<int>& v)
{
    int start= 0, end = v.size() - 1;
    int mid;

    while (start <= end)
    {
        mid = (end + start) / 2;
        if (v[mid] > b) end = mid - 1;
        else if (v[mid] == b) return 1;
        else start = mid + 1;
    }
    return 0;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> t;

    while (t--)
    {
        cin >> n;
        va.clear();
        for (int i = 0; i < n; i++)
        {
            cin >> a;
            va.push_back(a);
        }
        sort(va.begin(), va.end());
        cin >> m;
        for (int i = 0; i < m; i++)
        {
            cin >> b;
            cout << check(b, va) << '\n';
        }
    }

    return 0;
}