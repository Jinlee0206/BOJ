#include <bits/stdc++.h>
using namespace std;

string solution(vector<string> cards1, vector<string> cards2, vector<string> goal) {
    string answer = "";
    bool flag = true;
    
    int p1 = 0, p2 = 0;
    
    for(int i = 0; i< goal.size(); i++)
    {
        if(goal[i] == cards1[p1])
        {
            p1++;
        }
        else if (goal[i] == cards2[p2])
        {
            p2++;
        }
        else
        {
            flag = false;
            break;
        }
    }
    
    if(flag == true) answer = "Yes";
    else answer = "No";
    
    
    return answer;
}