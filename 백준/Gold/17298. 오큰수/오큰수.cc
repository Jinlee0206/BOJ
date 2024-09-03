// BOJ - 17298 : 오큰수
#include <bits/stdc++.h>
using namespace std;

const int INF = 2147000000;

int n, a[1000004], res[1000004];

stack<int> stk;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    memset(res, -1, sizeof(res));

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        while (stk.size() && a[stk.top()] < a[i])
        {
            res[stk.top()] = a[i];
            stk.pop();
        }
        stk.push(i);
    }

    for (int i = 0; i < n; i++) cout << res[i] << " ";
    
    return 0;
}