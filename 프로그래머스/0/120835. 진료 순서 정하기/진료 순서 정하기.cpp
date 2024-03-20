#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<int> emergency) {
    vector<int> answer;
    
    int idx = 1;
    for(int i = 0; i< emergency.size(); i++)
    {
        for(int j= 0; j < emergency.size(); j++)
        {
            if(emergency[i] < emergency[j]) idx++;
        }
        answer.push_back(idx);
        idx = 1;
    }
    
    return answer;
}