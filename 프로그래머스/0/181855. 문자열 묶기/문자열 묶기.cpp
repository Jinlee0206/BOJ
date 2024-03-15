#include <bits/stdc++.h>

using namespace std;

const int INF = 2147000000;
unordered_map<int, int> mp;

int solution(vector<string> strArr) {
    int answer = -INF;
    
    for(int i = 0; i< strArr.size(); i++)
    {
        int tmp = strArr[i].size();
        mp[tmp]++;
    }
    
    for(const auto& a : mp)
    {
        answer = max(answer, (int)a.second);
    }
    
    /*for(auto it = mp.begin(); it != mp.end(); it++)
    {
        if(answer < it->second)
        {
            answer = it->second;
        }
    }*/
    
    return answer;
}