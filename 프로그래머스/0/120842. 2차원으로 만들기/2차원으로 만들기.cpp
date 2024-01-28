#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> solution(vector<int> num_list, int n) {
    vector<vector<int>> answer;
    
    for(int i = 0; i< num_list.size(); i += n)
    {
        vector<int> tmpV;
        for(int j= i; j< i + n; j++)
        {
            tmpV.push_back(num_list[j]);
        }
        answer.push_back(tmpV);
    }
    return answer;
}