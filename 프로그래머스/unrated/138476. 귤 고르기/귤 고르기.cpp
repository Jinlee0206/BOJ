#include <bits/stdc++.h>

using namespace std;

map<int, int> mp;
vector<pair<int,int>> v;

int solution(int k, vector<int> tangerine) {
    int answer = 0;
    
    for(int i = 0; i< tangerine.size(); i++)
    {
        mp[tangerine[i]]++;
    }
    
    for(int i = 0 ; i< mp.size(); i++)
    {
        v.push_back({mp[i], i});
    }
    
    sort(v.begin(), v.end(), greater<>());
    
    int idx = 0;
    while(k > 0)
    {
        answer++;
        k -= v[idx].first;
        idx++;
    }
    
    return answer;
}