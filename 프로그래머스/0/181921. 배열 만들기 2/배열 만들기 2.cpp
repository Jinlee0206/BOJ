#include <bits/stdc++.h>

using namespace std;

vector<int> solution(int l, int r) {
    vector<int> answer;
    
    for(int i = l; i <= r; i++)
    {
        string tmp = to_string(i);
        bool isIncluded = true;
        
        for(char ch : tmp)
        {
            if(ch != '0' && ch != '5')
            {
                isIncluded = false;
                break;
            }
        }
        if(isIncluded) answer.push_back(i);
    }
    if(answer.empty()) answer.push_back(-1);
    return answer;
}