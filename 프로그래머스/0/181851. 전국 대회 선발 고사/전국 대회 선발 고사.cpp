#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> rank, vector<bool> attendance) {
    int answer = 0;
    vector<pair<int,int>> attended;
    
    for(int i = 0; i< rank.size(); i++) 
    {
        if(attendance[i]) attended.push_back({rank[i], i});
    }
    sort(attended.begin(), attended.end());
    answer = attended[0].second * 10000 + attended[1].second * 100 + attended[2].second;
    
    
    return answer;
}