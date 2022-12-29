#include <bits/stdc++.h>

using namespace std;

int solution(string s) {
    int answer = 0;
    bool flag = true;
    int cnt = s.size();
    
    while(cnt--)
    {
        flag = true;
        stack<char> stk;
        for(int i = 0; i< s.size(); i++)
        {
            if(s[i] == '[' || s[i] == '(' || s[i] == '{') stk.push(s[i]);
            else if(!stk.empty() && s[i] == ']')
            {
                if (stk.top() == '[') stk.pop();
                else {
                    flag = false;
                    break;
                }
            }
            else if(!stk.empty() && s[i] == ')')
            {    
                if (stk.top() == '(') stk.pop();
                else{
                    flag = false;
                    break;
                }
            }
            else if(!stk.empty() && s[i] == '}')
            {
                if(stk.top() == '{') stk.pop();
                else{
                    flag =false;
                    break;
                }
            }
            else 
            {
                flag =false;
                break;
            }
        }
        
        if(flag && stk.empty()) answer++;
        rotate(s.begin(), s.begin() + 1, s.end());
    }
    return answer;
}