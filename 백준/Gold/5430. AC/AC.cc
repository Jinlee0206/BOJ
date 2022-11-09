#include <iostream>
#include <string>
#include <vector>
#include <deque>

using namespace std;

int t, n;
string s, str;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> t;

    while (t--)
    {
        cin >> s >> n;

        deque<int> deq;

        cin >> str;

        string tmp = "";

        for (int i = 0; i < str.size(); i++)
        {
            if (isdigit(str[i]))
            {
                tmp += str[i];
            }
            else
            {
                if (!tmp.empty())
                {
                    deq.push_back(stoi(tmp));
                    tmp = "";
                }
            }
        }

        bool isReverse = false;
        bool isError = false;

        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == 'R')
            {
                if (isReverse) isReverse = false;
                else isReverse = true;
            }
            else if (s[i] == 'D')
            {
                if (deq.empty())
                {
                    isError = true;
                    break;
                }

                if (isReverse)
                {
                    deq.pop_back();
                }
                else deq.pop_front();
            }
        }

        if (!isError)
        {
            cout << "[";
            if (!isReverse)
            {
                for (int i = 0; i < deq.size(); i++)
                {
                    if (i == (deq.size() - 1)) cout << deq[i];
                    else cout << deq[i] << ",";
                }
            }
            else
            {
                for (int i = deq.size() - 1; i >= 0; i--)
                {
                    if (i == 0) cout << deq[i];
                    else cout << deq[i] << ",";
                }
            }
            cout << "]" << "\n";
        }
        else cout << "error" << "\n";
        
    }
    return 0;
}