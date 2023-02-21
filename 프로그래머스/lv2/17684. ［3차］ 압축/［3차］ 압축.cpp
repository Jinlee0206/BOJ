#include <bits/stdc++.h>

using namespace std;

int num = 1;
unordered_map<string, int> um;

void make_default_dictionary()
{
    for (char C = 'A'; C <= 'Z'; C++)
    {
        string str = "";
        str += C;
        um[str] = num++;
    }
}

void Compression(string msg, vector<int> &v)
{
    string Cur = "";
    for(int i = 0; i< msg.size(); i++)
    {
        Cur += msg[i];
        if(um[Cur] == 0)
        {
            um[Cur] = num++;
            Cur = Cur.substr(0, Cur.length() - 1);
            v.push_back(um[Cur]);
            Cur = "";
            //cout << i << '\n';
            i--;
        }
    }
    v.push_back(um[Cur]);
}

vector<int> solution(string msg) {
    vector<int> answer;
    
    make_default_dictionary();
    //for (auto i : um) cout << i.first << " " << i.second << '\n';
    Compression(msg, answer);
    
    return answer;
}