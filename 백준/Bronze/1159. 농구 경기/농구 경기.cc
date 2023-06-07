#include <bits/stdc++.h>

using namespace std;

int alpha[26];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        string str;
        cin >> str;
        alpha[str[0] - 'a']++;
    }

    string answer;
    for (int i = 0; i < 26; i++)
    {
        if (alpha[i] >= 5) answer += (char)(i + 'a');
    }

    if (answer != "") cout << answer << '\n';
    else cout << "PREDAJA" << '\n';

    return 0;
}