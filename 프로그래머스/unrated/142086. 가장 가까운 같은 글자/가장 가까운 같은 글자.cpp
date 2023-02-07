#include <bits/stdc++.h>

using namespace std;

// 키가 작을 때 검색이 빠름
unordered_map<char,int> um;

vector<int> solution(string s) {
    vector<int> answer;
    
    for(int i = 0; i < s.size(); i++)
    {
        // 찾음
        if(um.find(s[i]) != um.end())
        {
            int idx = um[s[i]];
            answer.push_back(i - idx);
            um[s[i]] = i;
        }
        // 못찾음
        else {
            um[s[i]] = i;
            answer.push_back(-1);
        }
    }
    return answer;
}