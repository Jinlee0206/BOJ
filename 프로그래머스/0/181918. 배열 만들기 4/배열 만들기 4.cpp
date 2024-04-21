#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> stk;
    stack<int> s;
    for(int i = 0; i< arr.size(); )
    {
        if(s.empty())
        {
            s.push(arr[i]);
            i++;
        }
        else
        {
            if(s.top() < arr[i]) 
            {
                s.push(arr[i]);
                i++;
            }
            else
            {
                s.pop();
            }
        }
    }
    
    while(s.size())
    {
        stk.push_back(s.top());
        s.pop();
    }
    reverse(stk.begin(), stk.end());
    
    return stk;
}