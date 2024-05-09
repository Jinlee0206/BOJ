#include <bits/stdc++.h>

using namespace std;

string solution(vector<string> id_pw, vector<vector<string>> db) {
    string answer = "fail";
    
    map<string, string> mp;
    for(int i = 0; i< db.size(); i++)
    {
        mp[db[i][0]] = db[i][1];
    }
    
    string id = id_pw[0];
    string pw = id_pw[1];
    
    if(mp.find(id) != mp.end())
    {
        if(mp[id] == pw) answer = "login";
        else answer = "wrong pw";
    }
    
    return answer;
}