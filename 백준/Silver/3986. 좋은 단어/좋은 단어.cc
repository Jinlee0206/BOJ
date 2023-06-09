#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, cnt = 0;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        stack<char> stk;
        string str;
        cin >> str;

        for (int j = 0; j < str.size(); j++)
        {
            if (!stk.empty() && stk.top() == str[j]) stk.pop();
            else stk.push(str[j]);
        }
        if (stk.empty()) cnt++;
    }
    cout << cnt << '\n';

    return 0;
}