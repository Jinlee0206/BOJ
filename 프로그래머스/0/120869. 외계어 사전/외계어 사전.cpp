#include <bits/stdc++.h>

using namespace std;



int solution(vector<string> spell, vector<string> dic) {
    int answer = 2;
    
    string tmp = "";
    for(int i = 0; i< spell.size(); i++) tmp += spell[i][0];
    sort(tmp.begin(), tmp.end());
    
    for(int i = 0; i<dic.size(); i++)
    {
        sort(dic[i].begin(), dic[i].end());
    }
    
    for(int i = 0; i<dic.size(); i++)
    {
        if(dic[i].find(tmp) == string::npos) continue;
        answer = 1;
        return answer;
    }
    
    return answer;
}