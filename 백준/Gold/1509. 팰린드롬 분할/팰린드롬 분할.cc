// BOJ - 1509 : 팰린드롬 분할
#include<bits/stdc++.h>
using namespace std;
const int INF = 2147000000;

int dp[2504][2504];
int dp2[2504];
string s;

int go(int here)
{
    if (here == s.size()) return 0;
    if (dp2[here] != INF) return dp2[here];
    int& res = dp2[here];
    for (int i = 1; i + here <= s.size(); i++)
    {
        if (dp[here][i]) res = min(res, go(here + i) + 1);
    }
    //cout << here << " : " << res << '\n';
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> s;

    for (int i = 0; i < s.size(); i++) dp[i][1] = 1;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == s[i + 1]) dp[i][2] = 1;
    }
    for (int _size = 3; _size <= s.size(); _size++)
    {
        for (int j = 0; j + _size <= s.size(); j++)
        {
            if (s[j] == s[j + _size - 1] && dp[j + 1][_size - 2]) dp[j][_size] = 1;
        }
    }

    fill(dp2, dp2 + 2504, INF);
    cout << go(0) << '\n';

    return 0;
}