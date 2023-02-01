#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int num = 0;
bool flag = false;
string s, tmp = "";

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> s;

    for (int i = 0; i <= s.size(); i++)
    {
        if (s[i] == '+' || s[i] == '-' || s[i] == '\0')
        {
            if (flag) num -= stoi(tmp);
            else num += stoi(tmp);

            if (s[i] == '-') flag = true;
            tmp = "";
            continue;
        }
        tmp += s[i];
    }

    cout << num << '\n';
    
    return 0;
}