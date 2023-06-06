#include <bits/stdc++.h>

using namespace std;

bool cmp (vector<int> &a, vector<int> &b)
{
    if(a[1] == b[1]) return a[0] < b[0];
    else return a[1] < b[1];
}

int solution(vector<vector<int>> targets) {
    int answer = 1;
   
    sort(targets.begin(), targets.end(), cmp);
    
    int from = targets[0][0];
    int to = targets[0][1];
    
    for(int i = 1; i< targets.size(); i++)
    {
        if(targets[i][0] < to) continue;
        from = targets[i][0];
        to = targets[i][1];
        answer++;
    }
    
    return answer;
}