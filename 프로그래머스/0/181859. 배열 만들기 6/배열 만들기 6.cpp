#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> answer;

    for(int i = 0; i < arr.size(); i++)
    {
        if(!answer.size()) {
            answer.push_back(arr[i]);
            continue;
        }
        else
        {
            if(answer[answer.size() - 1] == arr[i])
            {
                answer.pop_back();
            }
            else
            {
                answer.push_back(arr[i]);
            }
        }
    }
    if(!answer.size()) answer.push_back(-1);
    
    return answer;
}