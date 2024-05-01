#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr) {
    vector<vector<int>> answer = arr;
    
    int y = arr.size();
    int x = arr[0].size();
    if(y > x)
    {
        for(int i = 0; i< answer.size(); i++)
        {
            answer[i].resize(answer.size(), 0);
        }
    }
    else if(y < x)
    {
        answer.resize(answer[0].size(), vector<int>(answer[0].size(), 0));
    }
    return answer;
}