// BOJ - 1068 : 트리
#include <bits/stdc++.h>
using namespace std;

int n, root, k;
vector<int> adj[54];

int go(int here)
{
    int res = 0;
    int child = 0;

    for (int there : adj[here])
    {
        if (there == k) continue;
        res += go(there);
        child++;
    }
    if (child == 0) return 1;
    else return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int tmp;
        cin >> tmp;
        if (tmp == -1) root = i;
        else adj[tmp].push_back(i);
    }

    cin >> k;

    if(k == root) cout << 0 << '\n';
    else cout << go(root) << '\n';

    return 0;
}